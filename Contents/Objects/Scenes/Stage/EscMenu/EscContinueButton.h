#pragma once
#include "Components/Base/MonoBehavior.h"
#include "Components/UI/Button.h"

/* 25.08.09 | �ۼ���: �̼�ȣ
* esc�޴� ��� ��ư ������Ʈ�� ���� monobehavior
	
	Panel ��ũ��Ʈ���� �̺�Ʈ ���� ����
*
*/

class EscContinueButton : public MonoBehavior
{
public:
	void OnCreate() override;
	void OnStart() override;

private:
	Button* continueButton{};
};

