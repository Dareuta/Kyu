#include "LogicTestApplication.h"
#include "Utils/Singleton.h"
#include "Scene/SceneManager.h"
#include "../GameLogicTestScene/GameLogicTestScene.h"

void LogicTestApplication::LogicTestApplication::Initialize()
{
	// 1. SceneManager�� Scene �߰��ϱ�
	GameLogicTestScene = new GameLogicTestScene();	// MainMenu �� ��ü ����
	Singleton<SceneManager>::GetInstance().AddScene(GameLogicTestScene); // �� �߰�
	Singleton<SceneManager>::GetInstance().Init();	// SceneManager �ʱ�ȭ -> currentScene �ʱ�ȭ �� RenderSystem�� RenderLayer �ʱ�ȭ
}

void LogicTestApplication::LogicTestApplication::Render()
{
	__super::Render();
}

void LogicTestApplication::LogicTestApplication::Uninitialize()
{
	__super::Uninitialize();
}

void LogicTestApplication::LogicTestApplication::Update()
{
	__super::Update();
}