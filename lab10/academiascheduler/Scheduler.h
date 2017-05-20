//
// Created by mat on 16.05.17.
//

#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H
#include <StudentRepository.h>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <error.h>

namespace academia {
    class SchedulingItem;

    class Schedule{
    public:
        Schedule OfTeacher(int teacher_id) const;
        Schedule OfRoom(int room_id) const;
        Schedule OfYear(int year) const;
        Schedule OfCourse(int course) const;
        void InsertScheduleItem(const SchedulingItem &item);
        size_t Size() const;
        std::vector<int> AvailableTimeSlots(int n_time_slots) const;
        const SchedulingItem &operator[](const int &integer) const ;
//    private:
        std::vector<SchedulingItem> schedule_;

    };

    class SchedulingItem{
    public:
        SchedulingItem(int course_id_, int teacer_id_, int room_id_, int time_slot_, int year_);
        int CourseId() const;
        int TeacherId() const;
        int RoomId() const;
        int TimeSlot() const;
        int Year() const;

//    protected:
        int course_id_;
        int teacer_id_;
        int room_id_;
        int time_slot_;
        int year_;
    };

    class Scheduler {
    public:
        virtual Schedule PrepareNewSchedule(const std::vector<int> &rooms,
                                    const std::map<int, std::vector<int >> &teacher_courses_assignment,
                                    const std::map<int, std::set<int>> &courses_of_year, int n_time_slots)=0;
    };

    class GreedyScheduler:public Scheduler{
    public:
        Schedule PrepareNewSchedule(const std::vector<int> &rooms,
                                    const std::map<int, std::vector<int >> &teacher_courses_assignment,
                                    const std::map<int, std::set<int>> &courses_of_year, int n_time_slots) override;


    private:
        void Interscetion(int n_time_slots, const Schedule &result, std::vector<int> &freeTimes, const SchedulingItem &i,
                      bool &addedRoomTime) const;

        void SetValues(SchedulingItem &i, int room, int time, const std::vector<int> &rooms, bool &addedRoomTime) const;
    };

    class NoViableSolutionFound : public std::runtime_error{
    public:
        NoViableSolutionFound(const string &__arg);

    };

}
#endif //JIMP_EXERCISES_SCHEDULER_H
