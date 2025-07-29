#pragma once
#include <iostream>
#include <string>
#include "Components/Base/MonoBehavior.h"
#include "Components/Rendering/AnimationRenderer.h"
#include "Components/Logic/InputSystem.h"
#include "components/Collision/AABBCollider.h"
#include "Components/Physics/Rigidbody2D.h"

/*2025.07.28 - �ȼ���
 �÷��̾  ������ ��ӹ��� �⺻���� ������Ʈ
 ���� ���� : ID, �̸� , ü��, ���ݷ�, �⼼���ݷ�, ȸ����, �����
 ���� �Լ� : 
*/


class LiveObject : public MonoBehavior
{
public:
	LiveObject() {};
	virtual ~LiveObject() {};


public:
	// �� �������� �Լ���
	virtual float GetTotalImbalance() { return 0; }      // �� ��ü���� �� �ɹ� ���� ä���� �θ� ��ü�� �޾ƿ��� ���� �ʿ�!
	std::string GetID() { return Object_ID; }		                // ID ��ȯ
	std::string GetName() { return Object_Name; }				    // �̸� ��ȯ
	float GetHp() { return Object_Hp; }							    // ü�� ��ȯ
	float GetAttack() { return Object_Attack; }						// ���ݷ� ��ȯ
	float GetImbalanceAttack() { return Object_ImbalanceAttack; }   // �⼼ ���ݷ� ��ȯ
	float GetDodgeRate() { return Object_DodgeRate; }     // ȸ���� ��ȯ
	float GetDefenseRate() { return Object_DefenseRate; } // ����� ��ȯ

	// ���� �Լ���
	void SetID(const std::string& id) { Object_ID = id; }			// ID ����
	void SetName(const std::string& name) { Object_Name = name; }	// �̸� ����
	void SetHp(float hp) { Object_Hp = hp; }						// ü�� ����
	void SetAttack(float attack) { Object_Attack = attack; }		// ���ݷ� ����
	void SetImbalanceAttack(float imbalanceAttack) { Object_ImbalanceAttack = imbalanceAttack; } // �⼼ ���ݷ� ����
	void SetDodgeRate(float dodgeRate) { Object_DodgeRate = dodgeRate; }		 // ȸ���� ����
	void SetDefenseRate(float defenseRate) { Object_DefenseRate = defenseRate; } // ����� ����
	
	

	


private: 
	std::string Object_ID; 	      // ID
	std::string Object_Name;      // �̸�
	float Object_Hp;		      // ü��
	float Object_Attack;		  // ���ݷ�
	float Object_ImbalanceAttack; // �⼼ ���ݷ�
	float Object_DodgeRate;       // ȸ����
	float Object_DefenseRate;	  // �����

};

