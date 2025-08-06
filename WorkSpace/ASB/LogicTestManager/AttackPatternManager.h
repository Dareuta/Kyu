#pragma once
#include <vector>
#include <unordered_map>
#include "Components/Base/MonoBehavior.h"

struct pattern
{
	std::string PattenID;          // �÷������� ������ ����
	float PlayingAttackTime;	   // ���� ��� �ð�
	float TotalPlayingAttackTime;  // �и� ó���� ���� ��ü �ð�
	std::vector<int> NodePatten;   // ������ ���̵� ����
};

class AttackPatternManager : public MonoBehavior
{
public:
	AttackPatternManager() {};
	~AttackPatternManager() {};

	std::unordered_map<std::string, pattern*> NowPatternStorage;

	void OnStart() override;
	void OnUpdate() override;

	void AddPattern(std::string ID, float PlayingAttackTime, std::vector<int> PatternID);
	void SubPattern(std::string ID);

	pattern* CorrectPattern(std::vector<int> PatternID);
	pattern* TimeOutPatten();

private:
};

