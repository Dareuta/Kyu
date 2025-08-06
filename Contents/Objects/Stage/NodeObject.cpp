#include "NodeObject.h"
#include "Components/Base/GameObject.h"
#include "Components/Collision/CircleCollider.h"

/* 8.05. �ѽ±�
* ����Ƽ ��ǥ��� ���������
* ���ԵǸ� ���� ��ο� ������Ʈ ���� ��������
* ���� �ٲ���ؼ�
* ������ UI�ϱ� ��Ե� ���� ������
*/
void NodeObject::OnCreate() {
	owner->SetRenderLayer(EngineData::RenderLayer::GameObject);
	owner->GetTransform().SetUnityCoords(false); // �̰� ����Ƽ��ǥ�� �ϸ� �ȴ�

	bitmapRenderer = owner->AddComponent<BitmapRenderer>();
	bitmapRenderer->CreateBitmapResource(L"../WorkSpace/HSK/Test/ui03.png");
	bitmapRenderer->SetOrderInLayer(-1);

	size = bitmapRenderer->GetResource()->GetBitmap()->GetSize();
	owner->GetTransform().SetOffset(-size.width / 2, size.height / 2);
	auto c = owner->AddComponent<CircleCollider>();

}

void NodeObject::OnStart()
{
	
		
}

void NodeObject::OnUpdate()
{

}

void NodeObject::OnDestroy()
{
}


