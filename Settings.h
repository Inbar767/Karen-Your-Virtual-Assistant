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

/*---------- Settings_Functions - settings functions and variables for all classes ----------*/
namespace Settings
{
    const char ENTER{'\r'};
    const string BACK_KEY{"\b \b"};
    const int DELETE_KEY{8};
    const int KEY_UP{72};
    const int KEY_DOWN{80};
    const int KEY_LEFT{75};
    const int KEY_RIGHT{77};

    void create_search_link(string &, string &);
    int insert_valid_choice(const string &, int, int);
    void convert_to_lower(string &);
    boolean is_number(const string &);
};

/*---------- Style - style of project ----------*/
namespace Style
{
    const string HEADLINE_BORDER{"----------------------------------"};
    const string HEADLINE_SPACE{"\n\n"};
    const string BORDER{"***********************************************"};
    const string MIDDLE{"\t\t\t"};
    const int RED{4};
    const int GREEN{10};
    const int white{7};

    void headline(string, boolean);
};

/*---------- Time - gets current time and date ----------*/
namespace Time
{
    time_t TIME{time(NULL)};
    tm *LOCAL_TIME{localtime(&TIME)};

    int current_hour();
    int current_month();
    int current_day();
    string get_date();
};

#endif // Settings_H
