/*
----------------------------------------------------------------------------
               Project title   : Karen - Your Virtual Assistant
               Made By         : Inbar Maor
               Written in      : C++
               Platform        : Windows
               IDE used        : Visual Studio Code
 ----------------------------------------------------------------------------
*/


#ifndef Day_H
#define Day_H

#include <filesystem>
#include <sstream>
#include <fstream>
#include "Assistant.h"

#define MARK 0
#define DELETE 1

enum Months_Range {January = 1, December = 12};

/*---------- class of the Day ----------*/
class Day
{
private:
    string day;

public:
    Day(string day);
    void remove_old_day(const string &);
    boolean show_day(Assistant *);
    void add_task(string &);
    void change_day(int, const string &);
};

#endif // Day_H
