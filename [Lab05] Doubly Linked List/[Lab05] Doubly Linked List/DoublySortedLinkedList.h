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
*	���Ḯ��Ʈ���� ���̴� NodeType�� ����ü
*/
template <typename T>
struct DoublyNodeType
{
	T data; ///< �� ����� ������.
	DoublyNodeType* prev = NULL; ///< ����� ���� ����Ű�� ������.
	DoublyNodeType* next = NULL; ///< ����� ������ ����Ű�� ������.
};

/**
*	���ĵ� �����Ḯ��Ʈ Ŭ����
*/
template <typename T>
class DoublySortedLinkedList
{
	friend class DoublyIterator<T>; ///< DoublyIterator�� ģ�� Ŭ����.
public:
	/**
	*	����Ʈ ������.
	*/
	DoublySortedLinkedList();

	/**
	*	�Ҹ���.
	*/
	~DoublySortedLinkedList();

	/**
	*	@brief	����Ʈ�� ������� �ƴ��� �˻��Ѵ�.
	*	@pre	m_nLength�� ���� ������ �־�� �Ѵ�.
	*	@post	������� �ƴ����� �˷��ش�.
	*	@return	��������� true, �ƴϸ� false�� ��ȯ.
	*/
	bool IsEmpty();

	/**
	*	@brief	����Ʈ�� ���� á���� �ƴ��� �˻��Ѵ�.
	*	@pre	m_nLength�� ���� ������ �־�� �Ѵ�.
	*	@post	���� á���� �ƴ����� �˷��ش�.
	*	@return	���� �������� true, �ƴϸ� false�� ��ȯ.
	*/
	bool IsFull();

	/**
	*	@brief	����Ʈ�� ����.
	*	@pre	����.
	*	@post	m_pFirst�� m_pLast�� ������ ��� �����͸� �����.
	*/
	void MakeEmpty();

	/**
	*	@brief	����Ʈ�� ���̸� ��ȯ�Ѵ�.
	*	@pre	����.
	*	@post	����Ʈ�� ���̸� ��ȯ.
	*	@return	m_nLength ����Ʈ�� ���� ��ȯ.
	*/
	int GetLength() const;

	/**
	*	@brief	���ο� �������� ����Ʈ�� �߰��Ѵ�.
	*	@pre	item�� �Է¹޴´�.
	*	@post	�������� ����Ʈ�� �߰��Ѵ�.
	*	@return	���� �������� ������ 0�� ��ȯ�ϰ�, �Է¿� �����ϸ� 1�� ��ȯ.
	*/
	int Add(T item);

	/**
	*	@brief	�Է¹��� �������� ����Ʈ���� �����Ѵ�.
	*	@pre	item�� �Է¹޴´�.
	*	@post	�Է¹��� �������� ����Ʈ���� ã�� �����Ѵ�.
	*/
	void Delete(T item);

	/**
	*	@brief	�Է¹��� ���������� ������ �ٲ۴�.
	*	@pre	item�� �Է¹޴´�.
	*	@post	���ο� ������ ��ü�ȴ�.
	*/
	void Replace(T item);

	/**
	*	@brief	�Է¹��� �������� ������ ���Ͽ� ���� ����Ʈ�� �������� �����´�.
	*	@pre	item�� �Է¹޴´�.
	*	@post	�˻��� �����͸� �����ۿ� �ִ´�.
	*	@return	��ġ�ϴ� �����͸� ã���� 1, �׷��� ������ 0�� ��ȯ.
	*/
	int Get(T& item);

private:
	DoublyNodeType<T>* m_pFirst; ///< �ּҰ��� ������ ����Ʈ�� �� ó��.
	DoublyNodeType<T>* m_pLast; ///< �ִ��� ������ ����Ʈ�� �� ��.
	int m_nLength; ///< ����Ʈ�� ����.
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