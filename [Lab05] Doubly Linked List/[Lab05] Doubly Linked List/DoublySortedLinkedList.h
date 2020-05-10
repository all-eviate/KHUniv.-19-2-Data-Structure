#pragma once
#ifndef _DOUBLYSORTEDLINKEDLIST_H
#define _DOUBLYSORTEDLINKEDLIST_H

#include "ItemType.h"
#include "DoublyIterator.h"

#define min ItemType(INT_MIN)
#define max ItemType(INT_MAX)

template<typename T>
class DoublyIterator;

/**
*	연결리스트에서 쓰이는 NodeType의 구조체
*/
template <typename T>
struct DoublyNodeType
{
	T data; ///< 각 노드의 데이터.
	DoublyNodeType* prev = NULL; ///< 노드의 앞을 가리키는 포인터.
	DoublyNodeType* next = NULL; ///< 노드의 다음를 가리키는 포인터.
};

/**
*	정렬된 더블연결리스트 클래스
*/
template <typename T>
class DoublySortedLinkedList
{
	friend class DoublyIterator<T>; ///< DoublyIterator와 친구 클래스.
public:
	/**
	*	디폴트 생성자.
	*/
	DoublySortedLinkedList();

	/**
	*	소멸자.
	*/
	~DoublySortedLinkedList();

	/**
	*	@brief	리스트가 비었는지 아닌지 검사한다.
	*	@pre	m_nLength가 값을 가지고 있어야 한다.
	*	@post	비었는지 아닌지를 알려준다.
	*	@return	비어있으면 true, 아니면 false를 반환.
	*/
	bool IsEmpty();

	/**
	*	@brief	리스트가 가득 찼는지 아닌지 검사한다.
	*	@pre	m_nLength가 값을 가지고 있어야 한다.
	*	@post	가득 찼는지 아닌지를 알려준다.
	*	@return	가득 차있으면 true, 아니면 false를 반환.
	*/
	bool IsFull();

	/**
	*	@brief	리스트를 비운다.
	*	@pre	없음.
	*	@post	m_pFirst와 m_pLast를 제외한 모든 데이터를 지운다.
	*/
	void MakeEmpty();

	/**
	*	@brief	리스트의 길이를 반환한다.
	*	@pre	없음.
	*	@post	리스트의 길이를 반환.
	*	@return	m_nLength 리스트의 길이 반환.
	*/
	int GetLength() const;

	/**
	*	@brief	새로운 아이템을 리스트에 추가한다.
	*	@pre	item을 입력받는다.
	*	@post	아이템을 리스트에 추가한다.
	*	@return	같은 아이템이 있으면 0을 반환하고, 입력에 성공하면 1을 반환.
	*/
	int Add(T item);

	/**
	*	@brief	입력받은 아이템을 리스트에서 삭제한다.
	*	@pre	item을 입력받는다.
	*	@post	입력받은 아이템을 리스트에서 찾아 삭제한다.
	*/
	void Delete(T item);

	/**
	*	@brief	입력받은 아이템으로 정보를 바꾼다.
	*	@pre	item을 입력받는다.
	*	@post	새로운 정보로 교체된다.
	*/
	void Replace(T item);

	/**
	*	@brief	입력받은 아이템의 정보와 비교하여 같은 리스트의 아이템을 가져온다.
	*	@pre	item을 입력받는다.
	*	@post	검색된 데이터를 아이템에 넣는다.
	*	@return	일치하는 데이터를 찾으면 1, 그렇지 않으면 0을 반환.
	*/
	int Get(T& item);

private:
	DoublyNodeType<T>* m_pFirst; ///< 최소값을 가지는 리스트의 맨 처음.
	DoublyNodeType<T>* m_pLast; ///< 최댓값을 가지는 리스트의 맨 끝.
	int m_nLength; ///< 리스트의 길이.
};

template <typename T>
DoublySortedLinkedList<T>::DoublySortedLinkedList(){
	m_nLength = 0;
	m_pFirst = NULL;
	m_pLast = NULL;

	m_pFirst->data = min;
	m_pLast->data = max;

	m_pFirst->next = m_pLast;
	m_pLast->prev = m_pFirst;
}

template <typename T>
DoublySortedLinkedList<T>::~DoublySortedLinkedList() {
	MakeEmpty();
}

template <typename T>
bool DoublySortedLinkedList<T>::IsEmpty() {
	if (m_nLength == 0)
		return true;
	else
		return false;
}

template <typename T>
bool DoublySortedLinkedList<T>::IsFull() {
	/*
	DoublyNodeType<T>* location;
	try {
		location = new DoublyNodeType <T>;
		delete location;
		return false;
	}
	catch (bad_alloc exception) {
		return true;
	}
	*/
	return false;
}

