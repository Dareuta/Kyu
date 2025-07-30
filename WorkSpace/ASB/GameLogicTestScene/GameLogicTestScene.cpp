#include "GameLogicTestScene.h"
#include "LiveObject/LiveObject.h"
#include "../DataStorage/CsvDataManager.h"
#include "../DataClass/AllNodePattenClass.h"
void GameLogicTestScene::OnEnterImpl()
{
	//menuObj = new GameObject(); // GameObject ��ü ����
	//menuObj->AddComponent<MenuTextObject>(); // MonoBehaivor ���
	//AddGameObject(menuObj);	// Scene�� GameObject �߰�
	CsvDataManager<AllNodePattenClass> CsvDataManager; // CsvDataManager ��ü ����
	CsvDataManager.SetCSV("../../Resource/DataTable/��� ��ü ���� ���̺�.csv", 5); // ������ ���� �о����
	CsvDataManager.PrintMap();
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