#include <windows.h>
/// <summary>
/// ���α׷� winMain
/// </summary>
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	CoInitialize(nullptr);  // COM �ʱ�ȭ

	// 25.07.28 - �̼�ȣ
	// ������ Application Ŭ���� ���⿡ �ۼ��ϱ�
	// Fork test comment

	CoUninitialize();        // COM ����
	return (int)1;
}