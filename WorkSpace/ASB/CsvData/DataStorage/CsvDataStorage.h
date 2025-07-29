#pragma once
#include <string>
#include <unordered_map>
#include "../DataClass/AllNodePattenClass.h"
#include "../DataClass/EnemyAtkPattenData.h"
#include "../DataClass/EnemyData.h"
#include "../DataClass/PlayerAtkPetternData.h"
#include "../DataClass/PlayerData.h"

class CsvDataStorage
{ // CSV ������ ���� Ŭ����
  // �� :   Ű : �� ������ ù ��° ��    �� : �ش� ���� �����͸� �����ϴ� Ŭ������ ������
	 
	std::unordered_map<std::string, AllNodePattenClass* > allNodePatternMap;
	std::unordered_map<std::string, EnemyAtkPattenData* > enemyAtkPatternDataMap;
	std::unordered_map<std::string, EnemyData* > enemyDataMap;
	std::unordered_map<std::string, PlayerAtkPetternData* > playerAtkPetternDataMap;
	std::unordered_map<std::string, PlayerData* > playerDataMap;
};

