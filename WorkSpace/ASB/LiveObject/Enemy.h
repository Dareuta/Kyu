#pragma once
#include "LiveObject.h"

class Enemy : public LiveObject
{
public:
	Enemy() {};
	~Enemy() {};
public:
	float GetTotalImbalance() override { return TotalImbalance; };
	std::string GetDifficulty() override { return Difficulty; } // ���̵� ��ȯ

private:
	float TotalImbalance = 0.0f; // ���� �� ä��
	std::string Difficulty;       // ���� ���̵� 
};

