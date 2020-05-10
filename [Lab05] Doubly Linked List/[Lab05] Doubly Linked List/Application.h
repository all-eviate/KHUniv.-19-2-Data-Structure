#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "DoublySortedLinkedList.h"


#define FILENAMESIZE 1024

/**
*	�������� �����ϱ� ���� Application Ŭ����.
*/
class Application
{
public:
	/**
	*	����Ʈ ������.
	*/
	Application()
	{
		m_Command = 0;
	}

	/**
	*	�Ҹ���.
	*/
	~Application() {}

	/**
	*	@brief	���α׷��� �����Ѵ�.
	*	@pre	���α׷��� �����Ѵ�.
	*	@post	���α׷��� ������.
	*/
	void Run();

	/**
	*	@brief	command�� ��ũ���� ����ϰ� Ű����κ��� command�� �Է¹޴´�.
	*	@pre	����.
	*	@post	����.
	*	@return	������ command.
	*/
	int GetCommand();

	/**
	*	@brief	���ο� �������� ������ ����Ʈ�� �߰��Ѵ�.
	*	@pre	����Ʈ�� �ʱ�ȭ�Ǿ�� �Ѵ�.
	*	@post	����Ʈ�� �� �������� ������ �߰��ȴ�.
	*	@return	�Լ��� �� �۵��ϸ� 1�� �����ϰ�, �׷��� ������ 0�� �����Ѵ�.
	*/
	int AddItem();

	/**
	*	@brief	����Ʈ�� ��� ������ �������� ��ũ���� ����Ѵ�.
	*	@pre	����.
	*	@post	����.
	*/
	void DisplayAllItem();

	/**
	*	@brief	������ �ҷ��� ������ ���� ��ũ��Ʈ�� �̿��� ����.
	*	@pre	������ �ҷ��� ������ �����ؾ��Ѵ�.
	*	@post	�б� ���� ������ ����.
	*	@param	fileName	������ �ҷ����� ���� ���� ������ �̸�.
	*	@return	�Լ��� �� �۵��ϸ� 1�� �����ϰ�, �׷��� ������ 0�� �����Ѵ�.
	*/
	int OpenInFile(char* fileName);

	/**
	*	@brief	������ ������ ������ ���� ��ũ��Ʈ�� �̿��� ����.
	*	@pre	����Ʈ�� �ʱ�ȭ�Ǿ��־�� �Ѵ�.
	*	@post	���� ���� ������ ����.
	*	@param	fileName	������ ���� ���� ���� ������ �̸�.
	*	@return	�Լ��� �� �۵��ϸ� 1�� �����ϰ�, �׷��� ������ 0�� �����Ѵ�.
	*/
	int OpenOutFile(char* fileName);

	/**
	*	@brief	�б� ���� ������ ���� ���Ͽ� �ִ� ��� �����͸� �ҷ����� �����͵�� ����Ʈ�� �����.
	*	@pre	������ �������� �ʴ�.
	*	@post	����Ʈ�� ������ ��� ������ �������� �ִ´�.
	*	@return	�Լ��� �� �۵��ϸ� 1�� �����ϰ�, �׷��� ������ 0�� �����Ѵ�.
	*/
	int ReadDataFromFile();

	/**
	*	@brief	O���� ���� ������ ���� ����Ʈ�� ��� �������� �����Ѵ�.
	*	@pre	������ �������� �ʴ�.
	*	@post	�����ϴ� ���Ͽ� ����Ʈ�� ����ȴ�.
	*	@return	�Լ��� �� �۵��ϸ� 1�� �����ϰ�, �׷��� ������ 0�� �����Ѵ�.
	*/
	int WriteDataToFile();

	/**
	*	@brief	�Է¹��� ID�� ������ ������ ã�Ƴ��� ��ũ���� ����Ѵ�.
	*	@pre	����Ʈ�� �����۵��� ������ ����Ǿ� �ִ�.
	*	@post	����Ʈ���� �������� ã�� ����Ѵ�.
	*	@return	�Լ��� �� �۵��ϸ� 1�� �����ϰ�, �׷��� ������ 0�� �����Ѵ�.
	*/
	int SearchItembyID();

	/**
	*	@brief	����Ʈ�� ����.
	*	@pre	����Ʈ�� �����۵��� ������ ����Ǿ� �ִ�.
	*	@post	����Ʈ�� �������.
	*/
	void MakeEmptyList();

	/**
	*	@brief	�Է¹��� ID�� �������� ã�Ƴ��� �����Ѵ�.
	*	@pre	����Ʈ�� �����۵��� ������ ����Ǿ� �ִ�.
	*	@post	����Ʈ���� �������� ã�� �����Ѵ�.
	*	@return	�Լ��� �� �۵��ϸ� 1�� �����ϰ�, �׷��� ������ 0�� �����Ѵ�.
	*/
	int DeleteItem();

