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

struct TrailStamp { // ���ӿ�����Ʈ�� ��ü�ϴ� ����ü, ������ ��Ʈ�� ������Ʈ�� �䱸�ϱ� ������ ������ ���
	D2D1_POINT_2F position; // ��ǥ
	float angle; // ����(��� �ؾ���)

	float timestamp; // ��� ��� ����
};

class TrailComponent : public RenderComponent
{
public:
	void Update(); // ��� ���� + �÷��� ó����

	void AddStamp(D2D1_POINT_2F pos);
	void Draw(D2DRenderManager* manager); // �ѹ� ���Ѱ���, ���⼭ for ������ ��Ʈ�� ����
	void Render(D2DRenderManager* manager) override; // �̰� ������� �׷���
	void SetBitmap(std::wstring path);
	void OnDestroy() override;
	void Clear(); // �ѹ��� ����°���, ť ���

	inline float GetAngle(D2D1_POINT_2F prev, D2D1_POINT_2F current) { // ������ǥ�� ������ǥ�� ���ؼ�, ����(radian) ��ȯ����
		return atan2f(current.y - prev.y, current.x - prev.x); // radian
	}

	bool isDraw = false; // OnOff��
	bool wasDraw = false; // isDraw�� �ѹ� �����ص״ٰ� ����, �� ���������� ã�� �񱳿� ����
	bool isOutFromBox = true; // ���������� ������ true, �ڿ� ũ�⸦ �ڸ�

	float minDistance = 5.0f; // �ּҰŸ�, �� �������鰣�� ������ �����ϸ� �ε巯����
	float lifeTime = 0.3f; // �̰��ϴ� ������, ���߿� update���� �ð� ������ ó���ϴ½����� ������
	int maxTrailCount = 100; // �ִ� ����, ������ ��Ʈ���� ����


	std::deque<TrailStamp> cachedTrails; // �̰� �������(������) - ������ �����Ǳ�����
	// ID2D1Bitmap1* stampBitmap = nullptr;
private:
	std::deque<TrailStamp> trails; // ť, ���⿡ ����ü ���(��ǥ, ����, ����)
	std::shared_ptr<BitmapResource> stampBitmap = nullptr; // ���� ��Ʈ��, �귯�� ������ ��
};