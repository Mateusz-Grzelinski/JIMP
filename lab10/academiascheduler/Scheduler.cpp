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

    Schedule Schedule::OfCourse(int course) const {
        Schedule out;
        std::copy_if(schedule_.begin(), schedule_.end(), std::back_inserter(out.schedule_),
                     [course](const SchedulingItem &compare){ return compare.CourseId()==course;});
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

    NoViableSolutionFound::NoViableSolutionFound(const string &__arg) : runtime_error(__arg) {}


    Schedule GreedyScheduler::PrepareNewSchedule(const std::vector<int> &rooms,
                                                 const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                                 const std::map<int, std::set<int>> &courses_of_year,
                                                 int n_time_slots) {
        Schedule result;
        bool addedRoomTime{};
        bool Unaviable[rooms.size()][n_time_slots]{};
        std::vector <int> freeTimes;

        //ADDING TEACHERS AND COURSES
        for(auto teacher : teacher_courses_assignment) {
            for(auto course : teacher.second) {
                result.InsertScheduleItem(SchedulingItem(course,teacher.first,0,0,0));
            }
        }



        for(auto &item : result.schedule_) {
            for (auto year : courses_of_year) {
                for (auto course : year.second) {
                    if (item.CourseId() == course) item.year_ = year.first;
                }
            }
        }

        for(auto &i : result.schedule_) {
            Interscetion(n_time_slots, result, freeTimes, i, addedRoomTime);
            for(int room = 0;room<rooms.size() ; ++room){
                for(auto time : freeTimes){
                    if (!Unaviable[room][time] && !addedRoomTime){
                        SetValues(i, room, time, rooms, addedRoomTime);
                        Unaviable[room][time]=true;
                    }
                }
            }
            if (!addedRoomTime) throw NoViableSolutionFound{"error"};
        }
        return result;
    }

    void GreedyScheduler::SetValues(SchedulingItem &i, int room, int time, const std::vector<int> &rooms, bool &addedRoomTime) const {
        i.room_id_ = rooms[room];
        i.time_slot_ = time;
        addedRoomTime=true;
    }

    void GreedyScheduler::Interscetion(int n_time_slots, const Schedule &result, std::vector<int> &freeTimes,
                                       const SchedulingItem &i, bool &addedRoomTime) const {
        freeTimes.clear();
        std::vector<int> freeTimesTeacher = result.OfTeacher(i.TeacherId()).AvailableTimeSlots(n_time_slots);
        std::vector<int> freeTimesCourse = result.OfCourse(i.CourseId()).AvailableTimeSlots(n_time_slots);
        set_intersection(freeTimesTeacher.begin(), freeTimesTeacher.end(),
                         freeTimesCourse.begin(), freeTimesCourse.end(), back_inserter(freeTimes));
        addedRoomTime=false;
    }
}
