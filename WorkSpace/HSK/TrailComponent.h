#pragma once

#include "Components/Rendering/RenderComponent.h"
#include "Platform/D2DRenderManager.h"
#include "Resources/BitmapResource.h"
#include <deque>

/* 07.29. �ѽ±�
* Ʈ���� ������Ʈ
* ������Ʈ�� �ٿ��ָ�, �� ������Ʈ�� ��ǥ�� ��ġ ���Ϸ� ����Ǹ�
* �̹����� �ھƵ�
* ��, �������� ª�� �������� ������ �� ���� ����� ������Ʈ��
* �̹��� ���ҽ����� ������ �������ؼ� ������ ����ü�� ���ӿ�����Ʈ�� ��ü��
*/

struct TrailStamp {
	D2D1_POINT_2F position;
	float angle;
	//float timestamp; // ��ü�� ���� �ð���, ���ǹ� ������ ���� �ð��̶� ���ؼ� �����ϱ� ����
};

class TrailComponent : public RenderComponent
{
public:
	void Update(); // ��� �����Ҷ� �� 
	void AddStamp(D2D1_POINT_2F pos);
	void Draw(D2DRenderManager* manager);
	void Render(D2DRenderManager* manager) override; // �̰� ������� �׷���
	void SetBitmap(std::wstring path);
	void OnDestroy() override;
	void Clear();

	inline float GetAngle(D2D1_POINT_2F prev, D2D1_POINT_2F current) { // ������ǥ�� ������ǥ�� ���ؼ�, ����(radian) ��ȯ����
		return atan2f(current.y - prev.y, current.x - prev.x); // radian
	}

	bool isDraw = false;
	bool wasDraw = false;
	float minDistance = 5.0f; // �ּҰŸ�, �� �������鰣�� ������
	float lifeTime = 0.3f; // �̰��ϴ� ������
	int maxTrailCount = 100;

	std::deque<TrailStamp> trails;
	// ID2D1Bitmap1* stampBitmap = nullptr;
	std::shared_ptr<BitmapResource> stampBitmap = nullptr;
};