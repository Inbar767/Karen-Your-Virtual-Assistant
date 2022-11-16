/*
----------------------------------------------------------------------------
               Project title   : Karen - Your Virtual Assistant
               Made By         : Inbar Maor
               Written in      : C++
               Platform        : Windows
               IDE used        : Visual Studio Code
 ----------------------------------------------------------------------------
*/

#ifndef Task_Manage_H
#define Task_Manage_H

#include <vector>
#include "Day.h"

#define NUM_MONTHS 12
#define MENU_OPTIONS 5

enum Tasks_Menu {See = 0, Add = 1, Delete = 2, Return = 4};

/*---------- class of the Task Management ----------*/
class Task_Manage
{
private:
    const string TASKS_MENU[MENU_OPTIONS]{"See My Tasks", "Add New Task", "Delete Task", "Complete My Tasks", "Back to Menu"};
    const int NUM_DAYS[NUM_MONTHS]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // Number of days in every month
    int today;
    int month;
    vector <Day *> days;

    void create_days();
    void update();
    int day_location_list(string &);
    void complete_task();
    void remove_task();
    void add_task();
    void see_tasks();
    void day_input(string &, string);

public:
    Task_Manage();
    void menu();
};

#endif // TASK_MANAGE_H
