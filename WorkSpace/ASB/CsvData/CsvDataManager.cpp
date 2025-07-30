#include "CsvDataManager.h"

template<typename T, typename U>
U CsvDataManager<T,U>::SetCSV(const std::string& filePath, int skipLine) {
	std::wifstream file(filePath); // ���� ��Ʈ�� ����

	U tmpMap; // �ӽ� �� ����
	if (!file.is_open()) {  // ���� ���� ���� �� ���� �޽��� ���
		//std::cout << "������ �� �� �����ϴ�: " << file << std::endl;
	}


	std::wstring line;	 // ���� ���� ������ ����
	int countLine = 1;	 // ���� ���� ��ȣ (1���� ����)


	while (std::getline(file, line)) {
		T* tmpData = new T(); // ������ Ŭ������ ��ü ����
		if (countLine++ <= skipLine) continue; // ��� �ǳʶٱ�

		std::wstringstream ss(line);   // ���ڿ� ��Ʈ�� ����
		std::wstring cell;			   // �� ���� ������ ����
		std::vector<std::wstring> row; // ���� ���� ������ ������ ����
		std::wstring key;	           // Ű�� ����� ù ��° ���� ��
		bool isFirst = true;           // ù ��° ������ ���θ� Ȯ���ϴ� �÷���

		while (std::getline(ss, cell, L',')) {
			if (isFirst) {		 // ù ��° ���� Ű�� ���
				key = cell;
				isFirst = false;
			}
			row.push_back(cell); // ������ ���� ���Ϳ� �߰�
		}

		// ������ Ŭ���� ��ü�� �����͸� ����
		// T�� BaseData�� ��ӹ޴� Ŭ������ ��ü��, SetData �Լ��� ���ǵǾ� �־�� ��
		tmpData->SetData(row);


		// ����ó��
		// key�� ��������� �������� ���� (��ȣ ����)
		if (!key.empty()) {
			tmpMap[key] = tmpData; // Ű�� ��(�������� ������)�� ���� �ʿ� ����
		}
	}

	file.close();
	return tmpMap; // �ӽ� �� ��ȯ, ��ȯ���� = ���ؼ� �� ����
}


// �ֿܼ�
// ��ü�� �ܼ�â�� ���� �Լ�, Ű�� ���� ���� ����ϴ� �Լ�,
template<typename T, typename U>
void CsvDataManager<T, U>::PrintMap() {
	for (auto it = DataMap.begin(); it != DataMap.end(); ++it) {

		it->second->PrintMap(); // BaseData Ŭ������ PrintMap �Լ� ȣ��
	}
}