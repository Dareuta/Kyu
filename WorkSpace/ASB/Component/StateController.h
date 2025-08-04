#pragma once
#include <string>
#include "Components/Base/MonoBehavior.h"
class State {
public:
	State() {};
	~State() {};

	virtual void Onstart() {
		nowTimer = 0.0f;
		isNextState = false;
	};

	virtual void OnExit() {};

	virtual void Update(float deltaTime) {
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
private:
	float ToNextTimer = 0.0f;
	float nowTimer = 0.0f;
	bool  existTransition = false;
	bool  isNextState = false;
};



// ���� state ���� ���
template<typename T>
class StateController : public MonoBehavior {
public:
	StateController() {};
	~StateController() {};

private:
	std::unordered_map<std::string, T*>  StateStorage;
	T* nowState = nullptr;

public:
	//state�� ������
	void CreateState(std::string stateName) {
		T* tmpState = new T();
		StateStorage[stateName] = tmpState;
	}

	//�ܺο��� state ������ �Լ�
	void SetState(std::string stateName) {
		auto it = StateStorage.find(stateName)
			if (it != StateStorage.end()) {
				nowState = it->second;
				nowState->OnStart();  // ����ϱ���, �ʱ�ȭ
			}
	}

	// ���� State ����
	void SetNextState(std::string stateName, std::string NextstateName) {
		State* tmpState = nullptr;
		auto it = StateStorage.find(stateName);
		if (it != StateStorage.end()) {
			tmpState = it->second;
		}

		auto it = StateStorage.find(stateName);
		if (it != StateStorage.end()) {
			tmpState->nextState = it->second;
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
		if (nowState->nextState != " " || nowState->isNextState)
		{
			nowState = nowState->nextState;
		}
	}

	

	void Update(float deltaTime) {
		nowState->Update(deltaTime);
		GoNextState();
	}

	//delete �Լ� �����!!!
};

