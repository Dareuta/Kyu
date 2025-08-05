#include "NodeObject.h"
#include "Components/Base/GameObject.h"
#include "Components/Collision/CircleCollider.h"

void NodeObject::OnStart()
{
	owner->SetRenderLayer(EngineData::RenderLayer::GameObject);
	owner->GetTransform().SetUnityCoords(false);

	bitmapRenderer = owner->AddComponent<BitmapRenderer>();
	bitmapRenderer->CreateBitmapResource(L"../WorkSpace/HSK/Test/ui03.png");

	bitmapRenderer->SetOrderInLayer(-1); // �̰� �׷� ���߿� ������ ������ �� ���� �� ����Ǵ��� ������

	size = bitmapRenderer->GetResource()->GetBitmap()->GetSize();			
	auto c = owner->AddComponent<CircleCollider>();
	
}

void NodeObject::OnUpdate()
{

}

void NodeObject::OnDestroy()
{
}


