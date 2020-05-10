#include "ArrayList.h"


// Make list empty.
void ArrayList::MakeEmpty()
{
	m_Length = 0;
}


// Get a number of records in current list.
int ArrayList::GetLength()
{
	return m_Length;
}


// Check capacity of list is full.
bool ArrayList::IsFull()
{
	if(m_Length > MAXSIZE - 1)
		return true;
	else
		return false;
}


// add a new data into list.
int ArrayList::Add(ItemType inData)
{
	if(!IsFull())
	{
		m_Array[m_Length] = inData;
		m_Length++;
	}
	else
		return 0;

	return 1;
}


// Initialize list iterator.
void ArrayList::ResetList()
{
	m_CurPointer = -1;
}


// move list iterator to the next item in list and get that item.
int ArrayList::GetNextItem(ItemType& data)
{
	m_CurPointer++;	// list pointer 증가
	if(m_CurPointer == MAXSIZE)	// end of list이면 -1을 리턴
		return -1;
	data = m_Array[m_CurPointer];	// 현재 list pointer의 레코드를 복사

	return m_CurPointer;
}


// get an item from file
int ArrayList::Get(ItemType& data) {
	ResetList();
	ItemType temp;
	while (1) {
		GetNextItem(temp);
		if (m_CurPointer < m_Length && m_CurPointer != -1) {
			if (data.CompareByID(temp) == EQUAL) {
				data = temp;
				return m_CurPointer;
			}
		}
		else
			break;
	}
	return -1;
}

// delete an item and tighten the gap
void ArrayList::Delete(ItemType data)
{
	m_Length--;
	int ptrnext = m_CurPointer;
	while (m_CurPointer < m_Length)
	{
		ptrnext++;
		m_Array[m_CurPointer] = m_Array[ptrnext];//ptrnext가 오버플로우
		m_CurPointer++;
	}	
}


// replace data of an item to another
void ArrayList::Replace(ItemType data) {
	m_Array[m_CurPointer] = data;
}