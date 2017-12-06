#include <iostream>
#include <string>
#include "TTS.h"

using namespace std;

int main(void)
{
    string sText;
    TTS tts;
    do
    {
        cout << "Please Input The Text:";
        cin >> sText;
        tts.speak(sText);
    } while (true);

    return 0;
}