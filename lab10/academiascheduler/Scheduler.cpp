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

    Schedule GreedyScheduler::PrepareNewSchedule(const std::vector<int> &rooms,
                                                 //nauczyciel i jego kursy
                                                 const std::map<int, std::vector<int >> &teacher_courses_assignment,
                                                 //rok i wymagane kursy
                                                 const std::map<int, std::set<int>> &courses_of_year,
                                                 int n_time_slots) {
        //algorytm do bani. Złe założenie: to każdy nauczyciel ma dostać robotę, a nie każdy kurs ma dostać nauczyciela
        Schedule out;
        //zapętlam wszystkie podane roczniki
        for (const auto &yearandcourse : courses_of_year) {
            //zapętlam kursy który ma miećć każdy z roczników
            int year = yearandcourse.first;
            for (auto &singlecourse : yearandcourse.second) {
                bool throwexception=true;
                //potrzebuje nauczyciela i salę wolną o tej samej godzinie
                for (int trythishour = 1; trythishour <= n_time_slots; ++trythishour) {
                    //w kolejnych iteracjach godzin trzeba sprawdzić czy kurs już jest w planie
                    if (CourseIsArleadyInPlan(singlecourse, out))
                        throwexception=false;
                    else { //jesli kursu jeszcze w planie nie ma, przejdź do procedury
                        //znajduje wolnego nauczyciela
                        int foundTeacher = FindFreeTeacher(singlecourse, trythishour, n_time_slots,
                                                           teacher_courses_assignment, out);
                        if (foundTeacher != -1) { //czy znalazłem nauczyciela? -1 -nie znalazlem
                            //znajduje wolny pokój
                            int freeroom = FindFreeRoom(rooms, trythishour, out, n_time_slots);
                            if (freeroom != -1) { //czy mam pokój? -1 nie mam
                                out.InsertScheduleItem(
                                        SchedulingItem(singlecourse, foundTeacher, freeroom, trythishour, year));
                                throwexception = false;
                            }
                        }
                    }
                }//wypróbowałem wszytkie godziny dla kursu i czy się udało?
                if (throwexception)
                    throw NoViableSolutionFound("can\'t make schedule");
            }
        }
        //czy każdy nauczyciel ma wszystkie kursy obsadzone
        for (const auto &teacherandhiscourses : teacher_courses_assignment) {
            const int &teacher = teacherandhiscourses.first;
            const std::vector<int> &courses = teacherandhiscourses.second;
            Schedule ttt = out.OfTeacher(teacher);
            if (ttt.Size()!=courses.size())
                throw NoViableSolutionFound("");
        }
        return out;
    }

    int GreedyScheduler::FindFreeTeacher(const int course, const int &currenthour, const int &n_time_slots,
                                             const std::map<int, std::vector<int>> &map, const Schedule &out) {
        for (const auto &teacherandcourses : map) {
            int teacher = teacherandcourses.first; //mam losowegoo nauczyciela
            //sprawdzam czy nauczyciel ma odpowiedni kurs w zestawie
            const std::vector<int> &courses = teacherandcourses.second;
            bool canheteach= std::find(courses.begin(), courses.end(), course) != courses.end();
            if (canheteach) {
                //sprawdzam czy nauczyyciel jest dostępny:
                //pobieram plan nauczyciela
                Schedule teacher_plan = out.OfTeacher(teacher);
                //sprawdzam czy dana godzina już występuje
                const std::vector<int> free_hours = teacher_plan.AvailableTimeSlots(n_time_slots);
                bool teacherhasfreetime = std::find(free_hours.begin(), free_hours.end(), currenthour)!=free_hours.end();
                if (teacherhasfreetime)
                    return teacher;
            }
        }
         //nie znalazlem żadnego nauczyciela na żadną daną godzinę,
        return -1;
    }

    int GreedyScheduler::FindFreeRoom(const std::vector<int> &rooms, const int &currenthour, const Schedule &out,
                                          const int &n_time_slots) {
        for (const auto & room: rooms) {
            const Schedule singleroomschedule=out.OfRoom(room);
            const std::vector<int> free_hours=singleroomschedule.AvailableTimeSlots(n_time_slots);
            bool roomisfree=std::find(free_hours.begin(), free_hours.end(), currenthour)!=free_hours.end();
            if (roomisfree)
                return room;
        }
        return -1;
    }

    bool GreedyScheduler::CourseIsArleadyInPlan(const int &singlecourse, const Schedule &out) {
        bool isinserted;
        for (int i = 0; i < out.Size(); ++i) {
            isinserted=out[i].CourseId()==singlecourse;
            if(isinserted)
                return true;
        }
        return false;
    }

    NoViableSolutionFound::NoViableSolutionFound(const string &__arg) : runtime_error(__arg) {}
}