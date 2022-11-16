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
#include "Assistant.h"

#define USER_NAME "Inbar"
#define USER_PASSWORD "12345"
#define PASSWORD_LENGTH 5
#define MENU_LENGTH 15
#define NUM_LINKS 15
#define LINKS_POSITION 2
#define SEARCH true

enum Menu {Voice = 1, Word, Excel, Outlook, Notepad, Gmail, Google, Google_search, Instagram, Youtube, Youtube_search, Tasks, Date, Off};
enum period {morning = 5, afternoon = 12, evening = 18, night = 21};

class Board
{
private:
    const string MENU[MENU_LENGTH] {"Back To Search", "Karen Voice", "Word", "Excel", "Outlook", "Notepad","Gmail", "Google", "Google Search",
                                    "Instagram", "Youtube", "Youtube Search", "Tasks Management", "Date & Time", "Off"};
    const string LINKS[NUM_LINKS] {"WINWORD.EXE", "EXCEL.EXE", "OUTLOOK.EXE", "Notepad", "http://gmail.com", "http://google.com","https://www.google.com/search?q=",
                                   "https://www.instagram.com/","https://www.youtube.com/","https://www.youtube.com/results?search_query="};
    Assistant Karen;
    Task_Manage tasks;

    void welcome();
    void access();
    void wrong_access();
    int menu();
    void open_link(int app, boolean search);
    void date_time();
    void exit();

public:
    void run();  
};

#endif // Board_H
