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
	U SetCSV(const std::string& filePath, int skipLine);

	// �ֿܼ�
	// ��ü�� �ܼ�â�� ���� �Լ�, Ű�� ���� ���� ����ϴ� �Լ�
	void PrintMap();
};

