#include "AudioSystem.h"

#include "Utils/StringConvert.h"

bool AudioSystem::FileExists(const std::wstring& path)
{
	DWORD attrib = GetFileAttributesW(path.c_str());
	return (attrib != INVALID_FILE_ATTRIBUTES && !(attrib & FILE_ATTRIBUTE_DIRECTORY));
}


void AudioSystem::Initialize(int num)
{
	CheckError(FMOD::System_Create(&fmodSystem));
	CheckError(fmodSystem->init(num, FMOD_INIT_NORMAL, nullptr));
	fmodSystem->createChannelGroup("MuteGroup", &muteGroup);
}

void AudioSystem::Register(const std::vector<SoundResource>& soundlist)
{
	//for (const auto& it : soundlist)
	//{
	//	const std::wstring& id = std::get<0>(it);
	//	const std::wstring& path = std::get<1>(it);
	//	FMOD_MODE mode = std::get<2>(it);

	//	//�ߺ�����
	//	if(sounds.count(id)) continue;

	//	FMOD::Sound* sound = nullptr;
	//	fmodSystem->createSound(StringConvert::WstringToString(path).c_str(), mode, nullptr, &sound);
	//	sounds[id] = sound;
	// struct ��ü ����� �ڵ�
	//}

	if (!FileExists(L"../../Resource/sounds/����/����_3.mp3")) {
		std::cout << "[����] ������ �������� ����!" << std::endl;
	}
	else { std::cout << "���������� �ε�!" << std::endl;}
	std::cout << "FileExists �˻� ��\n";

	for (const auto& it : soundlist)
	{
		if (sounds.count(it.id)) continue;

		FMOD::Sound* sound = nullptr;
		fmodSystem->createSound(StringConvert::WstringToString(it.path).c_str(), it.mode, nullptr, &sound);
		sounds[it.id] = sound;
		

	}
}


void AudioSystem::PlaySound2(const std::wstring& id)
{
	CheckError(fmodSystem->playSound(sounds[id], muteGroup, false, &channel));
}


void AudioSystem::UnRegister()
{
	for (auto& it : sounds) {
		it.second->release();
		it.second = nullptr;
	}
	//Fmod�� release�� �����ؾ��� , delete ���� Fmod ���� ���ҽ� �ջ� ��������
	sounds.clear();
}

void AudioSystem::PauseSound()
{
	std::cout << "���� ȣ��" << std::endl;
	muteGroup->setPaused(true);
}

void AudioSystem::AgainstSound()
{
	std::cout << "����� ȣ��" << std::endl;
	muteGroup->setPaused(false);
}

void AudioSystem::ReSetChannel()
{
	std::cout << "ä�λ��� ȣ��" << std::endl;
	muteGroup->stop();
}

void AudioSystem::Setvolume(float state)
{
	muteGroup->setVolume(state);
}
