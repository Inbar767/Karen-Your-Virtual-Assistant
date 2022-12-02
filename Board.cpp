/*
----------------------------------------------------------------------------
               Project title   : Karen - Your Virtual Assistant
               Made By         : Inbar Maor
               Written in      : C++
               Platform        : Windows
               IDE used        : Visual Studio Code
 ----------------------------------------------------------------------------
*/

#include "Board.h"
#include <Windows.h>
#include <shellapi.h>
#include "Task_Manage.h"


/*---------- Constructor ----------*/
Board::Board()
{
    Karen = new Assistant();
}

/*---------- run - runs the project ----------*/
void Board::run()
{
    int choice{};
    welcome();
    do
    {
        choice = menu();
        switch (choice)
        {
        case Off:
        case Back:
            break;
        case Voice:
            Karen->voice_manage();
            break;
        case Word:
            open_link(Word - LINKS_POSITION, !SEARCH);
            break;
        case Excel:
            open_link(Excel - LINKS_POSITION, !SEARCH);
            break;
        case Outlook:
            open_link(Outlook - LINKS_POSITION, !SEARCH);
            break;
        case Notepad:
            open_link(Notepad - LINKS_POSITION, !SEARCH);
            break;
        case Gmail:
            open_link(Gmail - LINKS_POSITION, !SEARCH);
            break;
        case Google:
            open_link(Google - LINKS_POSITION, !SEARCH);
            break;
        case Google_search:
            open_link(Google_search - LINKS_POSITION, SEARCH);
            break;
        case Instagram:
            open_link(Instagram - LINKS_POSITION, !SEARCH);
            break;
        case Youtube:
            open_link(Youtube - LINKS_POSITION, !SEARCH);
            break;
        case Youtube_search:
            open_link(Youtube_search - LINKS_POSITION, SEARCH);
            break;
        case Tasks:
            system("CLS");
            Karen->speak("Opening task Management");
            tasks.menu(Karen);
            break;
        case Date:
            date_time();
            break;
        default:
            cout << Style::HEADLINE_SPACE;
            Style::wrong("Invalid choice !");
            Karen->dont_understand();
            break;
        }
    } while (choice != Off);
    exit();
}

/*---------- welcome - greets the user ----------*/
void Board::welcome()
{
    system("CLS");
    cout << Style::HEADLINE_SPACE << Style::MIDDLE;
    cout << "----------------------------------\3 W E L C O M E \3----------------------------------";
    cout << Style::HEADLINE_SPACE << Style::MIDDLE << Style::MIDDLE;
    cout << "  I'M KAREN YOUR VIRTUAL ASSISTANT";
    Karen->speak("welcome my name is karen and I am your virtual assistant please enter user name and password");
    access();
    system("CLS");
    cout << Style::HEADLINE_SPACE << Style::MIDDLE;
    cout << "------------------------- W E L C O M E  \3  I N B A R ------------------------";
    Karen->speak("Welcome Inbar");
}

/*---------- access - gets user name and password from the user and checks if correct ----------*/
void Board::access()
{
    string password, username;
    int c, i;
    boolean sw_continue = true;
    while (sw_continue)
    {
        i = 0;
        username.clear();
        password.clear();
        system("CLS");
        cout << Style::HEADLINE_SPACE << Style::MIDDLE << Style::HEADLINE_BORDER << "\n";
        cout << Style::MIDDLE << "Please enter your user name : ";
        getline(cin >> ws, username);
        cout << Style::MIDDLE << Style::HEADLINE_BORDER << "\n";
        cout << Style::MIDDLE << "Please enter your password : ";
        while (c = getch())
        {
            if (i < PASSWORD_LENGTH && isgraph(c) && c != Settings::KEY_UP && c != Settings::KEY_DOWN && c != Settings::KEY_LEFT && c != Settings::KEY_RIGHT)
            {
                cout << "x";
                password += c;
                i++;
            }
            else if (c == Settings::ENTER && i == PASSWORD_LENGTH)
                break;
            else if (c == Settings::DELETE_KEY && i > 0)
            {
                cout << Settings::BACK_KEY;
                password.erase(password.length() - 1);
                i--;
            }
        }
        if (username != USERNAME || password != USER_PASSWORD)
        {
            cout << Style::HEADLINE_SPACE << Style::MIDDLE;
            Style::wrong("USERNAME OR PASSWORD IS INCORRECT ! PLEASE TRY AGAIN");
            Karen->speak("please try again");
        }
        else
            sw_continue = false;
    }
}

