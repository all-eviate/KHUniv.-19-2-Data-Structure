#include "Application.h"


// Program driver.
void Application::Run()
{
	while (1)
	{
		m_nCurCommand = GetCommand();

		switch (m_nCurCommand)
		{
		case 1:		// inset item
			InsertItem();
			break;
		case 2:		// retrieves item
			DisplayAll();
			break;
		case 3:
			RetrieveItem();
			break;
		case 4:
			DeleteItem();
			break;
		case 5:
			MakeEmpty();
			break;
		case 0:	// quit
			return;
		default:
			cout << "\tIllegal sellection...\n";
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
	cout << "\t   1 : Insert Item" << endl;
	cout << "\t   2 : Display all Item" << endl;
	cout << "\t   3 : Retrieve Item" << endl;
	cout << "\t   4 : Delete Item" << endl;
	cout << "\t   5 : Make Empty" << endl;
	cout << "\t   0 : Quit " << endl;

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}


// Add new record into list.
int Application::InsertItem()
{
	ItemType item;

	cout << "Input Item : ";
	cin >> item;

	m_List.Add(item);
	DisplayAll();

	return 1;
}


int Application::DeleteItem() {
	ItemType item;
	cout << "Enter a item to delete : ";
	cin >> item;

	m_List.Delete(item);
	DisplayAll();

	return 1;
}


// Display all records in the list on screen.
void Application::DisplayAll()
{
	ItemType data;

	cout << "\n\tCurrent list" << endl;

	m_List.ResetList();	// ����Ʈ �ʱ�ȭ
	// list�� ��� �����͸� ȭ�鿡 ���
	for (int i = 0; i < m_List.GetLength(); i++)
	{
		m_List.GetNextItem(data);
		cout << data << " - ";
	}
}


int Application::MakeEmpty() {
	m_List.MakeEmpty();
	return 1;
}


// Retrieve item in the list.
int Application::RetrieveItem()
{
	ItemType item;
	cout << "Enter a item for search : ";
	cin >> item;

	if (m_List.Get(item))
	{
		cout << "Target item exists in the list." << endl;
		return 1;
	}
	else
	{
		cout << "Target item is not in the list." << endl;
		return 0;
	}
}