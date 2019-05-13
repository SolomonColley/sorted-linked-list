/**
This class is used for creating and manipulating sorted doubly
linked list abstract data types (ADTs). The polymorphic functions
derived from @file SortedListInterface.h provide a general
interface that users need to further develop more specific
algorithms.

@author		Solomon Colley
@file		SortedLinkedList.cpp
@since		03/31/2019
*/

#include "SortedLinkedList.h"
  
template<class ItemType>
SortedLinkedList<ItemType>::SortedLinkedList() : headPtr(nullptr), itemCount(0)
{
}  // end default constructor

template<class ItemType>
SortedLinkedList<ItemType>::SortedLinkedList(const SortedLinkedList<ItemType>& aList)
{
	// Build a new chain from the existing one
	headPtr = copyChain(aList.headPtr);
	itemCount = aList.itemCount;
}  // end copy constructor

template<class ItemType>
SortedLinkedList<ItemType>::~SortedLinkedList()
{
	clear();
}  // end destructor

template<class ItemType>
Node<ItemType>* SortedLinkedList<ItemType>::getNodeBefore(const ItemType& anEntry) const
{
	Node<ItemType>* curPtr = headPtr;
	Node<ItemType>* prevPtr = nullptr;

	while ((curPtr != nullptr) && (anEntry > curPtr->getItem()))
	{
		prevPtr = curPtr;
		curPtr = curPtr->getNext();
	} // end while

	return prevPtr;
} // end getNodeBefore

template<class ItemType>
Node<ItemType>* SortedLinkedList<ItemType>::getNodeAt(int position) const
{
	assert((position >= 1) && (position <= itemCount));

	/*
	Traverse the chain from the beginning and return the node
	at the specified position.
	*/
	Node<ItemType>* curPtr = headPtr;

	for (int skip = 1; skip < position; ++skip)
		curPtr = curPtr->getNext();

	return curPtr;
} // end getNodeAt

template<class ItemType>
Node<ItemType>* SortedLinkedList<ItemType>::copyChain(const Node<ItemType>* origChainPtr)
{
	Node<ItemType>* copiedChainPtr = nullptr;

	if (origChainPtr != nullptr)
	{
		// Build new chain from the specified one
		copiedChainPtr = new Node<ItemType>(origChainPtr->getItem());
		copiedChainPtr->setNext(copyChain(origChainPtr->getNext()));
	}  // end if-else

	return copiedChainPtr;
}  // end copyChain

template<class ItemType>
void SortedLinkedList<ItemType>::insertEntry(const ItemType& newEntry)
{
	Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
	Node<ItemType>* prevPtr = getNodeBefore(newEntry);

	if (isEmpty() || (prevPtr == nullptr))
	{
		// Add at the beginning of the chain
		newNodePtr->setNext(headPtr);
		headPtr = newNodePtr;
	}
	else
	{
		// Add after the node that exists before it
		Node<ItemType>* aftPtr = prevPtr->getNext();
		newNodePtr->setNext(aftPtr);
		prevPtr->setNext(newNodePtr);
	} // end if-else

	++itemCount;
} // end insertSorted

template<class ItemType>
bool SortedLinkedList<ItemType>::removeEntry(const ItemType& anEntry)
{
	bool canRemove = false;

	if (!isEmpty())
	{
		Node<ItemType>* nodeToRemovePtr = headPtr;
		Node<ItemType>* prevPtr = getNodeBefore(anEntry);

		if (prevPtr != nullptr)
			nodeToRemovePtr = prevPtr->getNext();

		canRemove = (nodeToRemovePtr != nullptr) && (anEntry == nodeToRemovePtr->getItem());

		if (canRemove)
		{
			Node<ItemType>* aftPtr = nodeToRemovePtr->getNext();

			if (nodeToRemovePtr == headPtr)
			{
				// Delete the first node in the chain
				headPtr = aftPtr;
			}
			else
			{
				/*
				Disconnect the indicated node from the chain by connecting the
				prior node with the one that comes after.
				*/
				prevPtr->setNext(aftPtr);
			}  // end if-else

			// Return the deleted node to the system.
			nodeToRemovePtr->setNext(nullptr);
			delete nodeToRemovePtr;
			nodeToRemovePtr = nullptr;

			--itemCount;
		}  // end if-else
	}  // end if-else

	return canRemove;
} // end removeSorted

template<class ItemType>
int SortedLinkedList<ItemType>::getPosition(const ItemType& anEntry) const
{
	int position = 1;
	Node<ItemType>* curPtr = headPtr;

	while ((curPtr != nullptr) && (anEntry > curPtr->getItem()))
	{
		curPtr = curPtr->getNext();
		++position;
	} // end while

	if ((curPtr == nullptr) || (anEntry != curPtr->getItem()))
		position = -position;

	return position;
}  // end getPosition

template<class ItemType>
bool SortedLinkedList<ItemType>::removePosition(int position)
{
	bool canRemove = (position >= 1) && (position <= itemCount);
	
	if (canRemove)
	{
		Node<ItemType>* curPtr = nullptr;

		if (position == 1)
		{
			/*
			Save a pointer to the beginning of the chain
			then delete the first node.
			*/
			curPtr = headPtr;
			headPtr = headPtr->getNext();
		}
		else
		{
			// Find node that exists before the one to be removed.
			Node<ItemType>* prevPtr = getNodeAt(position - 1);

			// Point to the node to be removed.
			curPtr = prevPtr->getNext();

			/*
			Disconnect the indicated node from the chain by connecting
			the previous node with the one that comes after it.
			*/
			prevPtr->setNext(curPtr->getNext());
		} // end if-else

		// Return the deleted node to the system.
		curPtr->setNext(nullptr);
		delete curPtr;
		curPtr = nullptr;

		--itemCount;
	} // end if-ele
	
	return canRemove;
} // end remove

template<class ItemType>
void SortedLinkedList<ItemType>::clear()
{
	while (!isEmpty())
		removePosition(1);
}  // end clear

template<class ItemType>
ItemType SortedLinkedList<ItemType>::getEntry(int position) const throw(PreconditionException)
{
	// Enforce the preconditions
	bool canGet = (position >= 1) && (position <= itemCount);
	
	if (canGet)
	{
		Node<ItemType>* nodePtr = getNodeAt(position);
		return nodePtr->getItem();
	}
	else
	{
		std::string message = "getEntry() called with an empty list or an invalid position.";
		throw(PreconditionException(message)); 
	} // end if-else
} // end getEntry

template<class ItemType>
int SortedLinkedList<ItemType>::getLength() const
{
	return itemCount;
} // end getLength

template<class ItemType>
bool SortedLinkedList<ItemType>::isEmpty() const
{
	return itemCount == 0;
} // end isEmpty
