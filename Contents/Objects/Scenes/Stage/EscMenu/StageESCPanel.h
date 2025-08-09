#pragma once
#include "Components/Base/MonoBehavior.h"
#include "Components/UI/Button.h"
#include "Components/Rendering/BitmapRenderer.h"
#include "Components/Logic/InputSystem.h"

/* 25.08.09 | �ۼ���: �̼�ȣ
*  esc�޴��� ��� ��ư ���� ��ũ��Ʈ 
	������ �ݵ�� SetButtons�� SetButtonsPosition�� ���� ��� �� ��ġ ������ ���� ��
*/

class StageESCPanel : public MonoBehavior
{
public:
	void OnCreate() override;
	void OnStart() override;
	void OnUpdate() override;

	void SetButtons(const std::vector<GameObject*> buttons);
	void SetButtonsPosition();
	void DisablePanel();

private:

	BitmapRenderer* barBitmap{};
	InputSystem* input;

	std::vector<GameObject*> buttons; // ������� continue, exit, mute
};

