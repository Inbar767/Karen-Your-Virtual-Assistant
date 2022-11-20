/*
----------------------------------------------------------------------------
               Project title   : Karen - Your Virtual Assistant
               Made By         : Inbar Maor
               Written in      : C++
               Platform        : Windows
               IDE used        : Visual Studio Code
 ----------------------------------------------------------------------------
*/

#include "Settings.h"

namespace Settings
{
    /*---------- create_link - gets string of the beginning of link, and the keyword user wants to search ----------
      ---------- Convert the search string and creates a valid link ----------*/
    void create_search_link(string &link, string &search)
    {
        stringstream hex;
        for (int i{}; i < search.size(); i++)
        {
            if ((search[i] >= 'A' && search[i] <= 'Z') || (search[i] >= 'a' && search[i] <= 'z') ||
                (search[i] >= '0' && search[i] <= '9'))
                hex << search[i];
            else
            {
                if (isspace(search[i]))
                    hex << '+';
                else
                    hex << '%' << std::hex << (int)search[i];
            }
        }
        link += hex.str();
    }

    /*---------- insert_valid_choice - gets phrase to ask user for input, and integer limit. ----------
      ---------- Prints the phrase and gets from the user input, if it is not real number ----------
      ---------- or not in limit - return -1, else - return choice ----------*/
    int insert_valid_choice(const string &phrase, int limit)
    {
        string choice{};
        int number{};
        cout << phrase;
        getline(cin >> ws, choice);
        choice.erase(remove_if(choice.begin(), choice.end(), ::isspace), choice.end());
        if (!is_number(choice) || (number = stoi(choice)) < 0 || number > limit)
            return -1;
        return number;
    }

    /*---------- convert_to_lower - gets a text string and converts it into a lower case string ----------*/
    void convert_to_lower(string &text)
    {
        transform(text.begin(), text.end(), text.begin(), [](unsigned char c)
                  { return tolower(c); });
    }

    /*---------- is_number - gets number and checks if is real number ----------*/
    boolean is_number(const string &number)
    {
        return all_of(number.begin(), number.end(), ::isdigit);
    }

};

namespace Style
{
    /*---------- headline - gets a phrase to print as a headline and ----------
      ---------- boolean variable named space : true - if headline needs space between chars, false - if not. ----------
      ---------- The function creates headline with phrase and prints it. ----------*/
    void headline(string phrase, boolean space)
    {
        cout << MIDDLE << HEADLINE_BORDER << " ";
        for (char c : phrase)
        {
            if (isspace(c))
                cout << "-";
            else
                cout << c;
            if (space)
                cout << " ";
        }
        if (!space)
            cout << " ";
        cout << HEADLINE_BORDER << " " << HEADLINE_SPACE;
    }

    void wrong(string phrase)
    {
        HANDLE text = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(text, RED);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xFC);
        cout << phrase;
        SetConsoleTextAttribute(text, white);
    }

};

namespace Time
{
    /*---------- current_month - returns current hour. ----------*/
    int current_hour()
    {
        time_t current_time{time(NULL)};
        tm *local{localtime(&current_time)};
        return local->tm_hour;
    }

    /*---------- current_month - returns current month. ----------*/
    int current_month()
    {
        time_t current_time{time(NULL)};
        tm *local{localtime(&current_time)};
        return 1 + local->tm_mon;
    }

    /*---------- current_day - returns current day. ----------*/
    int current_day()
    {
        return LOCAL_TIME->tm_mday;
    }

    /*---------- get_date - returns current date and hour. ----------*/
    string get_date()
    {
        time_t current_time{time(NULL)};
        return ctime(&current_time);
    }
};
