#include "PatternManager.h"
#include "Components/Base/GameObject.h"
#include "Components/Rendering/BitmapRenderer.h"


void PatternManager::SetNodes(const std::array<GameObject*, 9>& positions, float radius)
{
	Vector2 minNode{ FLT_MAX, FLT_MAX }; //�ذ�?�̶����
	Vector2 maxNode{ -FLT_MAX, -FLT_MAX };


	for (int i = 0; i < 9; ++i) {
		auto bmpSize = positions[i]->GetComponent<BitmapRenderer>()->GetResource()->GetBitmap()->GetSize();
		Vector2 mat = positions[i]->GetTransform().GetPosition();

		Vector2 offset = { bmpSize.width * 0.5f, bmpSize.height * 0.5f };
		Vector2 center = mat + offset;

		nodes[i].position = center; //�񱳿����� ��� ����
		nodes[i].radius = radius;
		nodes[i].isHit = false; // �ʱ�ȭ,

		std::cout << nodes[i].position << std::endl;

		if (center.x < minNode.x) minNode.x = center.x; // �ּҳ�庸�� �������ϰ��, ����
		if (center.y < minNode.y) minNode.y = center.y;

		if (center.x > maxNode.x) maxNode.x = center.x; // �ִ��庸�� ū ���ϰ�� ����
		if (center.y > maxNode.y) maxNode.y = center.y;
	}

	float padding = radius * 1.5f;

	patternBox = {
		minNode.x - padding,
		minNode.y - padding,
		maxNode.x + padding,
		maxNode.y + padding
	};
}

void PatternManager::AddNodes(Vector2 pos, float radius, int i)
{
	nodes[i].position = pos;
	nodes[i].radius = radius;
	nodes[i].isHit = false; // �ʱ�ȭ,
}


void PatternManager::SetPatternBox(const D2D1_RECT_F& box) // �Ⱦ�
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
				std::cout << "[DEBUG] pushing pattern index: " << (i + 1) << std::endl;
				pattern.push_back(i + 1); // 1~9				
			}
		}
	}

	for (int i = 0; i < 9; ++i) {
		nodes[i].isHit = false; // �ʱ�ȭ,
	}
}

bool PatternManager::CheckOutOfBox(Vector2 pos) // AABB < ���콺 ���������� �Ǵ����ָ� �����
{
	return (pos.x < patternBox.left || pos.x > patternBox.right ||
		pos.y < patternBox.top || pos.y > patternBox.bottom);
}



