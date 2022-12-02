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

/*---------- class of the Task Management ----------*/
class Task_Manage
{
private:
    enum Tasks_Menu //All menu options
    {
      See,
      Add,
      Delete,
      Complete,
      Return
    };
  
    const int NUM_OF_MONTHS = 12;
    const int MENU_LENGTH = 5;
    //Menu options
    const string TASKS_MENU[MENU_LENGTH] {"See My Tasks", "Add New Task", "Delete Task", "Complete My Tasks", "Go Back to Menu"};
    //How many days in each month 
    const int DAYS_IN_YEAR[NUM_OF_MONTHS] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
  
    int today;
    int month;
    vector <Day *> days; //Holds all the next month days

    void create_days();
    void update();
    int day_location_list(string &);
    void complete_task(Assistant *);
    void remove_task(Assistant *);
    void add_task();
    void see_tasks(Assistant *);
    void day_input(string &, string);

public:
    Task_Manage();
    ~Task_Manage();
    void menu(Assistant *);
};

#endif // TASK_MANAGE_H
