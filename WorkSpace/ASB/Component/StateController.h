#pragma once
#include <unordered_map>
#include <string>
#include "Components/Base/MonoBehavior.h"
class State {
public:
	State() {};
	~State() {};

	void OnStart() {
		nowTimer = 0.0f;
		isNextState = false;
	};

	void OnExit() {
		
	};

	void Update(float deltaTime) {
		if (existTransition || nowTimer < ToNextTimer)
			nowTimer += deltaTime;

		else if ( existTransition || nowTimer >= ToNextTimer )
			isNextState = true;
	};

	void SetTransitionTime(int tmpTime) {
		ToNextTimer = tmpTime;
		existTransition = true;
	}


	State* nextState = nullptr;
	std::string stateName;
	float ToNextTimer = 0.0f;
	float nowTimer = 0.0f;
	bool  existTransition = false;
	bool  isNextState = false;
private:
	
};



// ���� state ���� ���
class StateController : public Component {
public:
	StateController() {};
	~StateController() {};

private:
	std::unordered_map<std::string, State*>  StateStorage;
	State* nowState = nullptr;

public:
	//state�� ������
	void CreateState(std::string stateName) {
		State* tmpState = new State();
		StateStorage[stateName] = tmpState;
		tmpState->stateName = stateName;
	}

	//�ܺο��� state ������ �Լ�
	void SetState(std::string stateName) {
		auto it = StateStorage.find(stateName);
		if (it != StateStorage.end()) {
			nowState = it->second;
			nowState->OnStart();  // ����ϱ���, �ʱ�ȭ
		}
	}

	// ���� State ����
	void SetNextState(std::string stateName, std::string NextstateName) {
		State* tmpState = nullptr;
		auto it1 = StateStorage.find(stateName);
		if (it1 != StateStorage.end()) {
			tmpState = it1->second;
		}

		auto it2 = StateStorage.find(stateName);
		if (it2 != StateStorage.end()) {
			tmpState->nextState = it2->second;
		}
	}


	//nextState�� �̵��� Transition ����
	void SetTransitionTime(std::string stateName, int tmpTime) {
		auto it = StateStorage.find(stateName);
		if (it != StateStorage.end()) {
			it->second->SetTransitionTime(tmpTime);
		}
	}

	// ���ο��� transition�� ���� State �� ���� �� �Լ�
	void GoNextState() {
		if (nowState->nextState != nullptr || nowState->isNextState)
		{
			nowState = nowState->nextState;
		}
	}

	// ���� state�� �̸��� return
	std::string GetNowName() {
		return nowState->stateName;
	}
	

	void Update(float deltaTime) {
		nowState->Update(deltaTime);
		GoNextState();
	}

	//delete �Լ� �����!!!
};

