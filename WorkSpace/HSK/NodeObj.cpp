#include "NodeObj.h"
#include "Scene/SceneManager.h"
#include "Utils/GameTime.h"
#include "Components/Base/GameObject.h"
#include "Components/Collision/CircleCollider.h"

void NodeObj::OnStart()
{
	owner->SetRenderLayer(EngineData::RenderLayer::GameObject);
	bitmapRenderer = owner->AddComponent<BitmapRenderer>();
	bitmapRenderer->CreateBitmapResource(L"../HSK/Test/ui03.png");
	bitmapRenderer->SetOrderInLayer(-1); // �̰� �׷� ���߿� ������ ������ �� ���� �� ����Ǵ��� ������
	size = bitmapRenderer->GetResource()->GetBitmap()->GetSize(); 
	auto c = owner->AddComponent<CircleCollider>();
	owner->GetTransform().SetUnityCoords(false);
}

void NodeObj::OnUpdate()
{

}

void NodeObj::OnDestroy()
{
}


