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

/*---------- class of the virtual assistant ----------*/
class Assistant
{
private:
    const int NUMBER_OF_VOICES = 5;
    const string DEFAULT_VOICE = "f4";
    const string YES = "y";
    const string NO = "n";
    const string FEMALE_VOICES[NUMBER_OF_VOICES] {"f1", "f2", "f3", "f4", "f5"}; //Female voices array
    const string MALE_VOICES[NUMBER_OF_VOICES] {"m1", "m2", "m3", "m4", "m5"}; //Male voices array
    
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