template <typename T>
void DoublySortedLinkedList<T>::MakeEmpty() {
	DoublyNodeType<ItemType>* pItem;
	DoublyIterator<ItemType> itor(*this);

	while (itor.NotNull()) {
		pItem = itor.m_pCurPointer;
		itor.Next();
		delete pItem;
	}

	m_pFirst = m_pLast = NULL;

}

template <typename T>
int DoublySortedLinkedList<T>::GetLength() const {
	return m_nLength;
}

template <typename T>
int DoublySortedLinkedList<T>::Add(T item) {
	DoublyNodeType<T>* pItem = new DoublyNodeType<T>;
	DoublyNodeType<T>* location;
	DoublyIterator<T> itor(*this);
	bool added = false;

	pItem->data = item;
	pItem->next = NULL;
	pItem->prev = NULL;

	if (!m_nLength) {
		m_pFirst->next = pItem;
		pItem->prev = m_pFirst;
		pItem->next = m_pLast;
		m_pLast->prev = pItem;
		m_nLength++;
		return 1;
	}
	else {
		while (itor.NotNull() && !added) {
			if (pItem->data < itor.GetCurrentNode().data) {
				location = &(itor.GetCurrentNode());
				pItem->prev = location->prev;
				pItem->next = location;
				location->prev->next = pItem;
				location->prev = pItem;
				m_nLength++;
				return 1;
			}
			itor.Next();
		}
	}
	/*
	DoublyNodeType<T>* node = new DoublyNodeType<T>;
	DoublyNodeType<T>* pre;
	DoublyNodeType<T>* dummy = m_pFirst;

	node->data = item;
	node->next = NULL;
	node->prev = NULL;

	if (!m_nLength) {
		m_pFirst = node;
		node->next = m_pLast;
	}
	else {
		if (node->data < dummy->next->data) {
			node->prev = dummy->prev;
			node->next = dummy;
			dummy->prev->next = node;
			dummy->prev = node;
		}
	}
	*/
	return 0;
}

template <typename T>
void DoublySortedLinkedList<T>::Delete(T item) {
	DoublyNodeType<T> pItem;
	DoublyNodeType<T>* location;
	DoublyIterator<T> itor(*this);
	bool deleted = false;

	pItem.data = item;
	pItem.next = NULL;
	pItem.prev = NULL;

	while (itor.NotNull() && !deleted) {
		if (pItem.data == itor.GetCurrentNode().data) {
			location = &(itor.GetCurrentNode());
			location->prev->next = location->next;
			location->next->prev = location->prev;
			location->next = NULL;
			location->prev = NULL;
			delete location;
		}
		itor.Next();
	}
	/*
	DoublyNodeType<T>* location = m_pFirst;
	DoublyNodeType<T>* node = new DoublyNodeType<T>;
	DoublyNodeType<T>* pre;
	bool deleted = false;

	node->data = item;
	node->next = NULL;
	node->prev = NULL;

	if (!m_nLength) {
		cout << "List is already empty." << endl;
		return 0;
	}
	else {
		location->next;
		if (node->data == location->data) {
			location->prev->next = location->next;
			location->next->prev = location->prev;
			location->next = NULL;
			location->prev = NULL;
			delete location;
		}
	}
	*/
}

template <typename T>
void DoublySortedLinkedList<T>::Replace(T item) {
	DoublyNodeType<T> NewNode;
	DoublyNodeType<T>* location;
	DoublyIterator<T> itor(*this);
	bool replaced = false;

	NewNode.data = item;
	NewNode.next = NULL;
	NewNode.prev = NULL;

	while (itor.NotNull() && !replaced) {
		if (NewNode.data == itor.GetCurrentNode().data) {
			location = &(itor.GetCurrentNode());
			NewNode.prev = location->prev;
			NewNode.next = location->next;
			location->prev->next = &NewNode;
			location->next->prev = &NewNode;
			location->prev = NULL;
			location->next = NULL;
			delete location;
			replaced = true;
		}
		itor.Next();
	}
}

template <typename T>
int DoublySortedLinkedList<T>::Get(T& item) {
	DoublyNodeType<T> NewNode;
	DoublyNodeType<T>* location;
	DoublyIterator<T> itor(*this);

	NewNode.data = item;
	NewNode.next = NULL;
	NewNode.prev = NULL;

	while (itor.NotNull()) {
		if (NewNode.data == itor.GetCurrentNode().data) {
			item = itor.GetCurrentNode().data;
			return 1;
		}
		itor.Next();
	}
}

#endif _DOUBLYSORTEDLINKEDLIST_H