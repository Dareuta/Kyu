#pragma once
#include "Application/Application.h"
#include "Scene/Scene.h"
#include "Datas/SoundDatas.h"
#include <vector>

namespace SoundApp
{
	class SoundApp : public Application
	{
	public:
		void Initialize() override;
		void Uninitialize() override;

	private:
		Scene* testScene{};
		std::vector<SoundResource> musiclist = {
		{ L"P_Attack01",  L"../../Resource/sounds/����/����_3.mp3",  FMOD_DEFAULT | FMOD_LOOP_OFF },
		{ L"P_Attack02", L"../../Resource/sounds/����/����_4.mp3", FMOD_DEFAULT | FMOD_LOOP_OFF },
		{ L"P_Attack03",  L"../../Resource/sounds/����/����_5.mp3",  FMOD_DEFAULT | FMOD_LOOP_OFF },
		{ L"P_Break01",  L"../../Resource/sounds/�⼼/�⼼�ı�.mp3",  FMOD_DEFAULT | FMOD_LOOP_OFF },
		{ L"P_Guard01",  L"../../Resource/sounds/���_��/���_5.mp3",  FMOD_DEFAULT | FMOD_LOOP_OFF },
		{ L"P_Guard02",  L"../../Resource/sounds/���_��/���_6.mp3",  FMOD_DEFAULT | FMOD_LOOP_OFF },
		{ L"M_Bgm01",  L"../../Resource/sounds/bgmtest1.mp3",  FMOD_CREATESTREAM | FMOD_LOOP_NORMAL },
		{ L"M_Bgm02",  L"../../Resource/sounds/bgmtest2.mp3",  FMOD_CREATESTREAM | FMOD_LOOP_NORMAL },
		};
	};
}
