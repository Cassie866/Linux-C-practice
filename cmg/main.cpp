#include "fileManagerTools.h"

void menu()
{
	std::cout << "******************************" << std::endl;
	std::cout << "1ɨ��      2showall     3showcopy    4nameɾ��      5md5ɾ��     6ȫɾ    0�˳�" << std::endl;
}


void testFileManagerTool()
{
	FileManagerTool fmt;
	int input;
	do
	{
		menu();
		std::string garbage;
		std::cout << "������ѡ��";
		std::cin >> input;
		getline(std::cin, garbage);
		switch (input)
		{
		case 1:
			fmt.Sacnner();
			break;
		case 2:
			fmt.ShowAllFiles();
			break;
		case 3:
			fmt.ShowCopy();
			break;
		case 4:
			fmt.DeletebyName();
			break;
		case 5:
			fmt.DeletebyMD5();
			break;
		case 6:
			fmt.DeleteAllCopy();
			break;
		case 0:
			break;
		default:
			break;
		}
	} while (input != 0);
}


int main()
{
	testFileManagerTool();
	return 0;
}
