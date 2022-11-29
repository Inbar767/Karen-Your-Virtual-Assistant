/*
----------------------------------------------------------------------------
               Project title   : Karen - Your Virtual Assistant
               Made By         : Inbar Maor
               Written in      : C++
               Platform        : Windows
               IDE used        : Visual Studio Code
 ----------------------------------------------------------------------------
*/


#ifndef Assistant_H
#define Assistant_H

#include "Settings.h"
#include "Settings.cpp"

#define NUM_VOICES 5 
#define DEFAULT_VOICE "f4" 
#define YES "y"
#define NO "n"

/*---------- class of the virtual assistant ----------*/
class Assistant
{
private:
    const string FEMALE_VOICES[NUM_VOICES] {"f1", "f2", "f3", "f4", "f5"}; //Female voices array
    const string MALE_VOICES[NUM_VOICES] {"m1", "m2", "m3", "m4", "m5"}; //Male voices array
    string voice;

    string insert_valid_choice(const string &, const string &);
    void change_voice(int);

public:
    Assistant();
    void voice_manage();
    void speak(const string &);
    void dont_understand();
};

#endif // ASSISTANT_H