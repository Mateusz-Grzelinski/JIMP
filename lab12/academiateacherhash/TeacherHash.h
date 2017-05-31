//
// Created by mat on 31.05.17.
//

#ifndef JIMP_EXERCISES_AACADEMIATEACHERHASH_H
#define JIMP_EXERCISES_AACADEMIATEACHERHASH_H

#include <string>
#include <utility>

namespace academia {
    class TeacherId{
    public:
        TeacherId(const int &id):id_(id){}
        TeacherId(const TeacherId &teacher):id_(teacher.id_){}
        operator int() const {return id_;};
        bool operator!=(const TeacherId &teacher) const{return teacher.id_!=id_;};
    private:
        size_t id_;
    };


    class Teacher {
    public:
        Teacher(const TeacherId &id, const std::string &name, const std::string &work):id_(id),name_(name),work_(work){}
        bool operator==(const Teacher &teacher) const {return (id_==teacher.id_
                                                               && name_==teacher.name_
                                                               && work_==teacher.work_);}
        bool operator!=(const Teacher &teacher) const {return !(*this==teacher); }

        const int Id() const{ return id_;}
        const std::string Name() const{ return name_;}
        const std::string Work() const{return work_;}

    private:
        TeacherId id_;
        std::string name_, work_;

    };


    class TeacherHash{
    public:
        size_t operator()(const Teacher& in) const {
            size_t name_result=0, work_result=0;
            for (auto &character : in.Name()) {
                name_result+=character;
            }
            for (auto &character :in.Work()) {
                work_result+=character;

            }
            return in.Id() ^ work_result ^ name_result;
        }

    };


}
#endif //JIMP_EXERCISES_AACADEMIATEACHERHASH_H
