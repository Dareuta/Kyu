#pragma once
#include "BaseData.h"

/*2025.07.29 - �ȼ���

    ���� : ���� ������ �ҷ��� ��, �ʿ��� ID�� �ٸ��ų� �ٸ����� �������ε� �� �� ���� -> ���� ��������
*/ 
class EnemyData : public BaseData
{
public:
	EnemyData() {};
	~EnemyData() {};
	std::string enemyID;          // ���� ID�� ����
	std::string enemyName;        // ���� �̸��� ����
	std::string enemyDifficulty;  // ���� ���̵��� ����   <- �߿�!
	float enemyHealth;            // ���� ���ݷ��� ����
	float enemyDamage;            // ���� ������ ����
	float enemyCooldown;          // ���� ���� ��Ÿ���� ����
	float enemySpiritdamage;      // ���� �⼼ ���ݷ��� ����
	float enemySpiritamount;	  // �⼼�� �ѷ��� ����   <- �߿�!
	float eMoveSpeed;         // ���� �̵� �ӵ��� ����
	void SetData(std::vector<std::wstring> tmp) override; // ������ ���� �Լ�
	void PrintMap() override; // �ܼ�â�� ������ ���
};

