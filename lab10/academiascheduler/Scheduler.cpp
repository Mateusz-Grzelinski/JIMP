//
// Created by mat on 16.05.17.
//

#include "Scheduler.h"


namespace academia{

    Schedule Schedule::OfTeacher(int teacher_id) const {
        Schedule out;
        std::copy_if(schedule_.begin(), schedule_.end(), std::back_inserter(out.schedule_),
                     [teacher_id](const SchedulingItem &compare){ return compare.TeacherId()==teacher_id; });
        return out;

    }

    Schedule Schedule::OfRoom(int room_id) const {
        Schedule out;
        std::copy_if(schedule_.begin(), schedule_.end(), std::back_inserter(out.schedule_),
                     [room_id](const SchedulingItem &compare){ return compare.RoomId()==room_id;});
        return out;
    }

    Schedule Schedule::OfYear(int year) const {
        Schedule out;
        std::copy_if(schedule_.begin(), schedule_.end(), std::back_inserter(out.schedule_),
                     [year](const SchedulingItem &compare){ return compare.Year()==year;});
        return out;
    }

    SchedulingItem::SchedulingItem(int course_id_, int teacer_id_, int room_id_, int time_slot_, int year_)
            : course_id_(course_id_), teacer_id_(teacer_id_), room_id_(room_id_), time_slot_(time_slot_),
              year_(year_) {}

    void Schedule::InsertScheduleItem(const SchedulingItem &item) {
        schedule_.push_back(item);
    }

    std::vector<int> Schedule::AvailableTimeSlots(int n_time_slots) const {
        std::vector<int> out;
        for (int i = 1; i < n_time_slots+1; ++i) {
            if(!std::any_of(schedule_.begin(), schedule_.end(), [&i](const SchedulingItem &in_iter){ return i==in_iter.TimeSlot(); })){
                out.push_back(i);
            }
        }
        return out;

    }

    bool Schedule::CheckTime(const int &in) const {
        return std::any_of(schedule_.begin(), schedule_.end(), [&in](const SchedulingItem &in_item) { return in==in_item.TimeSlot();});
    }

    const SchedulingItem &Schedule::operator[](const int &integer) const {
        return this->schedule_[integer];
    }

    size_t Schedule::Size() const {
        return schedule_.size();
    }

    int SchedulingItem::CourseId() const {
        return course_id_;
    }

    int SchedulingItem::TeacherId() const {
        return teacer_id_;
    }

    int SchedulingItem::RoomId() const {
        return room_id_;
    }

    int SchedulingItem::TimeSlot() const {
        return time_slot_;
    }

    int SchedulingItem::Year() const {
        return year_;
    }
}