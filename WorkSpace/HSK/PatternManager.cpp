#include "PatternManager.h"

void PatternManager::SetNodes(const std::array<Vector2, 9>& positions, float radius)
{
	for (int i = 0; i < 9; ++i) {
		nodes[i].position = positions[i];
		nodes[i].radius = radius;
		nodes[i].isHit = false; // �ʱ�ȭ,
	}
}

void PatternManager::SetPatternBox(const D2D1_RECT_F& box)
{
	patternBox = box;
}

void PatternManager::CheckTrails(const std::deque<TrailStamp>& trails)
{
	pattern.clear();

	for (auto stamp : trails) { // Ʈ���� �ȿ� �ִ°͵�, ���´� TrailStamp
		Vector2 pos = { stamp.position.x, stamp.position.y };

		for (int i = 0; i < 9; ++i) {

			auto& node = nodes[i]; // Node ����ü

			if (node.isHit) continue; // �̹� �����Ѱ� �ǳʶ�

			float dx = pos.x - node.position.x; // x�� ����
			float dy = pos.y - node.position.y; // y�� ����
			float distSq = dx * dx + dy * dy; // ��Ÿ���
			float radiusSq = node.radius * node.radius; // �������� ���� // ��ǻ� ���� �Ÿ��� ���������� ���� �ָ��� �� ����

			if (distSq <= radiusSq) { // �浹 ����
				node.isHit = true; 
				pattern.push_back(i + 1); // 1~9				
			}
		}
	}

	for (int i = 0; i < 9; ++i) {
		nodes[i].isHit = false; // �ʱ�ȭ,
	}
}

void PatternManager::CheckOutOfBox(Vector2 pos) // AABB < ���콺 ���������� �Ǵ����ָ� �����
{
	if (pos.x < patternBox.left || pos.x > patternBox.right || pos.y < patternBox.top || pos.y > patternBox.bottom)
		isMousOut = true;
	else
		isMousOut = false;
}


