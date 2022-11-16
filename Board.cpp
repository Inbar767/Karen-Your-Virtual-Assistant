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

/*---------- run - runs the project ----------*/
void Board::run()
{
    int choice{};
    welcome();
    do{
        choice = menu();
        switch (choice)
        {
        case Voice:
            Karen.voice_manage();
            break;
        case Word:
            word();
            break;
        case Excel:
            excel();
            break;
        case Outlook:
            outlook();
            break;
        case Notepad:
            notepad();
            break;
        case Gmail:
            gmail();
            break;
        case Google:
            google();
            break;
        case Google_search:
            google_search();
            break;
        case Instagram:
            instagram();
            break;
        case Youtube:
            youtube();
            break;
        case Youtube_search:
            youtube_search();
            break;
        case Tasks:
            system("CLS");
            Karen.speak("Opening task Management");
            tasks.menu();
            break;
        case Date:
            date_time();
            break;
        }
    } while(choice != Off);
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
    Karen.speak("welcome my name is karen and I am your virtual assistant please enter user name and password");
    access();
    system("CLS");
    cout << Style::HEADLINE_SPACE << Style::MIDDLE;
    cout << "------------------------- W E L C O M E  \3  I N B A R ------------------------";
    Karen.speak("Welcome Inbar");
}