	/**
	*	@brief	�Է¹��� ID�� ������ ������ ã�Ƴ��� �����Ѵ�.
	*	@pre	����Ʈ�� �����۵��� ������ ����Ǿ� �ִ�.
	*	@post	����Ʈ���� �������� ã�� ������ �����Ѵ�.
	*	@return	�Լ��� �� �۵��ϸ� 1�� �����ϰ�, �׷��� ������ 0�� �����Ѵ�.
	*/
	int UpdateInfo();

	/**
	*	@brief	�̸��� �Է¹޾� �� ������ ��ȯ�Ѵ�.
	*	@pre	����.
	*	@post	�̸��� �Է¹��� ������ ��ȯ�ȴ�.
	*	@return	�Էµ� �̸��� ��ü�� ��ȯ�Ѵ�.
	*/
	ItemType RetreiveRecordByName();

	/**
	*	@brief	�̸��� �Է¹޾� ���� �̸��� ������ ��� �����۵��� ����Ѵ�.
	*	@pre	�̸��� �Է¹޴´�.
	*	@post	����Ʈ���� ���� �̸��� ���� ��� �����۵��� ��µȴ�.
	*/
	void SearchByName(ItemType target);


private:
	ifstream m_InFile;		///< �Է� ���� ��ũ����.
	ofstream m_OutFile;		///< ��� ���� ��ũ����.
	DoublySortedLinkedList<ItemType>m_List; ///< ������ ����Ʈ.
	int m_Command;			///< ���� command ����.
};

// ���α׷��� �����Ű�� �Լ�
void Application::Run()
{
	while (1)
	{
		m_Command = GetCommand();

		switch (m_Command)
		{
		case 1:		// ����Ʈ�� �������� �߰��Ѵ�.
			AddItem();
			break;
		case 2:		// ��ũ���� ����Ʈ�� ��� ������ ������ ����Ѵ�.
			DisplayAllItem();
			break;
		case 3:		// ����Ʈ�� ����.
			MakeEmptyList();
			break;
		case 4:		// ID�� �̿��Ͽ� ����Ʈ���� �������� ã�´�.
			SearchItembyID();
			break;
		case 5:		// �̸��� �̿��Ͽ� ����Ʈ���� �������� ã�´�.
			SearchByName(RetreiveRecordByName());
			break;
		case 6:		// ID�� �̿��Ͽ� ����Ʈ���� �������� ã�� �����Ѵ�.
			DeleteItem();
			break;
		case 7:		// ID�� �̿��Ͽ� ����Ʈ���� �������� ã�� ������ �����Ѵ�.
			UpdateInfo();
			break;
		case 8:		// ����Ʈ�� ��� ������ ���Ͽ��� �ҷ��´�.
			ReadDataFromFile();
			break;
		case 9:		// ����Ʈ�� ��� ������ ���Ͽ� �����Ѵ�.
			WriteDataToFile();
			break;
		case 0:		// ���α׷��� ������.
			return;
		default:
			cout << "\tIllegal sellection...\n";
			break;
		}
	}
}


// ��ũ���� command�� ����ϰ� Ű����κ��� command�� �Է¹޴´�.
int Application::GetCommand()
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : Add new item" << endl;
	cout << "\t   2 : Print all on screen" << endl;
	cout << "\t   3 : Make empty list" << endl;
	cout << "\t   4 : Search item by ID" << endl;
	cout << "\t   5 : Search item by Name" << endl;
	cout << "\t   6 : Delete item" << endl;
	cout << "\t   7 : Update item info" << endl;
	cout << "\t   8 : Get from file" << endl;
	cout << "\t   9 : Put to file " << endl;
	cout << "\t   0 : Quit" << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}


// ����Ʈ�� ���ο� ������ ������ �߰��Ѵ�.
int Application::AddItem()
{
	// �Է¹��� ���ڵ带 ����Ʈ�� add, ����Ʈ�� full�� ���� add���� �ʰ� 0�� ����
	if (m_List.IsFull())
	{
		cout << "List is full" << endl;
		return 0;
	}

	ItemType item;

	item.SetRecordFromKB();

	if (m_List.Add(item) == 0) // �Է��� ���̵�� ���� ���̵� �̹� ����Ʈ�� ������
	{
		cout << "Already has same ID! Try Again!" << endl; // ������� ����Ѵ�.
		return 0;
	}

	// ���� list ���
	DisplayAllItem();

	return 1;
}


// ��ũ���� ����Ʈ�� ��� ������ �������� ����Ѵ�.
void Application::DisplayAllItem()
{
	ItemType data;

	cout << "\n\tCurrent list" << endl;

	// list�� ��� �����͸� ȭ�鿡 ���
	DoublyIterator<ItemType> itor(m_List);
	data = itor.Next();
	while (itor.NextNotNull())
	{
		data.DisplayRecordOnScreen();
		data = itor.Next();
	}
}


// ������ �ҷ��� ������ ���� �Լ�
int Application::OpenInFile(char* fileName)
{
	m_InFile.open(fileName);	// �ҷ����� ���� ���� ����

	// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if (!m_InFile)	return 0;
	else	return 1;
}


// ������ ������ ������ ���� �Լ�
int Application::OpenOutFile(char* fileName)
{
	m_OutFile.open(fileName);	// �����ϱ� ���� ���� ����

	// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if (!m_OutFile)	return 0;
	else	return 1;
}


