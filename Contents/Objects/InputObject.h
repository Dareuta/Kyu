#pragma once
#include "Components/Base/MonoBehavior.h"
#include "Components/Rendering/BitmapRenderer.h"

/* 8.04. �ѽ±�
* ��ǲ �޾Ƽ� ó���ϴ� ������Ʈ
*/

class InputObject : public MonoBehavior
{
public:
	void OnStart() override;
	void OnUpdate() override;
	void OnDestroy() override;	

protected:
		
};

