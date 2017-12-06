#pragma once
#pragma warning(disable: 4996) 

#include <string>
#include <memory>

//����ͷ�ļ��Ϳ�
#include "sapi.h"
#include "sphelper.h"
#pragma comment(lib, "sapi.lib")

class TTS
{
public:
    TTS();
    ~TTS();
    bool speak(std::string sText);
private:
    //string ת LPCWSTR
    LPCWSTR stringToLPCWSTR(std::string orig);
    std::shared_ptr<ISpVoice> m_pVoice;
    HRESULT m_hr;
};

