/*
----------------------------------------------------------------------------
               Project title   : Karen - Your Virtual Assistant
               Made By         : Inbar Maor
               Written in      : C++
               Platform        : Windows
               IDE used        : Visual Studio Code
 ----------------------------------------------------------------------------
*/

#include "Assistant.h"
#include "Settings.h"

/*---------- constructor ----------*/
Assistant::Assistant()
{
    voice = DEFAULT_VOICE;
}

/*---------- speak - gets a phrase and says it ----------*/
void Assistant::speak(const string &phrase)
{
    string speaking = "espeak -v +";
    speaking += voice;
    string command = speaking + " \"" + phrase + "\"";
    const char *charCommand = command.c_str();
    system(charCommand); 
}

/*---------- dont_understand - tells the user his input incorrect ----------*/
void Assistant::dont_understand()
{
    speak("sorry i dont understand");
}

/*---------- change_voice - changes assistant's voice ----------*/
void Assistant::change_voice(int choice)
{
    if (choice != 0)
    {
        if (choice > NUMBER_OF_VOICES)
            voice = MALE_VOICES[choice - (NUMBER_OF_VOICES + 1)];
        else
            voice = FEMALE_VOICES[choice - 1];
    }
}

/*---------- voice_manage - asks the user to input a number which  ----------
  ---------- represents assistant's voice and changes it if the user choose to ----------*/
void Assistant::voice_manage()
{
    string old_voice{voice};
    string is_sure{NO};
    int choice{};
    boolean sw_continue = true;
    system("CLS");
    speak("Opening assistance voice changing");
    while (sw_continue)
    {
        system("CLS");
        Style::headline("ASSISTANT VOICE", true);
        cout << "Please choose a number that represents voice from 1 to 10\nTo exit press 0\n";
        cout << Style::HEADLINE_SPACE;
        choice = Settings::insert_valid_choice("\nPlease enter your choice: ", NUMBER_OF_VOICES * 2);
        if (choice < 0)
        {
            cout << Style::HEADLINE_SPACE;
            Style::wrong("Invalid choice !");
            Sleep(2000);
            continue;
        }
        change_voice(choice);
        is_sure = insert_valid_choice("\nAre you sure boss ? (Y / N) : ", "Are you sure boss");
        if (is_sure == NO)
        {
            voice = old_voice;
            cout << endl;
        }
        else
        {
            sw_continue = false;
        }
    }
}

/*---------- insert_valid_choice - checks if the user input is ----------
  ---------- a valid choice and if not - ask the user for typing again ----------*/
string Assistant::insert_valid_choice(const string &phrase, const string &assitant_phrase)
{
    string choice{};
    speak(assitant_phrase);
    boolean sw_continue = true;
    while (sw_continue)
    {
        cout << phrase;
        choice = "";
        getline(cin >> ws, choice);
        choice.erase(remove_if(choice.begin(), choice.end(), ::isspace), choice.end());
        Settings::convert_to_lower(choice);
        if (choice != YES && choice != NO)
        {
            cout << Style::HEADLINE_SPACE;
            Style::wrong("Invalid choice !");
            Sleep(2000);
        }
        else
        {
            sw_continue = false;
        }
    }
    return choice;
}
