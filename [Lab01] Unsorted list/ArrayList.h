#ifndef _UNSORTEDLIST_H
#define _UNSORTEDLIST_H

#include <iostream>
#include <fstream>	
#include <string>
using namespace std;

#include "ItemType.h"

#define MAXSIZE 5

/**
*	array based simple unsorted list.
*/
class ArrayList
{
public:
	/**
	*	default constructor.
	*/
	ArrayList()
	{
		m_Length = 0;
		ResetList();
	}

	/**
	*	destructor.
	*/
	~ArrayList()	{}

	/**
	*	@brief	Make list empty.
	*	@pre	none.
	*	@post	clear list.
	*/
	void MakeEmpty();

	/**
	*	@brief	Get a number of records in current list.
	*	@pre	none.
	*	@post	none.
	*	@return	number of records in current list.
	*/
	int GetLength();

	/**
	*	@brief	Check capacity of list is full.
	*	@pre	none.
	*	@post	none.
	*	@return	return true if list capacity reached to the upper bound, otherwise return false.
	*/
	bool IsFull();

	/**
	*	@brief	add a new data into list.
	*	@pre	list should be initialized.
	*	@post	added the new record into the list.
	*	@param	data	new data.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int Add(ItemType data);

	/**
	*	@brief	Initialize list iterator.
	*	@pre	list should be initialized.
	*	@post	iterator is reset.
	*/
	void ResetList();

	/**
	*	@brief	move list iterator to the next item in list and get that item.
	*	@pre	list and list iterator should not be initialized. 
	*	@post	iterator is moved to next item.
	*	@param	data	get current iterator's item. it does not need to be initialized.
	*	@return	index of current iterator's item if is not end of list, oterwise return -1.
	*/
	int GetNextItem(ItemType& data);

	/** [작성]
	*	@brief	Look for an item with the same ID that is called by reference
	*	@pre	list and list iterator is not initialised
	*	@post	parameter is changed into the item that was already in the list
	*	@param	data that gets current iterator's item if id matches. must have at least id.
	*	@return	index of current iterator's item if wanted data is found, otherwise -1.
	*/
	int Get(ItemType& data);
	
	/** [작성]
	*	@brief	search an item by id, delete the matching one
	*	@pre	list and list iterator should not be initialised
	*	@post	item is erased, and length is reduced
	*	@param	item needs to be deleted
	*	@return	none. void function.
	*/
	void Delete(ItemType data);

	/** [작성]
	*	@brief	replace an item in the list with the same ID
	*	@pre	list and list iterator should not be initialised
	*	@post	item data is replaced
	*	@param	item that is requested to be replaced into
	*	@return	none. void function.
	*/
	void Replace(ItemType data);

private:
	ItemType m_Array[MAXSIZE];  ///< list array.
	int m_Length;				///< number of elements in list.
	int m_CurPointer;			///< iterator pointer.
};

#endif	// _UNSORTEDLIST_H