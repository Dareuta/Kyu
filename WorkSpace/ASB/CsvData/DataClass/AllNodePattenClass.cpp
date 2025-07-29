#include "AllNodePattenClass.h"
#include "Utils/StringConvert.h"



//BaseData Ŭ������ �Լ��� �������̵� �Ͽ� ����ϴ� �Լ�
//�ش� �ڷ����� �����͸� �����ϴ� �Լ�
void AllNodePattenClass::SetData(std::vector<std::wstring> tmp) {
	Node_pattern_ID = StringConvert::WstringToString(tmp[0].c_str());
	for (int i = 1; i < 10; i++) { //�Ŀ� �̻��� ������ ������ ��쵵 �������� 9���� ����(�ϵ��ڵ�)

		// tmp[i]�� null�� ���� 0���� ����
		if (tmp[i] == L"null") {
			Node_Number.push_back(0);
		}

		//null�� �ƴϸ� wstring�� int ������ ����
		else {
			Node_Number.push_back(std::stoi(tmp[i])); //Ŭ������ ���Ϳ� ���� ����� ���͸� ���ڷ� ��ȯ�Ͽ� ����
		}
	}
}

void AllNodePattenClass::PrintMap() {
	std::cout << "Node_pattern_ID: " << Node_pattern_ID << " ";
	for (const auto& num : Node_Number) {
		std::cout << num << " ";
	}
	std::cout << std::endl;
}