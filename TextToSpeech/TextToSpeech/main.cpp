#include <iostream>
#include <string>
#include <atlstr.h>
#include "TTS.h"

using namespace std;

int main(void)
{
    string sText;
    TTS tts;
    if (!tts.bIsEnable())
    {
        cout << "TTS Init Fail!" << endl;
        return 1;
    }
    do
    {
        cout << "Please Input The Text:";
        cin >> sText;
        tts.speak(sText);
    } while (true);

    return 0;
}