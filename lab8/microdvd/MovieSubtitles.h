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

namespace moviesubs {
    class MovieSubtitles {
    public:
        MovieSubtitles()=default;
        void ShiftAllSubtitlesBy(const int delay, const int fps, std::istream *in, std::ostream *out);
        virtual void FindFrames(const std::string &in)=0;
        virtual void FindWords(const std::string &in)=0;
        virtual void Delay(const int delay, const int fps, std::istream *in, std::ostream *out)=0;

        };

//-------MicroDvdSubtitles-------
        class MicroDvdSubtitles : public MovieSubtitles {
        public:
            MicroDvdSubtitles()= default;
            void FindFrames(const std::string &in) override;
            void Delay(const int delay, const int fps, std::istream *in, std::ostream *out) override;

            void FindWords(const std::string &in) override;

        private:
            unsigned long CheckIfItsNumber(const std::string &in);
            std::vector<unsigned long> frames_;
            std::vector<std::string> words_;
        };


}


#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
