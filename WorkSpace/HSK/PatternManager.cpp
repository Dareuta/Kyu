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

int PatternManager::GetSkippedNode(int from, int to)
{
	int ax = (from - 1) % 3; // ���ο� 0 1 2
	int ay = (from - 1) / 3; // ���ο� 0 1 2 3 ...
	int bx = (to - 1) % 3;
	int by = (to - 1) / 3;

	int mx = (ax + bx) / 2; // x ���̿� ������ ��(�߾�)
	int my = (ay + by) / 2; // y ���̿� ������ ��(�߾�)


	if ((abs(ax - bx) == 2 && ay == by) || // ����, 1 3 ó��, 2ĭ���� ���µ� y ������, 0 2���� ���� �̰͵�
		(abs(ay - by) == 2 && ax == bx) || // ����, 0 1 2 ��, 2 0 ���� ������
		(abs(ax - bx) == 2 && abs(ay - by) == 2) // ��?�� �� �������� ���ÿ� �����ϸ� �밢��, 02 02
		) return my * 3 + mx + 1; // my < ���� , mx < ����

	return -1;
}


void PatternManager::SetPatternBox(const D2D1_RECT_F& box) // �Ⱦ�
{
	patternBox = box;
}

void PatternManager::CheckTrails(const std::deque<TrailStamp>& trails)
{
	pattern.clear();

	int lastHit = -1;

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
				int currentHit = i + 1;

				if (lastHit != -1) { // ù ��尡 �ƴѰ�쿡��
					int skipped = GetSkippedNode(lastHit, currentHit); // �߰����� ������ ��ȯ��, ������ -1
					if (skipped != -1 && !nodes[skipped - 1].isHit) { // �߰� �ƴµ�, ���� �浹�� �ȵǾ�������
						nodes[skipped - 1].isHit = true; //���� ó���ؼ� �־���
						pattern.push_back(skipped);
						std::cout << "[�߰� ��� ������] : " << skipped << std::endl;
					}
				}

				node.isHit = true;
				std::cout << "[��� ���] : " << (i + 1) << std::endl;
				pattern.push_back(i + 1); // 1~9				
				lastHit = currentHit;
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



