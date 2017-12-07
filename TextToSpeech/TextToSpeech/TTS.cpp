#include "TTS.h"

TTS::TTS()
{
    m_pVoice = NULL;
    //COM初始化
    if (FAILED(::CoInitialize(NULL)))
    {
        m_bIsEnable = false;
        return;
    }

    //获取ISpVoice接口
    m_hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&m_pVoice);
    if (!SUCCEEDED(m_hr))
    {
        m_bIsEnable = false;
        return;
    }
    m_bIsEnable = true;
}


TTS::~TTS()
{
    m_pVoice->Release();
    m_pVoice = NULL;
    ::CoUninitialize();
}

void TTS::speak(std::string sText)
{
    int nLen = MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, sText.c_str(), -1, NULL, 0);
    if (nLen == 0)
    {
        //MultiByteToWideChar get length = 0
        return ;
    }
    wchar_t* pResult = new wchar_t[nLen];
    MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, sText.c_str(), -1, pResult, nLen);
    m_pVoice->Speak(pResult, 0, NULL);
    delete pResult;
}

bool TTS::bIsEnable()
{
    return m_bIsEnable;
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
