#pragma once
#include <string>
#include <unordered_map>
#include <typeinfo>
#include "Utils/Singleton.h"
#include "../DataClass/AllNodePattenClass.h"
#include "../DataClass/EnemyAtkPattenData.h"
#include "../DataClass/EnemyData.h"
#include "../DataClass/PlayerAtkPetternData.h"
#include "../DataClass/PlayerData.h"

/*2025.07.30 - �ȼ���
   ���� : CsvDataStorage Ŭ������ CSV ���Ͽ��� �о�� �����͸� unordered_map�� �����ϴ� Ŭ���� 
	
*/



class CsvDataManager;


// ���丮������ ��� ���� ���̽� ���丮�� Ŭ����
template<typename T>
class CsvDataStorage
{ // CSV ������ ���� Ŭ����
  // �� :   Ű : �� ������ ù ��° ��    �� : �ش� ���� �����͸� �����ϴ� Ŭ������ ������
public:
	CsvDataStorage() {};
	virtual ~CsvDataStorage() {};
	friend class Singleton<CsvDataManager>; // �̱��� ������ ����ϱ� ���� ģ�� Ŭ���� ����

private:
	std::unordered_map<std::string, T* > DataMap;

public:

	// ������ Ŭ������ ��ü ����
	T*  CreateData(){
		T* tmpData = new T();
		return tmpData;
	}


	// Ű�� ��(�������� ������)�� ���� �ʿ� ����
	void SetData(const std::string DataID, T* tmpData) {
		DataMap[DataID] = tmpData; 
	}

	// �����͸� ������ �Լ�
	T* GetData(const std::string DataID) {
		auto it = DataMap.find(DataID);
		if (it != DataMap.end()) {
			return it->second;
		}
	}
};


