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

using namespace std;

/*---------- constructor ----------*/
Assistant::Assistant()
{
    voice = DEFAULT_VOICE;
}

/*---------- speak - gets a phrase and say it ----------*/
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
        if (choice > NUM_VOICES)
            voice = MALE_VOICES[choice - (NUM_VOICES + 1)];
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
    system("CLS");
    speak("Opening assistance voice changing");
    Style::headline("ASSISTANT VOICE", true);
    cout << "Please choose a number that represents voice from 1 to 10\nTo exit press 0\n";
    while (is_sure == NO)
    {
        cout << Style::HEADLINE_SPACE;
        choice = Settings_Functions::insert_valid_choice("\nPlease enter your choice: ", 0, NUM_VOICES * 2);
        while (choice < 0)
        {
            dont_understand();
            choice = Settings_Functions::insert_valid_choice("\nPlease enter your choice: ", 0, NUM_VOICES * 2);    
        }
        change_voice(choice);
        is_sure = insert_valid_choice("\nAre you sure boss ? (Y / N) : ", "Are you sure boss");
        if (is_sure == NO)
        {
            voice = old_voice;
            cout << endl;
        }
    }
}

/*---------- insert_valid_choice - checks if the user input is ----------
  ---------- a valid choice and if not - ask the user for typing again ----------*/
string Assistant::insert_valid_choice(const string &phrase, const string &assitant_phrase)
{
    string choice{};
    cout << phrase;
    speak(assitant_phrase);
    getline(cin >> ws, choice);
    choice.erase(remove_if(choice.begin(), choice.end(), ::isspace), choice.end());
    Settings_Functions::convert_to_lower(choice);
    if (choice != YES && choice != NO)
    {
        dont_understand();
        return insert_valid_choice(phrase, assitant_phrase);
    }
    return choice;
}
