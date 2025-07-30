#pragma once
#include "Utils/Singleton.h"
#include <unordered_map>
#include "External/FMod/fmod.hpp"
#include "External/FMod/fmod_errors.h"
#include <string>
#include <iostream>
#include "Datas/SoundDatas.h"
#include <Windows.h>


// $(SolutionDir)Engine\External\FMOD\api\core\lib\x64
// "../../Engine/External/FMOD/api/core/lib/x64/fmod_vc.lib"
#pragma comment(lib, "../../Engine/External/Fmod/fmod_vc.lib")

/*
FMOD_RESULT playSound(
	FMOD::Sound *sound,         // [1] ����� ���� ��ü
	FMOD::ChannelGroup *group,  // [2] ���� ä�� �׷� (nullptr�̸� �⺻ �׷�), ������Ұ� ���� ����� ������ �Ѱ��� �׷쿡 �������
	bool paused,                // [3] �Ͻ����� ���·� �������� ����
	FMOD::Channel **channel     // [4] ���带 ������ �� �ִ� ä�� ������ (��¿�)
);

AudioSystem�� ��� bgm�� �ѹ��� ��ϰ���
����Ҷ��� struct ��ü�� ���� �� ��ü�� ��� ( Datas���� SoundDatas���)
��� ����� muteGroup���� ����ϱ⶧���� Setvolume �Լ��� ���� ��ü ���� ũ�� ���� ����


ä�� ������ �ʿ��Ҷ�
���� ���� �ߺ� ����� ���Ҷ� -> (isPlaying Ȯ�� �� ������̸� stop ����)
���� ���� ���� �� ��� ����Ҷ� -> (unique key , static int ������ �̿��� Ư���� key ����)
���带 �׷캰�� �����Ҷ� -> ���;ȿ� ����, channelGroup ��� , std::unordered_map<std::wstring, std::vector<FMOD::Channel*>> channels; ���

��� ���� ���⶧�� PauseSound() ,  ������Ҷ��� AgainstSound() ȣ��
Scene�Ѿ�� chanel �� ���¿뵵�� ReSetChannel() ȣ��

Fmod �ʱ�ȭ�� ä�� ������ Init�� �����Ͽ� ä�� ���� ���� �� ����
*/


class AudioSystem : public Singleton<AudioSystem>
{
public:
	
	void Initialize(int num);
	void Register(const std::vector<SoundResource>& sounds);
	void PlaySound2(const std::wstring& id);
	void UnRegister();

	

	void PauseSound();

	void AgainstSound();

	void ReSetChannel();

	//ä�� ���� ���� ������ �Լ� �߰��ϸ��

	void Setvolume(float state);

	static void CheckError(FMOD_RESULT result) {
		if (result != FMOD_OK) {
			std::cerr << "FMOD Error: " << FMOD_ErrorString(result) << std::endl;
			exit(-1);
		}
	}

	bool FileExists(const std::wstring& path);


private:
	FMOD::System* fmodSystem = nullptr;
	FMOD::Channel* channel = nullptr;
	std::unordered_map<std::wstring, FMOD::Sound*> sounds;
	std::unordered_map<std::wstring, FMOD::Channel*> Channels;
	FMOD::ChannelGroup* muteGroup;

};

