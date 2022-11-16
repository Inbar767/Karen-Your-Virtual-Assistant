/*
----------------------------------------------------------------------------
               Project title   : Karen - Your Virtual Assistant
               Made By         : Inbar Maor
               Written in      : C++
               Platform        : Windows
               IDE used        : Visual Studio Code
 ----------------------------------------------------------------------------
*/

#ifndef Settings_H
#define Settings_H

#include <time.h>
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

/*---------- Settings_Functions - functions and variables for all classes ----------*/
namespace Settings_Functions
{
    const char ENTER{'\r'};
    const string BACK_KEY{"\b \b"};
    const int DELETE_KEY{8};

    void create_link(string &, string &);
    int insert_valid_choice(const string &, int, int);
    void convert_to_lower(string &);
    boolean is_number(const string &);

};

/*---------- Style - input style ----------*/
namespace Style
{
    const string HEADLINE_BORDER{"----------------------------------"};
    const string HEADLINE_SPACE{"\n\n"};
    const string BORDER{"***********************************************"};
    const string MIDDLE{"\t\t\t"};
    const int RED {4};
    const int GREEN {10};
    const int white {7};

    void headline(string, boolean);
};

/*---------- Time - gets current time and date ----------*/
namespace Time
{
    const time_t TIME{time(NULL)};
    const tm *LOCAL_TIME{localtime(&TIME)};

    int current_hour();
    int current_month();
    int current_day();
    string get_date();
};

#endif // Settings_H