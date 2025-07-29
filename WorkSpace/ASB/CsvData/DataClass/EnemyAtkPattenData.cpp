#include "EnemyAtkPattenData.h"
#include "Utils/StringConvert.h"


void EnemyAtkPattenData::SetData(std::vector<std::wstring> tmp) {
	ePatternID = StringConvert::WstringToString(tmp[0].c_str()); // ���� ���� ���� ID�� ����
	atkPetternGroup = std::stoi(tmp[1]);       // ���� ���� �׷��� ����
	eNodepattern = StringConvert::WstringToString(tmp[2].c_str());;  // ���� ��� ������ ����
	eAtkCoolDown = std::stof(tmp[3].c_str()); // ���� ���� ��Ÿ���� ����
}

void EnemyAtkPattenData::PrintMap() {
	std::cout << "Node_pattern_ID: " << ePatternID << " ";
	std::cout << "atkPetternGroup: " << atkPetternGroup << " ";
	std::cout << "eNodepattern: " << eNodepattern << " ";
	std::cout << "eAtkCoolDown: " << eAtkCoolDown << std::endl;
}