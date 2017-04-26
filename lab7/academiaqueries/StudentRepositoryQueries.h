//
// Created by mat on 18.04.17.
//

#ifndef JIMP_EXERCISES_STUDENTREPOSITORYQUERIES_H
#define JIMP_EXERCISES_STUDENTREPOSITORYQUERIES_H

#include <StudentRepository.h>
#include <string>
#include <vector>
#include <initializer_list>

namespace academia {
    // zdefiniowane w StudentRepository
//    class Query {
//    public:
//        virtual bool Accept(const Student &student) const =0;
//    };

    class ByFirstName : public Query{
    public:
        ByFirstName(std::string name):firstname_(name) {}
        bool Accept(const Student &student) const override;
    private:
        std::string firstname_;
    };

    class ByLastName : public Query{
    public:
        ByLastName(std::string name):lastname_(name) {}
        bool Accept(const Student &student) const override;
    private:
        std::string lastname_;
    };

    class ByOneOfPrograms : public Query{
    public:
        ByOneOfPrograms(std::initializer_list<std::string> prog_names):program_(prog_names) {}
        bool Accept(const Student &student) const override;
    private:
        std::vector<std::string> program_;
    };

    class ByYearLowerOrEqualTo : public Query{
    public:
        ByYearLowerOrEqualTo(StudyYear year):year_(year) {}
        bool Accept(const Student &student) const override;
    private:
        StudyYear year_;
    };

    class OrQuery : public Query{
    public:
        OrQuery(Query &&conditfirst, Query &&conditsecond): first_(conditfirst), second_(conditsecond) {};
        bool Accept(const Student &student) const override;
    private:
        Query &first_, &second_;
    };

    class AndQuery : public Query{
    public:
        AndQuery(Query &&conditfirst, Query &&conditsecond): first_(conditfirst), second_(conditsecond) {};
        bool Accept(const Student &student) const override;
    private:
        Query &first_, &second_;
    };
}
#endif //JIMP_EXERCISES_STUDENTREPOSITORYQUERIES_H
