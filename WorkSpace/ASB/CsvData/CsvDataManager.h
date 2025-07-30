#pragma once
#include <windows.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <string>
#include "Utils/Singleton.h"
#include "DataStorage/CsvDataStorage.h"
#include <fcntl.h> // �ܼ�â�� wstring�� ����ϱ� ���� ���
#include <io.h>
/*25.07.29 - �ȼ���.
	���� : CsvDataManager Ŭ������ CSV ������ �о�ͼ� �����͸� �����ϴ� Ŭ����
		   CSV ������ ù ��° ���� Ű�� ����ϰ�, ������ Ŭ������ �����͸� ������ �ʿ� ������

	���� : baseData�� �ִ� �����͸� �ڷᱸ���� �����ϴ� �Լ�(SetData)�� ȣ�������� �ش� Ŭ������ ���� baseData�� ��ӹ޴°��� ����
*/
/*25.07.30 - �ȼ���
	 ���� : ���� ����Լ��� ���� ��ü�� ���� �־����� ���� �ϴ� ��ü�� ���� �и��Ͽ� �Ŵ������� �����ϴ� ���·� ��ȯ
			���� c++14�� ����Ͽ� if constexpr�� ������� ��������, ����ġ ���� �Լ��� ����Ͽ� Ÿ�Կ� �´� �Լ��� ȣ����
			�Ŵ����� �����͸� ó���ϴ� �߾Ӱ����ڷ� �����, �̵����� ��ӹ޾� ������� �ʰ� ��
			�� �����Ϳ�	�Ŵ����� CsvDataStorage Ŭ������ ��ӹ޾� �����
			����ġ ���� �Լ�: ���ø� �ν��Ͻ��� �� Ÿ�Կ� �°� ���� ���ε��ǵ��� ����� �����
								-> �׳� �Լ��� �����ε��Ͽ� �Ű������� �´� �Լ��� ȣ���ϴ� ����ε�?
*/


class CsvDataManager : public Singleton<CsvDataManager>
{
public:
	CsvDataManager() = default; // ������
	~CsvDataManager() override; // �Ҹ���
	friend class Singleton<CsvDataManager>; // �̱��� ������ ����ϱ� ���� ģ�� Ŭ���� ����
public:
	// �Ű�����  : CSV ������ ���, ���� ���� ��ŵ�� ������ ��
	// CSV ������ �о�ͼ� std::unordered_map�� �����ϴ� �Լ�

	template<typename T>
	void SetCSV(const std::string filePath, int skipLine);
	
	// ������ Ÿ���� �������� ���� ã��, ID�� �ش��ϴ� �������� �����͸� ��ȯ�� 
	template<typename T>
	T* GetCSV(const std::string DataID);


	// �ֿܼ�
	// ��ü�� �ܼ�â�� ���� �Լ�, Ű�� ���� ���� ����ϴ� �Լ�
	void PrintMap();

	
private:
	// CSV ������ ���� Ŭ����
	CsvDataStorage<AllNodePattenClass> allNodePattenStorage;
	CsvDataStorage<EnemyAtkPattenData> enemyAtkPattenStorage;
	CsvDataStorage<EnemyData> enemyDataStorage;
	CsvDataStorage<PlayerAtkPetternData> playerAtkPetternStorage;
	CsvDataStorage<PlayerData> playerDataStorage;
	

	//CreateDate ���� �Լ�
	template<typename T>
	T* CreateDataImpl(T* tag) {  return nullptr; } // �⺻ ���� (���� ó��)
	AllNodePattenClass* CreateDataImpl(AllNodePattenClass* tag) { return allNodePattenStorage.CreateData(); }
	EnemyAtkPattenData* CreateDataImpl(EnemyAtkPattenData* tag) { return enemyAtkPattenStorage.CreateData(); }
	EnemyData* CreateDataImpl(EnemyData* tag) { return enemyDataStorage.CreateData(); }
	PlayerAtkPetternData* CreateDataImpl(PlayerAtkPetternData* tag) { return playerAtkPetternStorage.CreateData(); }
	PlayerData* CreateDataImpl(PlayerData* tag) { return playerDataStorage.CreateData(); }

	//SaveDataImpl ���� ����
	void SaveDataImpl(const std::string& key, AllNodePattenClass* data) { allNodePattenStorage.SetData(key, data); }
	void SaveDataImpl(const std::string& key, EnemyAtkPattenData* data) { enemyAtkPattenStorage.SetData(key, data); }
	void SaveDataImpl(const std::string& key, EnemyData* data) { enemyDataStorage.SetData(key, data); }
	void SaveDataImpl(const std::string& key, PlayerAtkPetternData* data) { playerAtkPetternStorage.SetData(key, data); }
	void SaveDataImpl(const std::string& key, PlayerData* data) { playerDataStorage.SetData(key, data); }

