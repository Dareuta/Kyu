#pragma once
#include <string>
#include "BaseData.h"


/*25.07.29 - �ȼ���
	���� : AllNodePattenClass Ŭ������ ��� ���� �����͸� �����ϴ� Ŭ����
	�ɹ� : ID�� ��� ���ڸ� �����ϴ� ����
	int�� null�� ������ �� �������� 0���� �����!
*/

class AllNodePattenClass : public BaseData 
{
public:
	AllNodePattenClass() {};
	~AllNodePattenClass() {};
	std::string Node_pattern_ID;  // ��� ������ ID�� ����
	std::vector<int> Node_Number; // ��� ������ �����ϴ� ����, �ִ� 9�� ��尡 �� �� ����

	void SetData(std::vector<std::wstring> tmp) override; // ������ ���� �Լ�
	void PrintMap() override; //�ܼ�â�� ������ ��� 
};

