#pragma once
#include "Components/Base/MonoBehavior.h"
#include "Components/UI/Button.h"

/* 25.08.09 | �ۼ���: �̼�ȣ
* esc�޴� ���Ұ� ��ư ������Ʈ�� ���� monobehavior
*/

class EscMuteButton : public MonoBehavior
{
public:
	void OnCreate() override;
	void OnStart() override;

private:
	Button* muteButton{};
};
