#pragma once
#include "../BaseData.h"
#include <vector>

/*25.07.29 - �ȼ���
 * ���� :���� ���� ���� �����͸� �����ϴ� Ŭ����
 * �ɹ� : ���� ������ �����ϴ� ����
 * int�� null�� ������ �� �������� 0���� �����!


*/

class EnemyAtkPattenData : public BaseData
{


	void SetData(std::vector<std::wstring> tmp)override; // ������ ���� �Լ�
	void PrintMap()override; // ���� �ܼ�â�� ��� �Լ�, ��ӹ޴� �����Ϳ��� �������̵� �Ͽ� ���
};