	//
	template<typename T>
	void DispatchSaveData(const std::string& key, T* ptr) {
		static_assert(sizeof(T) == 0, "�������� �ʴ� Ÿ���Դϴ�");
	}
	template<>
	void DispatchSaveData<AllNodePattenClass>(const std::string& key, AllNodePattenClass* ptr) {
		allNodePattenStorage.SetData(key, ptr);
	}
	template<>
	void DispatchSaveData<EnemyData>(const std::string& key, EnemyData* ptr) {
		enemyDataStorage.SetData(key, ptr);
	}
	template<>
	void DispatchSaveData<PlayerAtkPetternData>(const std::string& key, PlayerAtkPetternData* ptr) {
		playerAtkPetternStorage.SetData(key, ptr);
	}
	template<>
	void DispatchSaveData<PlayerData>(const std::string& key, PlayerData* ptr) {
		playerDataStorage.SetData(key, ptr);
	}

	//GetData ����
	AllNodePattenClass* getDataImpl(AllNodePattenClass* tag, std::string ID) 
		{ return allNodePattenStorage.GetData(ID); }
	EnemyAtkPattenData* getDataImpl(EnemyAtkPattenData* tag, std::string ID)
		{return enemyAtkPattenStorage.GetData(ID);}
	EnemyData* getDataImpl(EnemyData* tag, std::string ID)
		{return enemyDataStorage.GetData(ID);}
	PlayerAtkPetternData* getDataImpl(PlayerAtkPetternData* tag, std::string ID)
		{return playerAtkPetternStorage.GetData(ID);}
	PlayerData* getDataImpl(PlayerData* tag, std::string ID)
		{return playerDataStorage.GetData(ID);}
};


//if constexpr :  ���ǿ� �´� �б�� �ƿ� �����ϵǰ� ������ ���� �ʴ� �б�� �����ϵ��� ����



template<typename T>
void CsvDataManager::SetCSV(const std::string filePath, int skipLine) {
	static_assert(std::is_base_of_v<BaseData, T>); // T�� BaseData�� ��ӹ޴��� Ȯ���ϴ� ����


	//������ Ŭ���� T�� Ÿ���� �˻��ؼ� ���ٸ� ������ ����ҿ��� ������ Ŭ���� �����Լ� ȣ��
	T* tmpData = CreateDataImpl(static_cast<T*>(nullptr));

	std::wifstream file(filePath); // ���� ��Ʈ�� ����
	if (!file.is_open()) {  // ���� ���� ���� �� ���� �޽��� ���
		//std::cout << "������ �� �� �����ϴ�: " << file << std::endl;
	}

	// �� ������ Ÿ�Կ� ���� �����Ǵ� ������ �ٸ�


	std::wstring line;	 // ���� ���� ������ ����
	int countLine = 1;	 // ���� ���� ��ȣ (1���� ����)


	while (std::getline(file, line)) {
		if (countLine++ <= skipLine) continue; // ��� �ǳʶٱ�


		std::wstringstream ss(line);   // ���ڿ� ��Ʈ�� ����
		std::wstring cell;			   // �� ���� ������ ����
		std::vector<std::wstring> row; // ���� ���� ������ ������ ����
		std::wstring key;	           // Ű�� ����� ù ��° ���� ��
		bool isFirst = true;           // ù ��° ������ ���θ� Ȯ���ϴ� �÷���

		while (std::getline(ss, cell, L',')) {
			if (isFirst) {		 // ù ��° ���� Ű�� ���
				key = cell;
				isFirst = false;
			}
			row.push_back(cell); // ������ ���� ���Ϳ� �߰�
		}

		//������ Ŭ���� ��ü�� �� ���� �����͸� vector<wstring>�� ���� �־���
		tmpData->SetData(row); // SetData �Լ��� ȣ���Ͽ� �����͸� ����




		// ����ó��
		// key�� ��������� �������� ���� (��ȣ ����)
		//
		if (!key.empty()) {
			//SaveDataImpl(key, tmpData); // SaveDataImpl �Լ��� ȣ���Ͽ� �����͸� ����
			this->DispatchSaveData(key, tmpData); // DispatchSaveData �Լ��� ȣ���Ͽ� �����͸� ����
		}
	}
	// �����͸� �����ϴ� �Լ� �ʿ���!!!
	file.close();
}



template<typename T>
T* CsvDataManager::GetCSV(const std::string DataID) {
	return getDataImpl(static_cast<T*>(nullptr), DataID);
}
