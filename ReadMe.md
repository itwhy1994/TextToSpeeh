#文字转语音

使用微软的SAPI编写了一个TTS类
VS2015 C++

##使用方法
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
