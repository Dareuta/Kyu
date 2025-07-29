#include "GameLogicTestScene.h"
#include "LiveObject/LiveObject.h"
#include "../DataStorage/CsvDataStorage.h"
#include "../DataStorage/DataClass/AllNodePattenClass.h"
void GameLogicTestScene::OnEnterImpl()
{
	//menuObj = new GameObject(); // GameObject ��ü ����
	//menuObj->AddComponent<MenuTextObject>(); // MonoBehaivor ���
	//AddGameObject(menuObj);	// Scene�� GameObject �߰�
	CsvDataStorage<AllNodePattenClass> csvDataStorage; // CsvDataStorage ��ü ����
	csvDataStorage.SetCSV("../../Resource/DataTable/��� ��ü ���� ���̺�.csv", 5); // ������ ���� �о����
	csvDataStorage.PrintMap();
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