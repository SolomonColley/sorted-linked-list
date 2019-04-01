/**
Templated node class for constructing an arbitrary abstract data
structure (ADT). The class provides basic functionality for
getting and setting data.

@author		Solomon Colley
@file		Node.h
@since		03/31/2019
*/

#pragma once

template<class ItemType>
class Node
{
private:
	ItemType item;			// A data item.
	Node<ItemType>* next;	// A pointer to the next data item.

public:
	Node();
	Node(const ItemType& anItem);
	Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);

	/**
	Sets a new data item.
	@param		const ItemType& anItem - A reference to the data
					item to be set.
	@return		void
	*/
	void setItem(const ItemType& anItem);

	/**
	Sets the next data item.
	@param		Node<ItemType>* nextNodePtr - A pointer to the
					next node to be set.
	@return		void
	*/
	void setNext(Node<ItemType>* nextNodePtr);

	/**
	Gets the data item.
	@return		A data item.
	*/
	ItemType getItem() const;

	/**
	Gets the next node.
	@return		A pointer to the next node.
	*/
	Node<ItemType>* getNext() const;
}; // end class Node

#include "Node.cpp"
