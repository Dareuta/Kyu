#include "TrailComponent.h"
#include "Components/Camera/Camera.h"
#include "Scene/SceneManager.h"

#include "Utils/GameTime.h"
#include "Datas/SpriteDatas.h"
#include "Utils/DebugUtility.h"
#include "Resources/ResourceManager.h"

/* ��� ����(���콺 ���󰡰� ����)
#include "Components/Logic/InputSystem.h"
#include "Components/Rendering/TrailComponent.h"

Enter
	auto t = obj->GetComponent<TrailComponent>();
	t->isDraw = Input::leftButtonDown;
	t->isOutFromBox = Input::rightButtonDown;
	obj->GetTransform().SetPosition(Input::MouseX, Input::MouseY);

Update
	auto t = obj->GetComponent<TrailComponent>();
	t->isDraw = Input::leftButtonDown;
	t->isOutFromBox = Input::rightButtonDown;
	obj->GetTransform().SetPosition(Input::MouseX, Input::MouseY);
*/

constexpr float PI = 3.141592654f; // �� ���ڴ� ������ ���̶�°���

void TrailComponent::Update() { // ���⼭ ����(����)ó�����ָ� ��
	while (trails.size() > maxTrailCount && isOutFromBox) { // �ִ� �������� ����, ���߿� �����߰��ϸ� ��
		trails.pop_front();
	}

	if (wasDraw && !isDraw) { // ���Ļ��� true + ������� false, �� ������ �ѹ�
		Clear();
	}
	wasDraw = isDraw;
}

void TrailComponent::Clear()
{
	trails.clear();
}

void TrailComponent::AddStamp(D2D1_POINT_2F pos) {
	if (!isDraw) return; // �÷��� �� ����

	if (trails.empty()) { // ù ��Ҵ� �ٷ� ó���ع���, ������ ���� ����� �ʿ� �����ϱ�
		trails.push_back({ pos, 0.0f });
		return;
	}

	const TrailStamp& last = trails.back(); // ����ü�� ������, ť�� ���� �ֱٻ��ԵȰ� ��������
	float dx = pos.x - last.position.x; // ��ȭ����, x������
	float dy = pos.y - last.position.y; // y������
	float dist = sqrtf(dx * dx + dy * dy); // �����ؼ� ���ѵ� ��Ʈ ����, �� �Ÿ���

	if (dist < minDistance) // �����Ÿ� ���ϸ� ��������,
		return;

	int steps = static_cast<int>(dist / minDistance); //�ּҰŸ��� ���� ���ݿ� ��������� Ȯ���ϴ°���
													  //(�ּҰŸ����� Ŀ�� �����Ǵϱ� �⺻������ 1 �̻��� + int�� ������)
	for (int i = 1; i <= steps; ++i) {
		float t = static_cast<float>(i) / steps; // ������, t + 1/t
		D2D1_POINT_2F interpPos = { // �������� �߰� �� ��������, ��ȭ��(����)����
			last.position.x + dx * t, // �������� ��ȭ����ŭ �̵� * ����ġ
			last.position.y + dy * t 
		};

		float angle = (i == 1) // ù��° ��Ҹ�
			? GetAngle(last.position, interpPos) // ���������� ���� ���
			: GetAngle(trails.back().position, interpPos); // �ƴϸ� ������ �߰��ȰŶ� ���� ���
		trails.push_back({ interpPos, angle }); // ť�� �������, ���߿� draw���� ��ǥ + ���� ������� �׷���
	}
}

void TrailComponent::Draw(D2DRenderManager* manager) { // ���������� �׸��� �κ�
	if (!stampBitmap) return; // ��Ʈ�� ��� ���ϸ� �ȱ׸�

	for (auto& stamp : trails) { // ť ��ü�� ��ȸ�ϸ鼭
		D2D1_SIZE_F bmpSize = stampBitmap->GetBitmap()->GetSize(); // ������ ���� ���ؼ� �߾ӱ�������
		D2D1_RECT_F destRect = { // ���� �̹��� �� ��� ����
		 stamp.position.x - bmpSize.width * 0.5f,
		 stamp.position.y - bmpSize.height * 0.5f,
		 stamp.position.x + bmpSize.width * 0.5f,
		 stamp.position.y + bmpSize.height * 0.5f,
		};

		D2D1::Matrix3x2F transform = D2D1::Matrix3x2F::Rotation( // ȸ����� ����
			stamp.angle * 180.0f / PI,
			stamp.position
		);

		manager->SetBitmapTransform(transform); // ȸ����� ����
		
		D2D1_RECT_F srcRect = { // �̰� �԰� ������� �ٲ��ִ°���
			0.0f, 0.0f,
			bmpSize.width, bmpSize.height
		};

		manager->DrawBitmap(stampBitmap->GetBitmap(), destRect, srcRect); // ��ο� ��Ʈ���� ���� ȣ������
	}
}

void TrailComponent::Render(D2DRenderManager* manager)
{
	Update(); // ���⼭�� ���� ���� �Ǵ���
	auto tf = owner->GetTransform().GetPosition(); // ������Ʈ�� �پ��ִ� ������ ��ǥ�� �޾Ƽ�
	AddStamp({ tf.x, tf.y }); // ������ �߰� �õ�, ��ǥ�� �������(����ġ �̻�����) �������� ������ 
	Draw(manager); 

}

void TrailComponent::SetBitmap(std::wstring path) // �����Ѱ���
{
	stampBitmap = resourceManager->CreateBitmapResource(path);
}

void TrailComponent::OnDestroy() // �ƹ�ư �ʿ���
{
	stampBitmap.reset(); // �����߽��ϴ� 20:30 
}
