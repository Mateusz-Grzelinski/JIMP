//
// Created by mat on 03.05.17.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H
#include <stdexcept>
#include <exception>
#include <string>
#include <memory>
#include <vector>
#include <sstream>
#include <regex>
#include <iostream>
#include "SubtitleError.h"

namespace moviesubs {
    class MovieSubtitles {
    public:
        virtual void ShiftAllSubtitlesBy(const int delay, const int fps, std::istream *in, std::ostream *out)=0;
        virtual void FindFramesAndWords(const std::string &in)=0;
        virtual void Delay(const int delay, const int fps, std::istream *in, std::ostream *out)=0;
    protected:
        unsigned long CheckIfItsNumber(const std::string &in);
        void CheckIfIsMatched(const std::smatch &match);
        std::vector<long> frames_;
        std::vector<std::string> words_;
        void CheckFrameRate(const int fps);
        std::string &getLine(std::istream *in, std::string &tmpstring) const;
    private:
    };

//-------MicroDvdSubtitles-------
        class MicroDvdSubtitles : public MovieSubtitles {
        public:
            void ShiftAllSubtitlesBy(const int delay, const int fps, std::istream *in, std::ostream *out) override;

            MicroDvdSubtitles()= default;
            void FindFramesAndWords(const std::string &in) override;
            void Delay(const int delay, const int fps, std::istream *in, std::ostream *out) override;
        private:
            void CheckIfFrameWillBeNegative(const long &delayinframes);
            void CheckFrameOrder();

        };

//-------SubRipSubtitles-------
    class SubRipSubtitles: public MovieSubtitles{
    public:
        void ShiftAllSubtitlesBy(const int delay, const int fps, std::istream *in, std::ostream *out) override;

        void FindFramesAndWords(const std::string &in) override;
        void Delay(const int delay, const int fps, std::istream *in, std::ostream *out) override;
    private:
        void CheckFrameOrder();
        long ConvetrToMiliseconds(std::smatch results, int whichset);
        std::string ConvertToFormatedOutput(long &in);

        std::string GetSegment(std::istream *in, std::string result, int &iterator);
    };
}


#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
