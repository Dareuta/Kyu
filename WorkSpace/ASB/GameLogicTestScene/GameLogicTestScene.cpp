#include "GameLogicTestScene.h"
#include "LiveObject/LiveObject.h"
#include "../CsvData/DataClass/AllNodePattenClass.h"
#include "../CsvData/CsvDataManager.h"
#include "Utils/Singleton.h"
void GameLogicTestScene::OnEnterImpl()
{
	//menuObj = new GameObject(); // GameObject ��ü ����
	//menuObj->AddComponent<MenuTextObject>(); // MonoBehaivor ���
	//AddGameObject(menuObj);	// Scene�� GameObject �߰�
	
	CsvDataManager::GetInstance().SetCSV<AllNodePattenClass>("../../Resource/DataTable/��� ��ü ���� ���̺�.csv", 5); // ������ ���� �о����
	CsvDataManager::GetInstance().PrintMap();
}

void GameLogicTestScene::OnExitImpl()
{

}

void GameLogicTestScene::UpdateImpl()
{
	while (1) {
		int a = 1;
		a + 1;
	}
}