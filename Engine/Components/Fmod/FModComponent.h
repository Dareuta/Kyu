#pragma once
#include "Components/Base/Component.h"
#include "External/FMod/fmod.hpp"
#include "External/FMod/fmod_errors.h"
#include <iostream>
#include <unordered_map>
#include "Datas/SoundDatas.h"


/*
����

������
�ݺ� ��� ȿ����	FMOD_DEFAULT | FMOD_LOOP_NORMAL
���� ���� ȿ����	FMOD_DEFAULT | FMOD_LOOP_OFF (�Ǵ� �׳� FMOD_DEFAULT)
���� ��� BGM		FMOD_CREATESTREAM | FMOD_LOOP_NORMAL

*/

class FModComponent : public Component
{
public:

	/*void OnCreate() override;*/
	//void OnStart() override;
	void OnDestroy() override;
	void AddSound(const std::vector<SoundInfo>& list);
	void PlaySound(const std::wstring& id);


private:
	std::unordered_map<std::wstring, std::wstring> soundsID;
};