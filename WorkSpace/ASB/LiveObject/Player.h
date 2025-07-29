#pragma once
#include "LiveObject.h"
class Player : public LiveObject
{
public:
	Player() = default;
	~Player() = default;
	void OnCreate();
	void OnStart();
	void OnUpdate();
	void OnFixedUpdate();
	void OnDestroy();

	// �÷��̾��� ���¸� �ʱ�ȭ�ϴ� �Լ�
	void ResetPlayerState();
};

