#include "MouseTrailObject.h"
#include "Components/Base/GameObject.h"
// Components
#include "../Engine/Components/Rendering/PatternDrawerComponent.h"
#include "../Engine/Components/Rendering/TrailComponent.h"
#include "../Engine/Components/Logic/InputSystem.h"

void MouseTrailObject::OnStart()
{
	owner->SetRenderLayer(EngineData::RenderLayer::UI);	
	auto t = owner->AddComponent<TrailComponent>();	
	auto d = owner->AddComponent<PatternDrawerComponent>();
	
	d->SetOrderInLayer(80);
	d->SetBitmap(L"../WorkSpace/HSK/Test/test5.png");

	t->SetOrderInLayer(100);	
	t->SetBitmap(L"../WorkSpace/HSK/Test/test5.png");
	t->SetTailBitmap(L"../WorkSpace/HSK/Test/test1.png");
	t->SetHeadBitmap(L"../WorkSpace/HSK/Test/white_brush_test3.png");	
}

void MouseTrailObject::OnUpdate()
{	
	auto t = owner->GetComponent<TrailComponent>();
	t->isDraw = Input::leftButtonDown; //��Ŭ���� �׸��� ����
	owner->GetTransform().SetPosition(Input::MouseX, Input::MouseY); // ���콺 ��ǥ ����(Ʈ������ ���󰡴� ��)	
}

void MouseTrailObject::OnDestroy()
{
}


