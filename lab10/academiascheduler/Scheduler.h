//
// Created by mat on 16.05.17.
//

#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H
#include <StudentRepository.h>
#include <algorithm>
namespace academia {
    class SchedulingItem;
    class Scheduler {

    };
    class Schedule{
    public:
        Schedule OfTeacher(int teacher_id) const;
        Schedule OfRoom(int room_id) const;
        Schedule OfYear(int year) const;
        void InsertScheduleItem(const SchedulingItem &item);
        size_t Size() const;
        std::vector<int> AvailableTimeSlots(int n_time_slots) const;
        const SchedulingItem &operator[](const int &integer) const ;
        bool CheckTime(const int &in) const;
    private:
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

    private:
        int course_id_;
        int teacer_id_;
        int room_id_;
        int time_slot_;
        int year_;
    };

}
#endif //JIMP_EXERCISES_SCHEDULER_H
