#pragma once

#include <vector>
#include <iostream>
#include "../../Engine/Scene/Scene.h"
#include "../../Engine/Components/Base/GameObject.h"

/*2025.07.28 - �ȼ���
 ���� ���� �׽�Ʈ ��
 ���߿� ����� Scene�� ���� ���鿹��

*/

class GameLogicTestScene : public Scene
{
public:
	GameLogicTestScene() {}
	~GameLogicTestScene() = default;
protected:
	void OnEnterImpl() override;
	void OnExitImpl() override;
	void UpdateImpl() override;

private:
	GameObject* menuObj;

};

