#pragma once
#include <SDKwavefile.h>
#include <SDKsound.h>
#include "Singleton.h"
class Sound :
    public Singleton<Sound>
{
public:
    Sound();

    CSoundManager* mng;
    map<wstring, CSound*> soundgroup;

    void LoadSound(LPWSTR path, wstring name); // �̸� �ε�
    void PlaySFX(wstring name, bool isloop = false, LONG volume = 0);
    void StopSFX(wstring name);
};

