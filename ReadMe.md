#����ת����

ʹ��΢���SAPI��д��һ��TTS��

##ʹ�÷���
```
#include "TTS.h"
int main()
{
    string sText = "Hello World";
    TTS tts;
    if (tts.bIsEnable())
    {
        tts.speak(sText);
    }
}
```