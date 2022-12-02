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


/*---------- class of the Day ----------*/
class Day
{
private:
    enum Months_Range //First and last months of the year
    {
      January = 1,
      December = 12
    };
  
    const int MARK = 0; //Used to tell if task must be marked
    const int DELETE = 1; //Used to tell if task must be deleted
  
    string day;

public:
    Day(string day);
    void remove_old_day(const string &);
    boolean show_day(Assistant *);
    void add_task(string &);
    void change_day(int, const string &);
};

#endif // Day_H
