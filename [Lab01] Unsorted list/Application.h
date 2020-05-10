#ifndef _APPLICATION_H
#define _APPLICATION_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "ArrayList.h"

#define FILENAMESIZE 1024

/**
*	application class for item management simply.
*/
class Application
{
public:
	/**
	*	default constructor.
	*/
	Application()
	{
		m_Command = 0;
	}
	
	/**
	*	destructor.
	*/
	~Application()	{}

	/**
	*	@brief	Program driver.
	*	@pre	program is started.
	*	@post	program is finished.
	*/
	void Run();

	/**
	*	@brief	Display command on screen and get a input from keyboard.
	*	@pre	none.
	*	@post	none.
	*	@return	user's command.
	*/
	int GetCommand();

	/**
	*	@brief	Add new record into list.
	*	@pre	list should be initialized.
	*	@post	new record is added into the list.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int AddItem();

	/**
	*	@brief	Display all records in the list on screen.
	*	@pre	none.
	*	@post	none.
	*/
	void DisplayAllItem();

	/**
	*	@brief	Open a file by file descriptor as an input file.
	*	@pre	a file for reading is exist.
	*	@post	open the file for reading.
	*	@param	fileName	a filename to open for reading.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int OpenInFile(char *fileName);

	/**
	*	@brief	Open a file by file descriptor as an output file.
	*	@pre	list should be initialized.
	*	@post	open the file for writing.
	*	@param	fileName	a filename to open for writing.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int OpenOutFile(char *fileName);

	/**
	*	@brief	Open a file as a read mode, read all data on the file, and set list by the data.
	*	@pre	The file is not opened.
	*	@post	list holds all records from the file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReadDataFromFile();

	/**
	*	@brief	Open a file as a write mode, and write all data into the file,
	*	@pre	The file is not opened.
	*	@post	the list is stored in the output file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int WriteDataToFile();

	/** [작성]
	*	@brief	Get query by keyboard to search for the record
	*	@pre	List is initialised
	*	@post	none
	*	@return	1 if a matching data exists, 0 if not
	*/
	int SearchData();

	/** [작성]
	*	@brief	Get delete request by ID and exclude the searched item from the list
	*	@pre	List is initialised
	*	@post	Item by the request ID is erased
	*	@return	1 if succesfully deleted, 0 if not
	*/
	int DeleteItem();

	/** [작성]
	*	@brief	Search for a record by ID, and replace it into the new record that user entered
	*	@pre	List is initialised
	*	@post	Information of the item with the same ID is replaced
	*	@return	1 if succesful, 0 if not
	*/
	int UpdateItem();

	
private:
	ifstream m_InFile;		///< input file descriptor.
	ofstream m_OutFile;		///< output file descriptor.
	ArrayList m_List;		///< item list.
	int m_Command;			///< current command number.
};

#endif	// _APPLICATION_H