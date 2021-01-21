#include "DXUT.h"
#include "Sound.h"

Sound::Sound()
{
	mng = new CSoundManager();
	mng->Initialize(DXUTGetHWND(), DSSCL_PRIORITY);
	mng->SetPrimaryBufferFormat(22050, 1, 15);
}

void Sound::LoadSound(LPWSTR path, wstring name)
{
	CSound* sound;
	auto iter = soundgroup.find(name);
	if (iter == soundgroup.end()) // ���� �׷� �ȿ� ���� ã�� ���尡 �ߺ��� ���� �ʴ´ٸ�
	{
		if (FAILED(mng->Create(&sound, path, DSBCAPS_CTRLVOLUME, GUID_NULL, 15)))
		{
			wcout << "S LOAD FAILED : " << name << endl;
		}
		else
		{
			wcout << "S LOAD COMPLETE : " << name << endl;
			soundgroup.emplace(name, sound);
		}
	}
}

void Sound::PlaySFX(wstring name, bool isloop, LONG volume)
{
	auto iter = soundgroup.find(name);
	if (iter == soundgroup.end()) // �ȿ� ã�� ���尡 ���ٸ�
	{
		wcout << "play fail : " << name << endl;
		return;
	}
	iter->second->Play(0, isloop, volume);
}

void Sound::StopSFX(wstring name)
{
	auto iter = soundgroup.find(name);
	if (iter == soundgroup.end())
		return;
	iter->second->Stop();
}
