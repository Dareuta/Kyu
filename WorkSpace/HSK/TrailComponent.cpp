#include "TrailComponent.h"
#include "Components/Camera/Camera.h"
#include "Scene/SceneManager.h"

#include "Utils/GameTime.h"
#include "Datas/SpriteDatas.h"
#include "Utils/DebugUtility.h"
#include "Resources/ResourceManager.h"

constexpr float PI = 3.141592654f;

void TrailComponent::Update() {

}

void TrailComponent::AddStamp(D2D1_POINT_2F pos) {

	if (trails.empty()) { // ù ��Ҵ� �ٷ� ó���ع���
		trails.push_back({ pos, 0.0f });
		return;
	}

	const TrailStamp& last = trails.back(); // ����ü�� ������
	float dx = pos.x - last.position.x;
	float dy = pos.y - last.position.y;
	float dist = sqrtf(dx * dx + dy * dy); // �����ؼ� ���ѵ� ��Ʈ

	if (dist < minDistance) // �����Ÿ� ���ϸ� ��������
		return;

	int steps = static_cast<int>(dist / minDistance); //�ּҰŸ��� ��������� Ȯ���ϴ°���(������ ũ�� ������ 1�̻���)
	for (int i = 1; i <= steps; ++i) {
		float t = static_cast<float>(i) / steps; // ������, t + 1/t
		D2D1_POINT_2F interpPos = {
			last.position.x + dx * t,
			last.position.y + dy * t
		};

		float angle = (i == 1) // ù��° ��Ҹ�
			? GetAngle(last.position, interpPos) // ����������
			: GetAngle(trails.back().position, interpPos); // �ƴϸ� ������ �߰��ȰŶ�
		trails.push_back({ interpPos, angle });
	}
}

void TrailComponent::Draw(D2DRenderManager* manager) {
	if (!stampBitmap) return;

	for (auto& stamp : trails) { 
		D2D1_SIZE_F bmpSize = stampBitmap->GetBitmap()->GetSize();
		D2D1_RECT_F destRect = { // ���� �̹��� �� ��� ����
		 stamp.position.x - bmpSize.width * 0.5f,
		 stamp.position.y - bmpSize.height * 0.5f,
		 stamp.position.x + bmpSize.width * 0.5f,
		 stamp.position.y + bmpSize.height * 0.5f,
		};

		D2D1::Matrix3x2F transform = D2D1::Matrix3x2F::Rotation(
			stamp.angle * 180.0f / PI,
			stamp.position
		);

		manager->SetBitmapTransform(transform);
		D2D1_RECT_F srcRect = {
			0.0f, 0.0f,
			bmpSize.width, bmpSize.height
		};
		manager->DrawBitmap(stampBitmap->GetBitmap(), destRect, srcRect);
	}	
}

void TrailComponent::Render(D2DRenderManager* manager)
{
	auto tf = owner->GetTransform().GetPosition();
	AddStamp({ tf.x, tf.y });
	Draw(manager);
	Update();
}

void TrailComponent::SetBitmap(std::wstring path)
{
	stampBitmap = resourceManager->CreateBitmapResource(path);
}

void TrailComponent::OnDestroy()
{
	stampBitmap.reset(); // �����߽��ϴ� 20:30 
}
