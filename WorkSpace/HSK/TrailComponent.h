#pragma once

#include "Components/Rendering/RenderComponent.h"

/* 07.29. �ѽ±�
* Ʈ���� ������Ʈ
* ������Ʈ�� �ٿ��ָ�, �� ������Ʈ�� ��ǥ�� ���� �ð�(Ȥ�� ����)���� �����ص�
*
*/

struct TrailStamp {
	D2D1_POINT_2F position;
	float angle;
	float timestamp; // ��ü�� ���� �ð���, ���ǹ� ������ ���� �ð��̶� ���ؼ� �����ϱ� ����
};

class TrailComponent : public RenderComponent
{
public:
	void Update(float currentTime); // �ð�ó���Ҷ��� ��

	void AddStamp(D2D1_POINT_2F pos, float angle, float time);
	void Draw(ID2D1RenderTarget* rt);
	void Render(D2DRenderManager* manager) override; // �̰� ������� �׷���

	inline float GetAngle(D2D1_POINT_2F prev, D2D1_POINT_2F current) { // ������ǥ�� ������ǥ�� ���ؼ�, ����(radian) ��ȯ����
		return atan2f(current.y - prev.y, current.x - prev.x); // radian
	}

	float minDistance = 10.0f; // �ּҰŸ�, �� �������鰣�� ������
	float lifeTime = 0.3f;
	
private:
	std::deque<TrailStamp> trails{};
	ID2D1Bitmap* stampBitmap = nullptr;
};