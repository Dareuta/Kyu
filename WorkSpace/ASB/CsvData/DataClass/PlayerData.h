#pragma once
#include "BaseData.h"

class PlayerData : public BaseData
{
public:
	PlayerData() {};
	~PlayerData() {};

	void SetData(std::vector<std::wstring> tmp)override; // ������ ���� �Լ�
	void PrintMap()override; // ���� �ܼ�â�� ��� �Լ�, ��ӹ޴� �����Ϳ��� �������̵� �Ͽ� ���
};

