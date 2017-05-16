//
// Created by mat on 16.05.17.
//

#include "Scheduler.h"
using namespace academia;

int main(){
    Schedule schedule;
    schedule.InsertScheduleItem(SchedulingItem {0, 1, 2, 3, 4});
    schedule.InsertScheduleItem(SchedulingItem {5, 6, 7, 8, 9});

    return 0;
}