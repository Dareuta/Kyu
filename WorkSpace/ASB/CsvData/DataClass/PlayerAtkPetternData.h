#pragma once
#include "BaseData.h"

class PlayerAtkPetternData : public BaseData
{
public:
	PlayerAtkPetternData() {};
	~PlayerAtkPetternData() {};

	void SetData(std::vector<std::wstring> tmp)override; // ������ ���� �Լ�
	void PrintMap()override; // ���� �ܼ�â�� ��� �Լ�, ��ӹ޴� �����Ϳ��� �������̵� �Ͽ� ���
};

