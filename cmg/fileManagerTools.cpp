#include "fileManagerTools.h"

void FileManagerTool::Sacnner()
{
	std::cout << "������Ҫɨ����ļ��У�" << std::endl;
	std::string path;
	getline(std::cin, path);
	_fm.ScanDisk(path);
}

void FileManagerTool::DeletebyMD5()
{
	std::cout << "������Ҫɾ���ļ���MD5ֵ��" << std::endl;
	std::string md5;
	std::cin >> md5;
	_fm.DeleteByMD5(md5);
}

void FileManagerTool::DeletebyName()
{
	std::cout << "������Ҫɾ�����ļ�����" << std::endl;
	std::string f;
	getline(std::cin, f);
	_fm.DeleteByName(f);
}

void FileManagerTool::DeleteAllCopy()
{
	_fm.DeleteAllCopy();
}

//void FileManagerTool::deleteFuzzMatchCopy()
//{
//	std::cout << "������ƥ���ļ�����" << std::endl;
//	std::string match;
//	getline(std::cin, match);
//	_fm.deleteByMatchName(match);
//}

void FileManagerTool::ShowCopy()
{
	_fm.ShowCopyList();
}


void FileManagerTool::ShowAllFiles()
{
	_fm.ShowAllFiles();
}