/*---------- search - gets from the user his search ----------*/
int Board::menu()
{
    int choice{};
    string search{}, lower_case_option{MENU[Off]};
    boolean all{};
    Settings::convert_to_lower(lower_case_option);
    system("CLS");
    Style::headline("MENU", true);
    cout << Style::MIDDLE << "\4 \4 All - Check all options   \4 \4\n ";
    cout << Style::MIDDLE << "\4 \4 Off - Shut down assistant \4 \4\n";
    cout << Style::HEADLINE_SPACE << "Please type what you are looking for boss : ";
    getline(cin >> ws, search);
    Settings::convert_to_lower(search);
    if (search == lower_case_option)
        return Off;
    if (search == "all")
        all = true;
    cout << endl;
    Style::headline("OPTIONS", false);
    for (int i = 0; i < MENU_LENGTH; i++)
    {
        lower_case_option = MENU[i];
        Settings::convert_to_lower(lower_case_option);
        if (all || lower_case_option.find(search) != string::npos || i == Off || i == 0)
        {
            cout << i;
            if (i < 10)
                cout << " ";
            cout << " - " << MENU[i] << endl;
        }
    }
    choice = Settings::insert_valid_choice("\nPlease enter your choice: ", MENU_LENGTH - 1);
    return choice;
}

/*---------- open_link - gets an app number and a boolean search variable which says if user want to search on internt ----------
  ---------- and open it for the user  ----------*/
void Board::open_link(int app, boolean search)
{
    string link{LINKS[app]}, user_search{};
    system("CLS");
    Karen->speak("opening " + MENU[app + LINKS_POSITION]);
    if (search)
    {
        Style::headline("EASY SEARCH", true);
        cout << "Please enter your " << MENU[app + LINKS_POSITION] << " boss : ";
        getline(cin >> ws, user_search);
        Settings::create_search_link(link, user_search);
    }
    ShellExecute(NULL, "open", link.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

/*---------- date_time - displays the current date and time ----------*/
void Board::date_time()
{
    string date;
    boolean display = true;
    system("CLS");
    Karen->speak("Opening date and time");
    Style::headline("DATE&TIME", true);
    cout << Style::MIDDLE << "Press any key to go back" << Style::HEADLINE_SPACE;
    while (display)
    {
        date = Time::get_date();
        cout << Style::MIDDLE << "\e[1m" << date; //Prints date in a bold font
        Sleep(1000);
        printf("\x1b[1F"); //Goes back to the last line begining and replaces it
        printf("\x1b[2K"); 
        if (kbhit())
            display = false;
            
    }
    cout << "\e[0m"; //Off bold font
    getch();
}

/*---------- exit - greets the user according to current hour and stops Karen's work ----------*/
void Board::exit()
{
    string phrase{};
    int hour = Time::current_hour();
    system("CLS");
    cout << Style::HEADLINE_SPACE << Style::MIDDLE;
    cout << "----------------------------------- G O O D B Y E  \3  B O S S -----------------------------------";
    if (hour >= night || hour < morning)
        phrase = "good night boss";
    else
    {
        if (hour < afternoon)
            phrase = "Have a great day boss";
        else
        {
            if (hour < evening)
                phrase = "good afternoon boss";
            else
                phrase = "good evening boss";
        }
    }
    Karen->speak(phrase);
}


/*---------- Destructor - deletes Karen after program ending ----------*/
Board::~Board()
{
    delete Karen;
}
