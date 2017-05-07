//
// Created by mat on 03.05.17.
//

#include "MovieSubtitles.h"
#include "SubtitleError.h"

namespace moviesubs {
//-------MicroDvdSubtitles-------
    void MovieSubtitles::ShiftAllSubtitlesBy(const int delay, const int fps, std::istream *in, std::ostream *out) {
        std::string tmpstring;
        CheckFrameRate(fps);
        do {
            tmpstring = getLine(in, tmpstring);
            FindFramesAndWords(tmpstring);
            tmpstring.clear();
        } while (in->peek() != -1);
        Delay(delay, fps, in, out);
    }

    std::string &MovieSubtitles::getLine(std::istream *in, std::string &tmpstring) const {
        (*in) >> std::ws;
        while (in->peek() != '\n' && in->peek() != -1) {
                std::__cxx11::string tmp;
                (*in) >> tmp;
                tmpstring += ' ' + tmp;
            }
        (*in) >> std::ws;
        return tmpstring;
    }

    void MovieSubtitles::CheckIfIsMatched(const std::smatch &match) {
        for (const auto &item : match) {
            if(!item.matched) {
                frames_.clear();
                words_.clear();
                throw InvalidSubtitleLineFormat();
            }
        }
    }
    unsigned long MovieSubtitles::CheckIfItsNumber(const std::string &in) {
        unsigned long number = 0;
        if (in == "") throw InvalidSubtitleLineFormat();
        else {
            unsigned long weight = 1;
            for (int i = 0; i < in.size() - 1; ++i) {
                weight *= 10;
            }
            for (auto iter: in) {
                if ((int) iter >= (int) '0' && (int) iter <= (int) '9')
                    number += ((int) iter - (int) '0') * weight;
                else throw InvalidSubtitleLineFormat();
                weight /= 10;
            }
        }
        return number;
    }
    void MovieSubtitles::CheckFrameRate(const int fps) {
        if(fps<0) throw std::invalid_argument("Negative frame rate");
    }

//-------MicroDvdSubtitles-------
    void MicroDvdSubtitles::FindFramesAndWords(const std::string &in) {
        std::regex formula{R"(\s*\{([^\{\}]+)?\}\{([^\{\}]+)?\}(\{?.*\}?.*))"};
        std::smatch match;
        std::regex_match(in, match, formula);
        CheckIfIsMatched(match);
        for (int j = 1; j < match.size() - 1; ++j) {
            frames_.push_back(CheckIfItsNumber(match[j]));
        }
        std::string wordstmp= match[match.size() - 1].str();
        words_.push_back( wordstmp );


    }
    void MicroDvdSubtitles::Delay(const int delay, const int fps, std::istream *in, std::ostream *out) {
        long delayinframes = delay / (1000 / fps);
        CheckFrameOrder();
        CheckIfFrameWillBeNegative(delayinframes);

        for (int i = 0, j = 0; i + 1 < frames_.size(); i += 2, ++j) {
            if (frames_[i] > frames_[i+ 1]) {
                const std::string message =
                        "{"+std::to_string(frames_[i])+"}" + "{"+std::to_string(frames_[i + 1]) +"}"+ words_[j];
                throw SubtitleEndBeforeStart(2, message);
            }
            *out << "{" << std::to_string(frames_[i]) << "}";
            *out << "{" << std::to_string(frames_[i + 1]) << "}";
            *out << words_[j] << "\n";
        }
    }
    void MicroDvdSubtitles::CheckFrameOrder(){
        for (int i = 0, j = 0; i + 1 < frames_.size(); i += 2, ++j) {
            if (frames_[i] > frames_[i + 1]) {
                const std::string message =
                        "{" + std::to_string(frames_[i]) + "}" + "{" + std::to_string(frames_[i + 1]) + "}" + words_[j];
                throw SubtitleEndBeforeStart(2, message);
            }
        }
    }
    void MicroDvdSubtitles::CheckIfFrameWillBeNegative(const long &delayinframes) {
        for (auto &frame : frames_) {
            if (frame + delayinframes < 0)
                throw NegativeFrameAfterShift();
            frame += delayinframes;
        }
    }

//-------SubRipSubtitles-------
    void SubRipSubtitles::FindFramesAndWords(const std::string &in) {
        std::regex formula{R"(\s*(.+):(.+):(.+),(.+)\s*-->\s*(.+):(.+):(.+),(.+)([.\s]+))"};
        std::smatch match;
        std::regex_match(in, match, formula);
//        CheckIfIsMatched(match);
//        for (int j = 1; j < match.size() - 1; ++j) {
//            CheckIfItsNumber(match[j]));
//        }
        for (int j = 1; j < 5; j+=4) {
            frames_.push_back(ConvetrToMiliseconds(match, j));
        }

    }

    void SubRipSubtitles::Delay(const int delay, const int fps, std::istream *in, std::ostream *out) {
        long delayinframes = delay / (1000 / fps);
        CheckFrameOrder();
//        CheckIfF1rameWillBeNegative(delayinframes);

        for (int i = 0, j = 0; i + 1 < frames_.size(); i += 2, ++j) {
            *out << ConvertToFormatedOutput(frames_[i]) << " --> " << ConvertToFormatedOutput(frames_[i+1]);
            *out << words_[i];
        }
    }

    long SubRipSubtitles::ConvetrToMiliseconds(std::smatch results, int whichset) {
        long timeinmiliseconds=0;;
        //petla dodaje wszystkie godziny i minuty i sekundy
        for (long i = whichset, time=3600000;
             i < whichset+4;
             ++i, time/60) { //hh:mm:ss,___
            timeinmiliseconds+=CheckIfItsNumber(results[i].str())*time;
        }
        //dodaje pozostale milisekundy
        timeinmiliseconds+=CheckIfItsNumber(results[whichset+4].str());
        return timeinmiliseconds;
    }

    std::string SubRipSubtitles::ConvertToFormatedOutput(long &in) {
        long tmph=in/60;
        long tmpm=(in-tmph)/60;
        long tmps=(in-tmph-tmpm)/60;
        long tmpmilsec=(in-tmph-tmpm-tmps);
        tmph/=1000; tmpm/=1000; tmps/=1000;
        std::string result;
        result.append(std::to_string(tmph)+":");
        result.append(std::to_string(tmpm)+":");
        result.append(std::to_string(tmps)+",");
        result.append(std::to_string(tmpmilsec));
        return result;        
    }
    void SubRipSubtitles::CheckFrameOrder() {
        for (int i = 0, j = 0; i + 1 < frames_.size(); i += 2, ++j) {
            if (frames_[i] > frames_[i + 1]) {
                const std::string message =
                        "{" + std::to_string(frames_[i]) + "}" + "{" + std::to_string(frames_[i + 1]) + "}" + words_[j];
                throw SubtitleEndBeforeStart(2, message);
            }
        }
    }


}
