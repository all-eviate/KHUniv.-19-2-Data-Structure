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
		case 4:		// [작성] search item from list.
			SearchData();
			break;
		case 5:		// [작성] delete item from list
			DeleteItem();
			break;
		case 6:		// [작성] update item in list
			UpdateItem();
			break;
		case 7:		// load list data from a file.
			ReadDataFromFile();
			break;
		case 8:		// save list data into a file.
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
	cout << "\t   1 : Add new item" << endl;
	cout << "\t   2 : Print all on screen" << endl;
	cout << "\t   3 : Make empty list" << endl;
	cout << "\t   4 : Search item" << endl;
	cout << "\t   5 : Delete item" << endl;
	cout << "\t   6 : Update item" << endl;
	cout << "\t   7 : Get from file" << endl; 
	cout << "\t   8 : Put to file " << endl; 
	cout << "\t   0 : Quit" << endl; 

	cout << endl << "\t Choose a Command--> ";
	cin >> command;
	cout << endl;

	return command;
}


// Add new record into list.
int Application::AddItem()
{
	// [작성] 입력받은 레코드를 리스트에 add, 리스트가 full일 경우는 add하지 않고 0을 리턴
	if (m_List.IsFull()) {
		cout << "\n\tList is already full." << endl;
		return 0;
	}
	else {
		// enter information of a record
		ItemType data;
		data.SetRecordFromKB();
		
		// check if ID is already in use, and return 0 if it is
		if (m_List.Get(data) != -1) {
			cout << "\n\tID already in use." << endl;
			DisplayAllItem();
			return 0;
		}
		m_List.Add(data);
	}

	// [작성] 현재 list 출력
	DisplayAllItem();

	return 1;
}


// Display all records in the list on screen.
void Application::DisplayAllItem()
{
	ItemType data;

	cout << "\n\tCurrent list" << endl;

	// [작성] list의 모든 데이터를 화면에 출력
	m_List.ResetList();
	if (m_List.IsFull()) {
		for (int i = 0; i < MAXSIZE; i++) {
			m_List.GetNextItem(data);
			data.DisplayRecordOnScreen();
		}
	}
	else {
		while (m_List.GetNextItem(data) < m_List.GetLength()) {
			data.DisplayRecordOnScreen();
		}
	}
}


// Open a file by file descriptor as an input file.
int Application::OpenInFile(char *fileName)
{
	m_InFile.open(fileName);	// file open for reading.
	
	// [작성] 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if (m_InFile.is_open())
		return 1;
	else
		return 0;
}


// Open a file by file descriptor as an output file.
int Application::OpenOutFile(char *fileName)
{
	m_OutFile.open(fileName);	// file open for writing.

	// [작성] 파일 오픈에 성공하면 1, 그렇지 않다면 0을 리턴.
	if (m_OutFile.is_open())
		return 1;
	else
		return 0;
}


// Open a file as a read mode, read all data on the file, and set list by the data.
int Application::ReadDataFromFile()
{
	
	int index = 0;
	ItemType data;	// temporary for reading in
	
	char filename[FILENAMESIZE];
	cout << "\n\tEnter Input file Name : ";
	cin >> filename;

	// [작성] file open, open error가 발생하면 0을 리턴
	OpenInFile(filename);
	if (!m_InFile.is_open()) {
		cout << "\n\tError when opening file." << endl;
		return 0;
	}

	// [작성] 파일의 모든 내용을 읽어 list에 추가
	while (data.ReadDataFromFile(m_InFile)) {
		m_List.Add(data);
		if (m_InFile.eof())
			break;
	}

	m_InFile.close();	// file close
	
	// [작성] 현재 list 출력
	DisplayAllItem();
	
	return 1;
}


// Open a file as a write mode, and write all data into the file,
int Application::WriteDataToFile()
{
	
	ItemType data;	// temporary for writing out

	char filename[FILENAMESIZE];
	cout << "\n\tEnter Output file Name : ";
	cin >> filename;

	// [작성] file open, open error가 발생하면 0을 리턴
	OpenOutFile(filename);
	if (!m_OutFile.is_open()) {
		cout << "\n\tError when opening file." << endl;
		return 0;
	}

	// [작성] list 포인터를 초기화
	m_List.ResetList();

	// [작성] list의 모든 데이터를 파일에 쓰기
	while (m_List.GetNextItem(data) < m_List.GetLength()) {
		data.WriteDataToFile(m_OutFile);
	}

	m_OutFile.close();	// file close

	m_List.MakeEmpty(); // empty list to prevent malfunction in the future
	
	return 1;
}


// Search for a record by ID, and check if a match exists or not
int Application::SearchData() {

	ItemType query; // contains id of a record needs to be searched

	cout << "\n\tEnter ID for searching : " << endl;
	query.SetIdFromKB(); // enter id of a record

	
	// Fetch data if there is a match using Get()
	if (m_List.Get(query) != -1) {
		cout << "\n\tWe have a match!" << endl;
		query.DisplayRecordOnScreen();
		return 1;
	}
	else {
		cout << "\n\tThere is no such data by that ID" << endl;
		return 0;
	}
}


// Search for a record by ID, and delete it if one is found
int Application::DeleteItem() {

	ItemType query; // contains id of a record needs to be deleted

	cout << "\n\tEnter ID for deletion : " << endl;
	query.SetIdFromKB(); // enter id of a record

	if (m_List.Get(query) != -1) { // search for a record with same id using query and query gets overwritten into the record in the list
		cout << "\n\tWe have a match!" << endl;
		m_List.Delete(query); // delete the data
		DisplayAllItem(); // show the result
		return 1;
	}
	else { // display if nothing happened
		cout << "\n\tThere is no such data by that ID." << endl;
		DisplayAllItem();

		return 0;
	}
}


// Search for a record by ID, and replace it into the new record that user typed in
int Application::UpdateItem() {

	ItemType request; // Data needed to be updated into

	ItemType temp; // temporary for comparison

	request.SetRecordFromKB(); // enter updated information of a record

	temp.SetId(request.GetId()); // copy id of request into temp

	if (m_List.Get(temp) != -1) { // search for a record with same id using temp
		cout << "\n\tWe have a match!" << endl;
		m_List.Replace(request);
		DisplayAllItem();
		return 1;
	}
	else {
		cout << "\n\tThere is no such data by that ID." << endl;
		return 0;
	}
}