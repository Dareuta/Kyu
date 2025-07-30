#pragma once
#include "Components/UI/UIComponent.h"
#include "Components/Rendering/BitmapRenderer.h"
#include <Utils/EventDelegate.h>
#include <string>
#include <functional>

/* 25.07.29 | �ۼ��� : ������
������ ��׶���, ������, ��ư �� 3���� OnStart���� ���
�̹����� �ٲٰ������ Component�� �߰��� SetImage(���) �Լ��� �̹��� ����
***�̶� �̹����� ���μ��� �� �´� �׸��̾���� , ���ҽ� ��û�� �ʼ� ����
��ư�� �ʿ���� �����̴��� ��� ButtShow�� false�� ����
�����̴� �̵��� void ChangeGauge(float x); void ChangeButtonPosition(float x);���� x���� �������� ���������
SetPivotSide�� false�� �����ٶ� �����ʿ��� �������� �þ������ ( ��� �̿ϼ��̶� �Ⱦ��°� ���� )
*/


class Slider : public UIComponent
{
public:
	void OnStart() override;
	void Update() override;	

	/*void SetPivotSide( bool isLeft);*/

	//�̹������� ���� �� �������� �Լ�
	void SetGaugeBackgroundImage(std::wstring path);
	BitmapRenderer* GetGaugeBackgroundImage();
	void SetGaugeBarImage(std::wstring path);
	BitmapRenderer* GetGaugeBarImage();
	void SetGaugeButtonImage(std::wstring path);
	BitmapRenderer* GetGaugeButtonImage();


	//GaugeRect�����Լ�(ù ���� ������ �޾ƿ�)
	void SetGaugeRectValue();
	D2D1_RECT_F GetGaugeRectValue();

	//GaugeRect�����Լ�(������ ����������� ����)
	void ChangeGauge(float x);

	//Button��ġ�����Լ�
	void ChangeButtonPosition(float x);

	//Button�Ⱥ��̴¿뵵(ü�¹�)
	void ButtShow(bool setvalue);

	//�߻�Ŭ���� ��ӹ޾Ƽ� �����ϴ� �Լ�
	virtual bool IsMouseOver(const Vector2& mousePos) const override;

private:
	BitmapRenderer* GaugeBackground{};
	BitmapRenderer* GaugeBar{};
	BitmapRenderer* BarButton{};

	D2D1_RECT_F GaugeBarRect{};

	D2D1_RECT_F ButtonDestRect{};
	D2D1_RECT_F BarButSrctonRect{};

	
	bool HandleValue = true;

	bool pivotIsLeft = true;

};


