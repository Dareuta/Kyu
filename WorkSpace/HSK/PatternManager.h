#pragma once
#include "Components/Rendering/TrailComponent.h"
#include "Components/Logic/InputSystem.h"
#include <array>

/* 7.30. �ѽ±�
* ���(9��)��, ���� Ʈ���� ������Ʈ�� ���� ������ �浹���θ� Ȯ���ؼ�
* �����(� ��带 ���-�浹 �Ͽ�����)�� ��ȯ���ִ� �Ŵ���
* ��, 1 3 2 �̷������� �迭�� ���� ������
* + �߰�������, ���� ����(�簢��) ������ ������ �Ǵ��ؼ�
* Ʈ������ �����ִ�(���ҽ�Ű��) �÷��׸� Ű�� ���ҵ���
* ���� ���õ� ������ ���⼭ ó���� ����
*/

/* ��� 1 : ��ϵ� ���(9��)��, �Էµ� ť(cachedTrails) �浹ó�� (�浹 ����)�� �迭(ť)�� ���� ��ȯ ex) 1 3 2 4 5 6 8
*  ��� 2 : ��ϵ� �ڽ�(���� ũ��) ������ ���콺�� �����°� �����ϸ�, �÷��׺�ȯ����
*/

struct Node {
	Vector2 position;
	float radius;
	bool isHit = false;
};

class PatternManager {
public:
	void SetNodes(const std::array<GameObject*, 9>& positions, float radius); // �ִ� �ּ� ũ�⸦ ����س��ٰ�, AABB �ڽ� ������ִ� ��ɵ� ���Ե�
	void SetPatternBox(const D2D1_RECT_F& box);
	void CheckTrails(const std::deque<TrailStamp>& trails);
	bool CheckOutOfBox(Vector2 pos);
	void AddNodes(Vector2 pos, float radius, int i);
	int GetSkippedNode(int from, int to); // �� ����, �߰��� ��尡 ��ŵ�Ǿ��� ���ɼ��� �Ǵ�

	const std::deque<int>& GetPattern() const {
		return pattern;
	}	
private:
	std::array<Node, 9> nodes;
	std::deque<int> pattern;
	D2D1_RECT_F patternBox = { 0,0,0,0 };
};
