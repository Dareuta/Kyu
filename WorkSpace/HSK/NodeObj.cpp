#include "NodeObj.h"
#include "Scene/SceneManager.h"
#include "Utils/GameTime.h"
#include "Components/Base/GameObject.h"
#include "Components/Collision/CircleCollider.h"

void Node::OnStart()
{
	owner->SetRenderLayer(EngineData::RenderLayer::GameObject);
	bitmapRenderer = owner->AddComponent<BitmapRenderer>();
	bitmapRenderer->CreateBitmapResource(L"../HSK/Test/test2.png");
	bitmapRenderer->SetOrderInLayer(-1); // �̰� �׷� ���߿� ������ ������ �� ���� �� ����Ǵ��� ������

	auto c = owner->AddComponent<CircleCollider>();




}

void Node::OnUpdate()
{

}

void Node::OnDestroy()
{
}