/*---------- access - gets user name and password from the user and checks if correct ----------*/
void Board::access()
{
    string password, user_name{};
    int c, i{};
    boolean sw_continue = true;
    while (sw_continue)
    {
        i = 0;
        user_name.clear();
        password.clear();
        system("CLS");
        cout << Style::HEADLINE_SPACE << Style::MIDDLE << Style::HEADLINE_BORDER << "\n";
        cout << Style::MIDDLE << "Please enter your user name : ";
        getline(cin >> ws, user_name);
        cout << Style::MIDDLE << Style::HEADLINE_BORDER << "\n";
        cout << Style::MIDDLE << "Please enter your password : ";
        while (c = getch())
        {
            if (i < PASSWORD_LENGTH && ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')))
            {
                cout << "x";
                password += c;
                i++;
            }
            else if (c == Settings_Functions::ENTER && i == PASSWORD_LENGTH)
                break;
            else if (c == Settings_Functions::DELETE_KEY && i > 0)
            {
                cout << Settings_Functions::BACK_KEY;
                password.erase(password.length() - 1);
                i--;
            }
        }
        if (user_name != USER_NAME || password != USER_PASSWORD)
            wrong_access();
        else
            sw_continue = false;
    }
}

/*---------- wrong_access - tells the user to try again access ----------*/
void Board::wrong_access()
{
    HANDLE text = GetStdHandle(STD_OUTPUT_HANDLE);
    string phrase{};
    cout << endl
         << Style::MIDDLE << Style::HEADLINE_BORDER << "\n";
    cout << Style::HEADLINE_SPACE << Style::MIDDLE << Style::BORDER << endl;
    SetConsoleTextAttribute(text, Style::RED);
    cout << Style::MIDDLE << "USER NAME OR PASSWORD WROG ! PLEASE TRY AGAIN\n";
    SetConsoleTextAttribute(text, Style::white);
    cout << Style::MIDDLE << Style::BORDER << endl;
    Karen.speak("please try again");
}

/*---------- search - gets from the user his search ----------*/
int Board::menu()
{
    int choice{};
    string search{};
    boolean all{};
    system("CLS");
    Style::headline("MENU", true);
    cout << Style::MIDDLE << "\4 \4 All - Check all options   \4 \4\n ";
    cout << Style::MIDDLE << "\4 \4 Off - Shut down assistant \4 \4\n";
    cout << Style::HEADLINE_SPACE << "Please type what you are looking for boss : ";
    getline(cin >> ws, search);
    Settings_Functions::convert_to_lower(search);
    cout << endl;
    if (search == options[MENU_LENGTH - 1])
        return MENU_LENGTH - 1;
    if (search == "all")
        all = true;
    Style::headline("OPTIONS", false);
    for (int i{}; i < MENU_LENGTH; i++)
    {
        if (all || options[i].find(search) != string::npos || i == MENU_LENGTH - 1 || i == 0)
            cout << i << "- " << options[i] << endl;
    }
    choice = Settings_Functions::insert_valid_choice("\nPlease enter your choice: ", 0, MENU_LENGTH - 1);
    while (choice < 0)
    {
        Karen.dont_understand();
        choice = Settings_Functions::insert_valid_choice("\nPlease enter your choice: ", 0, MENU_LENGTH - 1);
    }
    return choice;
}

/*---------- gmail - opens gmail ----------*/
void Board::gmail()
{
    system("CLS");
    Karen.speak("opening gmail");
    ShellExecute(NULL, "open", "http://gmail.com", NULL, NULL, SW_SHOWNORMAL);
}

/*---------- google - opens google ----------*/
void Board::google()
{
    system("CLS");
    Karen.speak("opening google");
    ShellExecute(NULL, "open", "http://google.com", NULL, NULL, SW_SHOWNORMAL);
}

/*---------- google_search - asks the user for his google search and opens it ----------*/
void Board::google_search()
{
    string link{}, search{};
    system("CLS");
    link = "https://www.google.com/search?q=";
    Karen.speak("opening google search");
    Style::headline("EASY GOOGLE SEARCH", true);
    cout << "Please enter your google search boss : ";
    getline(cin >> ws, search);
    Settings_Functions::create_link(link, search);
    ShellExecute(NULL, "open", link.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

/*---------- instagram - opens instagram ----------*/
void Board::instagram()
{
    system("CLS");
    Karen.speak("opening instagram");
    ShellExecute(NULL, "open", "https://www.instagram.com/", NULL, NULL, SW_SHOWNORMAL);
}

/*---------- youtube - opens youtube ----------*/
void Board::youtube()
{
    system("CLS");
    Karen.speak("opening youtube");
    ShellExecute(NULL, "open", "https://www.youtube.com/", NULL, NULL, SW_SHOWNORMAL);
}

/*---------- youtube_search - asks the user for his youtube search and opens it ----------*/
void Board::youtube_search()
{
    string link{}, search{};
    system("CLS");
    link = "https://www.youtube.com/results?search_query=";
    Karen.speak("opening youtube search");
    Style::headline("EASY YOUTUBE SEARCH", true);
    cout << "Please enter your youtube search boss : ";
    getline(cin >> ws, search);
    Settings_Functions::create_link(link, search);
    ShellExecute(NULL, "open", link.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

/*---------- word - opens new word file ----------*/
void Board::word()
{
    system("CLS");
    Karen.speak("opening word");
    ShellExecute(NULL, "open", "WINWORD.EXE", NULL, NULL, SW_SHOWNORMAL);
}

/*---------- excel - opens new excel file ----------*/
void Board::excel()
{
    system("CLS");
    Karen.speak("opening excel");
    ShellExecute(NULL, "open", "EXCEL.EXE", NULL, NULL, SW_SHOWNORMAL);
}

/*---------- outlook - opens outlook ----------*/
void Board::outlook()
{
    system("CLS");
    Karen.speak("opening outlook");
    ShellExecute(NULL, "open", "OUTLOOK.EXE", NULL, NULL, SW_SHOWNORMAL);
}

/*---------- notepad - opens new notepad file ----------*/
void Board::notepad()
{
    system("CLS");
    Karen.speak("opening notepad");
    ShellExecute(NULL, "open", "Notepad", NULL, NULL, SW_SHOWNORMAL);
}

/*---------- date_time - displays the current date and time ----------*/
void Board::date_time()
{
    string date = Time::get_date();
    system("CLS");
    Karen.speak("Opening date and time");
    Style::headline("DATE&TIME", true);
    cout << Style::HEADLINE_SPACE << Style::BORDER << endl;
    cout << date;
    cout << endl << Style::BORDER << Style::HEADLINE_SPACE;
    cout << "Press any key to go back ";
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
    Karen.speak(phrase);
}
