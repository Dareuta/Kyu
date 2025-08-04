#include "TestObject.h"
#include "Components/Base/GameObject.h"
#include "Scene/SceneManager.h"

void TestObject::OnStart()
{
	owner->SetRenderLayer(EngineData::RenderLayer::GameObject);

	bitmapRenderer = owner->AddComponent<BitmapRenderer>();
	bitmapRenderer->CreateBitmapResource(L"../WorkSpace/HSK/Test/test2.png");

	bitmapRenderer->SetOrderInLayer(-1); // �̰� �׷� ���߿� ������ ������ �� ���� �� ����Ǵ��� ������

 	size = bitmapRenderer->GetResource()->GetBitmap()->GetSize();

	owner->GetTransform().SetUnityCoords(false);
}

void TestObject::OnUpdate()
{

}

void TestObject::OnDestroy()
{
}


