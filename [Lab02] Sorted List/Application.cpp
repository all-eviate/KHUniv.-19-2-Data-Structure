#include "Application.h"


// Program driver.
void Application::Run()
{
	while(1)
	{
		m_Command = GetCommand();

		switch(m_Command)
		{
		case 1:		// read a record and add to list.
			AddItem();
			break;
		case 2:		// display all the records in list on screen.
			DisplayAllItem();
			break;
		case 3:		// make empty list.
			m_List.MakeEmpty();
			break;
		case 4:
			//SearchItemById();
			SearchItemByBinarySearch();
			break;
		case 5:
			RetrieveRecordByMemberName();
			break;
		case 6:
			DeleteItem();
			break;
		case 7:
			ReplaceItem();
			break;
		case 8:		// load list data from a file.
			ReadDataFromFile();
			break;
		case 9:		// save list data into a file.
			WriteDataToFile();
			break;
		case 0:
			return;
		default:
			cout << "\tIllegal selection...\n";
			break;
		}
	}
}


// Display command on screen and get a input from keyboard.
int Application::GetCommand()
{
	int command;
	cout << endl << endl;
	cout << "\t---ID -- Command ----- " << endl;
	cout << "\t   1 : Add item" << endl;
	cout << "\t   2 : Print all on screen" << endl;
	cout << "\t   3 : Make empty list" << endl;
	cout << "\t   4 : Search item by ID" << endl;
	cout << "\t   5 : Search item by name" << endl;
	cout << "\t   6 : Delete item" << endl;
	cout << "\t   7 : Update item" << endl;
	cout << "\t   8 : Get from file" << endl; 
	cout << "\t   9 : Put to file " << endl; 
	cout << "\t   0 : Quit" << endl; 

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}


// Add new record into list.
int Application::AddItem()
{
	// �Է¹��� ���ڵ带 ����Ʈ�� add, ����Ʈ�� full�� ���� add���� �ʰ� 0�� ����
	if(m_List.IsFull())
	{
		cout << "\t[Message]List is full" << endl;
		return 0;
	}

	ItemType item;

	item.SetRecordFromKB();
	m_List.Add(item);

	// ���� list ���
	DisplayAllItem();

	return 1;
}


// Display all records in the list on screen.
void Application::DisplayAllItem()
{
	ItemType data;

	cout << "\n\tCurrent list" << endl;

	// list�� ��� �����͸� ȭ�鿡 ���
	m_List.ResetList();
	int length = m_List.GetLength();
	int curIndex = m_List.GetNextItem(data);
	while(curIndex < length && curIndex != -1)
	{
		data.DisplayRecordOnScreen();
		curIndex = m_List.GetNextItem(data);
	}
}


// Open a file by file descriptor as an input file.
int Application::OpenInFile(char *fileName)
{
	m_InFile.open(fileName);	// file open for reading.
	
	// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if(!m_InFile)	return 0;
	else	return 1;
}


// Open a file by file descriptor as an output file.
int Application::OpenOutFile(char *fileName)
{
	m_OutFile.open(fileName);	// file open for writing.

	// ���� ���¿� �����ϸ� 1, �׷��� �ʴٸ� 0�� ����.
	if(!m_OutFile)	return 0;
	else	return 1;
}


// Open a file as a read mode, read all data on the file, and set list by the data.
int Application::ReadDataFromFile()
{
	int index = 0;
	ItemType data;	// �б�� �ӽ� ����
	
	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	// file open, open error�� �߻��ϸ� 0�� ����
	if(!OpenInFile(filename))
		return 0;

	// ������ ��� ������ �о� list�� �߰�
	while(!m_InFile.eof())
	{
		// array�� �л����� ������ ����ִ� structure ����
		data.ReadDataFromFile(m_InFile);
		m_List.Add(data);
	}

	m_InFile.close();	// file close

	// ���� list ���
	DisplayAllItem();

	return 1;
}


// Open a file as a write mode, and write all data into the file,
int Application::WriteDataToFile()
{
	ItemType data;	// ����� �ӽ� ����

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;

	// file open, open error�� �߻��ϸ� 0�� ����
	if(!OpenOutFile(filename))
		return 0;

	// list �����͸� �ʱ�ȭ
	m_List.ResetList();

	// list�� ��� �����͸� ���Ͽ� ����
	int length = m_List.GetLength();
	int curIndex = m_List.GetNextItem(data);
	while(curIndex < length && curIndex != -1)
	{
		data.WriteDataToFile(m_OutFile);
		curIndex = m_List.GetNextItem(data);
	}

	m_OutFile.close();	// file close

	return 1;
}

//id�� item�� ã�� ���
int Application::SearchItemById() {
	ItemType item;
	item.SetIdFromKB();

	if (m_List.Get(item)) {
		cout << "\t[Message] Successfully search!!" << endl;
		item.DisplayRecordOnScreen();
		return 1;
	}
	cout << "\t[Message] Search failed." << endl;
	return 0;
}

//name���� item�� ã�� ���
int Application::RetrieveRecordByMemberName() {
	ItemType item;
	item.SetNameFromKB();
	if (SearchListByMemberName(item) == 0) {
		cout << "\t[Message] There is no such data." << endl;
		return 0;
	}
	else
		return 1;
}

int Application::SearchListByMemberName(ItemType& inData) {
	ItemType temp;
	m_List.ResetList();
	int cur = m_List.GetNextItem(temp), count = 0;
	while (cur < m_List.GetLength() && cur != -1) {
		if (temp.GetName().find(inData.GetName()) != -1) {
			count++;
			cout << "\t[Message] Result No." << count << endl;
			temp.DisplayRecordOnScreen();
		}
		cur = m_List.GetNextItem(temp);
	}
	if (count > 0)
		return 1;
	else
		return 0;
}

//id�� item�� ã�Ƽ� ����
int Application::DeleteItem() {
	ItemType item;
	item.SetIdFromKB();

	switch(m_List.Delete(item)) {
	case 1:
		cout << "\t[Message] Successfully delete!!" << endl;
		DisplayAllItem();
		return 1;
	case 0:
		cout << "\t[Message] There is no item." << endl;
		break;
	default: // case -1:
		cout << "\t[Message] List is empty." << endl;
	}
	DisplayAllItem();
	return 0;
}

//id���� ������ item�� ����
int Application::ReplaceItem() {
	ItemType item;
	item.SetRecordFromKB();

	if (m_List.Replace(item)) {
		cout << "\t[Message] Successfully update!!" << endl;
		DisplayAllItem();
		return 1;
	}
	cout << "\t[Message] There is no item in the list." << endl;
	DisplayAllItem();
	return 0;
}

//����Ž�� �ǽ�
int Application::SearchItemByBinarySearch() {
	ItemType item;
	item.SetIdFromKB();

	if (m_List.GetBinarySearch(item)) {
		cout << "\t[Message] Item found!" << endl;
		item.DisplayRecordOnScreen();
		return 1;
	}
	cout << "\t[Message] There is no such data." << endl;
	return 0;
}