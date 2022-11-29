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
#include "Day.cpp"
#include "Day.h"

#define NUM_MONTHS 12
#define MENU_OPTIONS 5

enum Tasks_Menu {See, Add, Delete, Complete, Return};

/*---------- class of the Task Management ----------*/
class Task_Manage
{
private:
    const string TASKS_MENU[MENU_OPTIONS]{"See My Tasks", "Add New Task", "Delete Task", "Complete My Tasks", "Go Back to Menu"};
    const int NUM_DAYS[NUM_MONTHS]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // Number of days in every month
    int today;
    int month;
    vector <Day *> days;

    void create_days();
    void update();
    int day_location_list(string &);
    void complete_task(Assistant *Karen);
    void remove_task(Assistant *Karen);
    void add_task();
    void see_tasks(Assistant *);
    void day_input(string &, string);

public:
    Task_Manage();
    ~Task_Manage();
    void menu(Assistant*);
};

#endif // TASK_MANAGE_H