//
// Created by mat on 03.05.17.
//

#include "MovieSubtitles.h"

namespace moviesubs {
    void MovieSubtitles::ShiftAllSubtitlesBy(const int delay, const int fps, std::istream *in, std::ostream *out) {
        std::string tmpstring;
        do {
            (*in) >> std::ws;
            while(in->peek()!='\n' && in->peek() != -1) {
                std::string tmp;
                (*in) >> tmp;
                tmpstring+=' '+tmp;
            }
            (*in) >> std::ws;
            FindFrames(tmpstring);
            FindWords(tmpstring);
            tmpstring.clear();
        } while (in->peek() != -1);
        Delay(delay, fps, in, out);
    }


//-------MicroDvdSubtitles-------
    void MicroDvdSubtitles::FindFrames(const std::string &in) {
        std::regex formula{R"(\s*\{([^\{\}]+)?\}\{([^\{\}]+)?\}\{?.*\}?(.*))"};
        std::smatch match;
        std::regex_match(in, match, formula);
        for (int j = 1; j < match.size()-1; ++j) {
//            std::cout << match[j] << std::endl;
            frames_.push_back(CheckIfItsNumber(match[j]));
        }
    }

    unsigned long MicroDvdSubtitles::CheckIfItsNumber(const std::string &in) {
        unsigned long number = 0;
        if (in == "")
            std::cout << "bu"; // throw InvalidSubtitleLineFormat();
        else {
            unsigned long weight = 1;
            for (int i = 0; i < in.size()-1; ++i) {
                weight*=10;
            }
            for (auto iter: in ) {
                if ((int) iter >= (int) '0' && (int) iter <= (int) '9')
                    number += ((int) iter - (int) '0') * weight;
                weight /= 10;
            }
        }
        return number;
    }

    void MicroDvdSubtitles::FindWords(const std::string &in) {
        std::regex formula{R"(\s*\{[^\{\}]+\}\{[^\{\}]+\}(\{?.*\}?.*))"};
        std::smatch match;
        std::regex_match(in, match, formula);
        words_.push_back(match[1].str());
//        std::cout<<match[2].str();
    }

    void MicroDvdSubtitles::Delay(const int delay, const int fps, std::istream *in, std::ostream *out) {
        int delayinframes=(int) (delay/(1000/fps));
        for (auto &&frame : frames_) {
            frame+=delayinframes;
        }
        for(int i=0, j=0; i+1<frames_.size(); i+=2, ++j) {
            *out << "{" << std::to_string(frames_[i]) << "}";
            *out << "{" << std::to_string(frames_[i+1]) << "}";
            *out<<words_[j]<<"\n";
        }


    }


}
