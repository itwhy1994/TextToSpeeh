#pragma once
#pragma warning(disable: 4996) 

#include <string>
#include <memory>

//包含头文件和库
#include "sapi.h"
#include "sphelper.h"
#pragma comment(lib, "sapi.lib")

class TTS
{
public:
    TTS();
    ~TTS();
    //语音合成是否可用
    bool bIsEnable();
    //通过文本合成语音
    void speak(std::string sText);
    
private:
    //string 转 LPCWSTR
    LPCWSTR stringToLPCWSTR(std::string orig);
    std::shared_ptr<ISpVoice> m_pVoice;
    HRESULT m_hr;
    bool m_bIsEnable;
};

