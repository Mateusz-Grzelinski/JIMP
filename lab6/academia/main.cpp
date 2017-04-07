//
// Created by mat on 04.04.17.
//

#include <Student.h>
#include"StudentRepository.h"
using namespace academia;
using namespace std;


int main(){
    StudentRepository rep{};
    Student jeden, dwa;
    jeden.ChangeLastName("Nowak");
    cout<<jeden;
}