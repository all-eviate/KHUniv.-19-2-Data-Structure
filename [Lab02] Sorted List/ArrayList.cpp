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
		//m_Array[m_Length] = inData;
		if (m_Length == 0)
			m_Array[0] = inData;
		else {
			for (int i = m_Length - 1; i >= 0; i--) {
				switch (inData.CompareByID(m_Array[i])) {
				case LESS:
					m_Array[i + 1] = m_Array[i];
					break;
				case EQUAL:
					cout << "\n\tID already in use." << endl;
					for (int j = i + 1; j < m_Length; j++)
						m_Array[j] = m_Array[j + 1];
					return 0;
				default:
					m_Array[i + 1] = inData;
					m_Length++;
					return 1;
				}
			}
			m_Array[0] = inData;
		}
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
	m_CurPointer++;	// list pointer ����
	if(m_CurPointer == MAXSIZE)	// end of list�̸� -1�� ����
		return -1;
	data = m_Array[m_CurPointer];	// ���� list pointer�� ���ڵ带 ����

	return m_CurPointer;
}

//id�� ��ġ�ϴ� item�� ã�Ƽ� ��ȯ
int ArrayList::Get(ItemType& target) {
	
	ItemType data;

	ResetList();
	GetNextItem(data);
	while (m_CurPointer < m_Length) {
		switch (data.CompareByID(target)) {
		case EQUAL:
			target = data;
			return 1;
		case GREATER:
			return 0;
		default:
			GetNextItem(data);
			break;
		}
	}

	return 0;
}

//id�� ��ġ�ϴ� item�� ã�Ƽ� ����
int ArrayList::Delete(ItemType item) {
	if (m_Length != 0) { //IsEmpty()
		if (Get(item)) {
			for (int i = m_CurPointer; i < m_Length-1; i++)
				m_Array[i] = m_Array[i + 1];
			m_Length--;
			return 1;
		}
	}
	else return -1;
	return 0;
}

//id�� ��ġ�ϴ� item�� ������ ��ü
int ArrayList::Replace(ItemType item) {
	ItemType tmp(item);

	if (Get(item)) {
		m_Array[m_CurPointer] = tmp;
		return 1;
	}
	return 0;
}

//id�� ��ġ�ϴ� item�� binary search�� ã�Ƽ� ���
int ArrayList::GetBinarySearch(ItemType& data) {
	int first = 0, last = m_Length - 1;
	while (!(first > last)) {
		int mid = (first + last) / 2;
		switch (m_Array[mid].CompareByID(data)) {
		case LESS:
			first = mid + 1;
			break;
		case GREATER:
			last = mid - 1;
			break;
		default:
			data = m_Array[mid];
			return 1;
		}
	}
	return 0;
}