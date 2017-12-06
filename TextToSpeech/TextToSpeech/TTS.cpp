#include "TTS.h"
#include <iostream>

TTS::TTS()
{
    m_pVoice = NULL;
    //COM初始化
    if (FAILED(::CoInitialize(NULL)))
    {
        std::cerr << "Init Fail!" << std::endl;
        return;
    }

    //获取ISpVoice接口
    m_hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&m_pVoice);
    if (!SUCCEEDED(m_hr))
    {
        std::cerr << "Get Fail!" << std::endl;
    }
}


TTS::~TTS()
{
    m_pVoice->Release();
    m_pVoice = NULL;
    ::CoUninitialize();
}

bool TTS::speak(std::string sText)
{
    m_pVoice->Speak(stringToLPCWSTR(sText), 0, NULL);
    std::cout << m_hr << std::endl;
    return false;
}

LPCWSTR TTS::stringToLPCWSTR(std::string orig)
{
    size_t origsize = orig.length() + 1;
    const size_t newsize = 100;
    size_t convertedChars = 0;
    wchar_t *wcstring = (wchar_t *)malloc(sizeof(wchar_t)*(orig.length() - 1));
    mbstowcs_s(&convertedChars, wcstring, origsize, orig.c_str(), _TRUNCATE);
    return wcstring;
    return LPCWSTR();
}
