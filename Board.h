/*
----------------------------------------------------------------------------
               Project title   : Karen - Your Virtual Assistant
               Made By         : Inbar Maor
               Written in      : C++
               Platform        : Windows
               IDE used        : Visual Studio Code
 ----------------------------------------------------------------------------
*/


#ifndef Board_H
#define Board_H

#include <Windows.h>
#include <shellapi.h>
#include <cctype>
#include "Assistant.h"

#define USER_NAME "Inbar"
#define USER_PASSWORD "12345"
#define PASSWORD_LENGTH 5
#define MENU_LENGTH 15

enum Menu {Voice = 1, Word, Excel, Outlook, Notepad, Gmail, Google, Google_search, Instagram, Youtube, Youtube_search, Tasks, Date, Off};
enum Period {morning = 5, afternoon = 12, evening = 18, night = 21};

class Board
{
private:
    const string BOARD_MENU[MENU_LENGTH] {"back to search", "karen voice", "word", "excel", "outlook", "notepad","gmail",
          "google", "google search", "instagram", "youtube", "youtube search", "tasks management", "date and time", "off"};
    Assistant Karen;
    Task_Manage tasks;

    void welcome();
    void access();
    void wrong_access();
    int menu();
    void gmail();
    void google();
    void google_search();
    void instagram();
    void youtube();
    void youtube_search();
    void word();
    void excel();
    void outlook();
    void notepad();
    void date_time();
    void exit();

public:
    void run();  
};

#endif // Board_H
