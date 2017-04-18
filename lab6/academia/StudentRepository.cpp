//
// Created by mat on 05.04.17.
//

#include "StudentRepository.h"

namespace academia {
    StudentRepository::StudentRepository(initializer_list<Student> in) {
        studentcontainer_.assign(in);
    }
    void StudentRepository::AddStudent(Student &in) {
        studentcontainer_.push_back(in);
    }
    void StudentRepository::RemoveStudent(std::string outbyid) {
        bool flag = true;
        int i=0;
        while  ( i < studentcontainer_.size() && flag) {
            if (studentcontainer_[i].Id()==outbyid)
                flag=false;
            i++;
        }
        if (!flag)
            studentcontainer_.erase(studentcontainer_.begin()+i);
    }
    void StudentRepository::RemoveStudent(Student out) {
        std::string outbyid=out.Id();
        this->RemoveStudent(outbyid);
    }
    int StudentRepository::StudentCount() {
        return studentcontainer_.size();
    }

    std::vector<Student> StudentRepository::FindByQuery(const Query &query) {
        std::vector<Student> result;
        for (auto &&item : studentcontainer_) {
            if (query.Accept(item))
                result.push_back(item);
        }
        return result;
    }
    Student &StudentRepository::operator[]( const std::string &searchforid) {
        bool flag = true;
        int i=0;
        while  ( i < studentcontainer_.size() && flag) {
            if (studentcontainer_[i].Id()==searchforid) {
                flag = false;
                return studentcontainer_[i];
            }
            i++;
        }
        return studentcontainer_[i];

    }

    bool operator==(StudentRepository &firstrep, StudentRepository &secondrep){
        bool thesame=true;
        if(firstrep.StudentCount()!=secondrep.StudentCount())
            thesame=false;
        for(int i=0; i< firstrep.StudentCount() && thesame; ++i){
            if ( !(firstrep.studentcontainer_[i]==secondrep.studentcontainer_[i]))
                thesame=false;
        }
        return thesame;
    }
    std::ostream &operator<<(std::ostream &os, StudentRepository stdrep){
        for(int i=0; i<stdrep.StudentCount(); ++i) {
            os << stdrep;
            os << std::endl;
        }
    }

}