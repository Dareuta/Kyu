#pragma once

#include <vector>
#include <iostream>
#include "Scene/Scene.h"
#include "Components/Base/GameObject.h"

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

