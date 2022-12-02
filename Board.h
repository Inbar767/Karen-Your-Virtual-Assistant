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

class Board
{
private:
    enum Menu //All menu options
    {
      Back,
      Voice,
      Word,
      Excel,
      Outlook,
      Notepad,
      Gmail,
      Google,
      Google_search,
      Instagram,
      Youtube,
      Youtube_search,
      Tasks,
      Date,
      Off
   };
   enum period //Time period
   {
      morning = 5,
      afternoon = 12,
      evening = 18,
      night = 21
    };
  
    const string USERNAME = "Inbar"
    const string USER_PASSWORD = "12345"
    const int PASSWORD_LENGTH = 5
    const int MENU_LENGTH = 15
    const int NUM_LINKS = 15
    const int LINKS_POSITION = 2
    const boolean SEARCH = true
    //Menu options
    const string MENU[MENU_LENGTH]{"Back To Search", "Karen Voice", "Word", "Excel", "Outlook", "Notepad", "Gmail",
                                   "Google", "Google Search", "Instagram", "Youtube", "Youtube Search", "Tasks Management", "Date & Time", "Off"};
  //Applications and sites links  
  const string LINKS[NUM_LINKS]{"WINWORD.EXE", "EXCEL.EXE", "OUTLOOK.EXE", "Notepad", "http://gmail.com", "http://google.com",
                                  "https://www.google.com/search?q=", "https://www.instagram.com/", "https://www.youtube.com/", "https://www.youtube.com/results?search_query="};
    
    Assistant *Karen;
    Task_Manage tasks;

    void welcome();
    void access();
    void wrong_access();
    int menu();
    void open_link(int, boolean);
    void date_time();
    void exit();

public:
    Board();
    ~Board();
    void run();
};

#endif // Board_H
