//
// Created by mat on 03.05.17.
//

#ifndef JIMP_EXERCISES_SUBTITLEERROR_H
#define JIMP_EXERCISES_SUBTITLEERROR_H

#include <stdexcept>
#include <exception>

namespace moviesubs {
    class SubtitleError : public std::runtime_error {
    protected:
        SubtitleError(const std::string &message = "Something, somewhere went terribly wrong #UNDEFINDED")
                : runtime_error(message) {}
    };

    class NegativeFrameAfterShift : public SubtitleError {
    public:
        NegativeFrameAfterShift() : SubtitleError("Negative frame after shift") {}
    };

    class OutOfOrderFrames : public SubtitleError {
    public:
        OutOfOrderFrames() : SubtitleError("Invalid frames values") {}
    };

    class MissingTimeSpecification : public SubtitleError {
    public:
        MissingTimeSpecification() : SubtitleError("Invalid/missing time") {}
    };

    class InvalidSubtitleLineFormat : public SubtitleError {
    public:
        InvalidSubtitleLineFormat() : SubtitleError("Invalid format of subtitle line") {}
    };

    class SubtitleEndBeforeStart : public SubtitleError {
    public:
        SubtitleEndBeforeStart(int line, std::string message) : line_(line), SubtitleError(
                "At line " + std::to_string(line) + ": " + message) {}

        int LineAt() const { return line_; }
    private:
        int line_;
    };

}
#endif //JIMP_EXERCISES_SUBTITLEERROR_H