// �б� ���� ������ ���� ���Ͽ� �ִ� ��� �����͸� �ҷ����� �����͵�� ����Ʈ�� �����.
int Application::ReadDataFromFile()
{
	int index = 0;
	ItemType data;	// �б�� �ӽ� ����

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	// file open, open error�� �߻��ϸ� 0�� ����
	if (!OpenInFile(filename))
		return 0;

	// ������ ��� ������ �о� list�� �߰�
	while (!m_InFile.eof())
	{
		// array�� �л����� ������ ����ִ� structure ����
		data.ReadDataFromFile(m_InFile);
		m_List.Add(data);
	}

	m_InFile.close();	// ������ �ݴ´�.

	// ���� list ���
	DisplayAllItem();

	return 1;
}


// ���� ���� ������ ���� ����Ʈ�� ��� �������� �����Ѵ�.
int Application::WriteDataToFile()
{
	ItemType data;	// ����� �ӽ� ����

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;

	// file open, open error�� �߻��ϸ� 0�� ����
	if (!OpenOutFile(filename))
		return 0;


	// list�� ��� �����͸� ���Ͽ� ����
	DoublyIterator<ItemType> itor(m_List);
	data = itor.Next();
	while (itor.NextNotNull())
	{
		data.WriteDataToFile(m_OutFile);
		data = itor.Next();
	}

	m_OutFile.close();	// ������ �ݴ´�.

	return 1;
}


// �Է¹��� ID�� ������ ������ ã�Ƴ��� ��ũ���� ����Ѵ�.
int Application::SearchItembyID()
{
	ItemType data;
	data.SetIdFromKB(); // Ű����κ��� ID�� �Է¹޴´�.
	if (m_List.Get(data) == 0)
		cout << "\tNo match. Try Again." << endl; // ����Ʈ�� ��ġ�ϴ� �������� ���� ��� ��õ� ���� ���
	else
		data.DisplayRecordOnScreen(); //����Ʈ�� ��ġ�ϴ� �������� �߰��ϸ� �� �������� ��� ������ ���

	return 1;
}


// ����Ʈ�� ���� �Լ�
void Application::MakeEmptyList()
{
	m_List.MakeEmpty(); // ����Ʈ�� ����
	cout << "\tCompelete. List is Empty" << endl; // ����Ʈ ���⿡ �����ߴٴ� ���� ���
}


// �Է¹��� ID�� �������� ã�Ƴ��� �� �������� ��� ������ ����Ʈ���� �����Ѵ�.
int Application::DeleteItem()
{
	if (m_List.IsEmpty() == true) // ����Ʈ�� ����� �� �����͸� ���� �߰��϶�� ���� ���
	{
		cout << "\tData is Empty. Add new data and Try again." << endl;
		return 0;
	}
	ItemType data;
	data.SetIdFromKB(); // Ű����κ��� ID�� �Է¹޴´�.
	if (m_List.Get(data) == 0) // ��ġ�ϴ� �������� ���� ��� ��õ� ���� ���
	{
		cout << "\tNo Match. Try Again" << endl;
		return 0;
	}
	m_List.Delete(data); // �������� ������ �����Ѵ�.
	cout << "\tDelete compelete." << endl; // ���� �Ϸ� ���� ���
	return 1;
}


// �Է¹��� ID�� �������� ã�Ƴ��� �� �������� ������ �����Ѵ�.
int Application::UpdateInfo()
{
	ItemType data;
	data.SetIdFromKB(); // Ű����κ��� ID�� �Է¹޴´�.
	if (m_List.Get(data) == 0) // ��ġ�ϴ� �������� ���� ��� ��õ� ���� ���
	{
		cout << "\tNo Match. Try Again" << endl;
		return 0;
	}
	data.SetNameFromKB();
	data.SetManufacturerFromKB();
	m_List.Replace(data); // �������� ������ �����Ѵ�.
	cout << "\tUpdate compelete." << endl; // ���� �Ϸ� ���� ���
	return 1;
}


// �Է¹��� �̸��� ���� �������� ��ȯ�Ѵ�.
ItemType Application::RetreiveRecordByName()
{
	ItemType data;
	data.SetNameFromKB(); // Ű����κ��� �̸��� �Է¹޴´�.
	return data;
}

//�̸��� �Է¹޾� ���� �̸��� ���� ��� �����۵��� ����Ѵ�.
void Application::SearchByName(ItemType target)
{
	ItemType data;

	cout << "\n\tCurrent list" << endl;

	DoublyIterator<ItemType> itor(m_List);
	data = itor.Next(); // �������� �̵�.				

	while (itor.NextNotNull())
	{
		if (data.GetName().find(target.GetName(), 0) != -1) // �������� �̸��� ��
		{
			data.DisplayRecordOnScreen(); // ��ġ�ϸ� ���
			data = itor.Next();	// �������� �̵�.
		}
		else
			data = itor.Next();	// �׷��� ������ �������� �̵�.
	}

	return;
}

#endif	// _APPLICATION_H