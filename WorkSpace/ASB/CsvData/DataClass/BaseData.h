#pragma once
#include <vector>
#include <string>
/* 2025.07.29 - �ȼ���
	BaseData Ŭ������ ���� ������ ������ ������ �⺻ Ŭ����

	���� : ������ �������� int�� null�� ������ �� �������� 0���� �����!
*/

class BaseData
{
public :
	BaseData() {};
	virtual ~BaseData() {};

public:
	// ���� ���� �Լ� ����
	virtual void SetData(std::vector<std::wstring> tmp)  = 0; // ������ ���� �Լ�
	virtual void PrintMap()  = 0; // ���� �ܼ�â�� ��� �Լ�, ��ӹ޴� �����Ϳ��� �������̵� �Ͽ� ���
	
};

