/*
----------------------------------------------------------------------------
               Project title   : Karen - Your Virtual Assistant
               Made By         : Inbar Maor
               Written in      : C++
               Platform        : Windows
               IDE used        : Visual Studio Code
 ----------------------------------------------------------------------------
*/


#include "Day.h"

/*---------- constructor ----------*/
Day::Day(string day)
{
    remove_old_day(day);
    this -> day = day + ".txt";
}

/*---------- remove_old_day - search for old file with the same day number - and deletes it ----------*/
void Day::remove_old_day(const string &date)
{
    size_t position = date.find('.');
    string temp{}, old_day{};
    int month{stoi(date.substr(position + 1))};
    old_day = date.substr(0, position + 1);
    for(int i = January; i <= December; i++)
    {
        if(i != month)
        {
            temp = old_day + to_string(i) + ".txt";
            if(filesystem::exists(temp))
            {
                remove(temp.c_str());
                return;
            }
        }
    }
}

/*---------- show_day - displays all tasks of the day file ----------*/
boolean Day::show_day()
{
    HANDLE text = GetStdHandle(STD_OUTPUT_HANDLE);
    string line{};
    ifstream file;
    file.open(day, ios::in);
    if(!file || std::filesystem::is_empty(day))
    {
        cout << "\nList is empty !\n\n";
        Sleep(2000);
        return false;
    }
    while(file.eof() == 0)
    {
        getline(file, line);
        if(line.find(" - V") != string::npos)
        {
            SetConsoleTextAttribute(text, Style::GREEN);
            cout << line << endl;
            SetConsoleTextAttribute(text, Style::white);
        }
        else
            cout << line << endl;
    }
    file.clear();
    file.seekg(0);
    file.close();
    return true;
}

/*---------- add_task - gets a task an add it to the day file ----------*/
void Day::add_task(string &task)
{
    fstream file;
    file.open(day, std::ios::app | std::ios::out);
    file << task << endl;
    file.close();
}

/*---------- change_day - gets action which says if the user wants to delete the task or mark it as completed. ---------- 
  ---------- Function changes the day file acorrding to action ----------*/
void Day::change_day(int action, const string &task)
{
    ofstream temp;
    ifstream file;
    string line{};
    file.open(day, ios::in);
    temp.open("temp.txt", std::ios::app | std::ios::out);
    while(file.eof() == 0)
    {
        getline(file, line);
        if(!line.empty())
        {
            if(line.find(task) == string::npos || (action == 0 && (line.find(" - V") != string::npos)))
                temp << line << endl;
            else if(action == MARK)
                temp << line << " - V" << endl;
        }
    }
    temp.close();
    file.close();
    remove(day.c_str());
    rename("temp.txt", day.c_str());
}
