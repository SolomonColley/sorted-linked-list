/**
This class is used for creating and manipulating sorted doubly
linked list abstract data types (ADTs). The polymorphic functions
derived from @file SortedListInterface.h provide a general
interface that users need to further develop more specific
algorithms.

@author		Solomon Colley
@file		SortedLinkedList.h
@since		03/31/2019
*/

#pragma once

#pragma warning(disable : 4290)

#include "Node.h"
#include "PreconditionViolatedException.h"
#include "SortedListInterface.h"

template<class ItemType>
class SortedLinkedList : public SortedListInterface<ItemType>
{
private:
	Node<ItemType>* headPtr;
	int itemCount;

	/**
	Locates the node that is before the node that should or does contain
	the given entry.
	@param		const ItemType& anEntry - The entry to find.
	@return		Either a pointer to the node before the node that contains
					or should contain the given entry, or nullptr if no
					prior node exists.
	*/
	Node<ItemType>* getNodeBefore(const ItemType& anEntry) const;

	/**
	Locates the node at a given position within the linked list.
	@pre		The argument is greater than or equal to one.
	@pre		The argument is less than or equal to the number of
					nodes within the chain.
	@param		int position - The position of the node to find.
	@return		Either a pointer to the node at the specified position,
					or nullptr if @pre fail.
	*/
	Node<ItemType>* getNodeAt(int position) const;

	/**
	Returns a pointer to a copy of the chain to which the parameter
	pointer points to.
	@pre		The pointer to the original chain is not a nullptr.
	@param		const Node<ItemType>* - A pointer to the original chain.
	@return		Either a pointer to a copy of the chain, or a nullptr if
					the original pointer was a nullptr.
	@post		The original chain has been copied and a pointer to it
					has been returned.
	*/
	Node<ItemType>* copyChain(const Node<ItemType>* origChainPtr);

public:
	SortedLinkedList();
	SortedLinkedList(const SortedLinkedList<ItemType>& aList);
	virtual ~SortedLinkedList();

	//=======================================================================//
	//	   Polymorphic methods derived from @file SortedListInterface.h		 //
	//=======================================================================//

	void insertEntry(const ItemType& newEntry);
	bool removeEntry(const ItemType& anEntry);
	int getPosition(const ItemType& anEntry) const;
	bool removePosition(int position);

	void clear();
	ItemType getEntry(int position) const throw(PreconditionViolatedException);
	int getLength() const;
	bool isEmpty() const;
}; // end class LinkedSortedList

#include "SortedLinkedList.cpp"
