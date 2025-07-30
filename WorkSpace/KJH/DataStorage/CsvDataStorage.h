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

/*


*/



template<typename T >
class CsvDataStorage {
public:
	CsvDataStorage() {};

	// �Ű�����  : CSV ������ ���, ���� ���� ��ŵ�� ������ ��
	// CSV ������ �о�ͼ� std::unordered_map�� �����ϴ� �Լ�
	// map�� Ű : ù ��° ���� ��(ID), 
	//		 �� : �ش� ���� �����͸� �����ϴ� Ŭ������ ������
	static void SetCSV(const std::string& path, std::unordered_map<std::wstring, T>& outMap) {

		std::wifstream file(path); // ���� ��Ʈ�� ����

		
		if (!file.is_open()) {  // ���� ���� ���� �� ���� �޽��� ���
			//std::cout << "������ �� �� �����ϴ�: " << file << std::endl;
		}

		while (std::getline(file, line)) {
			T tmpData; // ������ Ŭ������ ��ü ����
			//if (countLine++ <= skipLine) continue; // ��� �ǳʶٱ�

			std::wstringstream ss(line);   // ���ڿ� ��Ʈ�� ����
			std::wstring cell;			  // �� ���� ������ ����
			std::vector<std::wstring> row; // ���� ���� ������ ������ ����
			std::wstring key;	          // Ű�� ����� ù ��° ���� ��
			bool isFirst = true;          // ù ��° ������ ���θ� Ȯ���ϴ� �÷���

			while (std::getline(ss, cell, L',')) {
				if (isFirst) {		 // ù ��° ���� Ű�� ���
					key = cell;
					isFirst = false;
				}
				else{
					row.push_back(cell);
				} // ������ ���� ���Ϳ� �߰�
			}

			// ������ Ŭ���� ��ü�� �����͸� ����
			// T�� BaseData�� ��ӹ޴� Ŭ������ ��ü��, SetData �Լ��� ���ǵǾ� �־�� ��
			tmpData.SetData(row);


			// ����ó��
			// key�� ��������� �������� ���� (��ȣ ����)
			if (!key.empty()) {
				outMap[key] = tmpData; // Ű�� ��(�������� ������)�� ���� �ʿ� ����
			}
		}

		file.close();
	}
};

