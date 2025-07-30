#pragma once
#include <windows.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <string>

#include <fcntl.h> // �ܼ�â�� wstring�� ����ϱ� ���� ���
#include <io.h>

/*25.07.29 - �ȼ���
	���� : CsvDataManager Ŭ������ CSV ������ �о�ͼ� �����͸� �����ϴ� Ŭ����
		  CSV ������ ù ��° ���� Ű�� ����ϰ�, ������ Ŭ������ �����͸� ������ �ʿ� ������

	���� : baseData�� �ִ� ���͸� �ڷᱸ���� �����ϴ� �Լ�(SetData)�� ȣ�������� �ش� Ŭ������ ���� baseData�� ��ӹ޴°��� ����

*/

//�̱������� ����
//       ������,     ��
template<typename T, typename U>
class CsvDataManager {
public:
	CsvDataManager() {};
	~CsvDataManager() {};


	// map�� Ű : ù ��° ���� ��(ID), 
	//		 �� : �ش� ���� �����͸� �����ϴ� Ŭ������ ������
	std::unordered_map<std::wstring, T*> DataMap; 



	// �Ű�����  : CSV ������ ���, ���� ���� ��ŵ�� ������ ��
	// CSV ������ �о�ͼ� std::unordered_map�� �����ϴ� �Լ�
	U SetCSV(const std::string& filePath, int skipLine) {

		std::wifstream file(filePath); // ���� ��Ʈ�� ����

		U tmpMap; // �ӽ� �� ����
		if (!file.is_open()) {  // ���� ���� ���� �� ���� �޽��� ���
			//std::cout << "������ �� �� �����ϴ�: " << file << std::endl;
		}


		std::wstring line;	 // ���� ���� ������ ����
		int countLine = 1;	 // ���� ���� ��ȣ (1���� ����)
		

		while (std::getline(file, line)) {
			T* tmpData = new T(); // ������ Ŭ������ ��ü ����
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

			// ������ Ŭ���� ��ü�� �����͸� ����
			// T�� BaseData�� ��ӹ޴� Ŭ������ ��ü��, SetData �Լ��� ���ǵǾ� �־�� ��
			tmpData->SetData(row);


			// ����ó��
			// key�� ��������� �������� ���� (��ȣ ����)
			if (!key.empty()) {
				tmpMap[key] = tmpData; // Ű�� ��(�������� ������)�� ���� �ʿ� ����
			}
		}

		file.close();
		return tmpMap; // �ӽ� �� ��ȯ, ��ȯ���� = ���ؼ� �� ����
	}



	// �ֿܼ�
	// ��ü�� �ܼ�â�� ���� �Լ�, Ű�� ���� ���� ����ϴ� �Լ�,
	void PrintMap() {
		for (auto it = DataMap.begin(); it != DataMap.end(); ++it) {
			
			it->second->PrintMap(); // BaseData Ŭ������ PrintMap �Լ� ȣ��
		}
	}
};

