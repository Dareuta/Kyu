#include "PatternManager.h"
#include "Components/Base/GameObject.h"
#include "Components/Rendering/BitmapRenderer.h"


void PatternManager::SetNodes(const std::array<GameObject*, 9>& positions, float radius)
{	
	for (int i = 0; i < 9; ++i) {		
		auto bmpSize = positions[i]->GetComponent<BitmapRenderer>()->GetResource()->GetBitmap()->GetSize();
		Vector2 mat = positions[i]->GetTransform().GetPosition();
		
		Vector2 offset = { bmpSize.width * 0.5f, bmpSize.height * 0.5f };

		nodes[i].position = mat + offset;
		
		nodes[i].radius = radius;
		nodes[i].isHit = false; // �ʱ�ȭ,

		std::cout << nodes[i].position<<std::endl;
	}
}

void PatternManager::AddNodes(Vector2 pos, float radius, int i)
{
	nodes[i].position = pos;
	nodes[i].radius = radius;
	nodes[i].isHit = false; // �ʱ�ȭ,
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
				std::cout << "[DEBUG] pushing pattern index: " << (i + 1) << std::endl;
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



