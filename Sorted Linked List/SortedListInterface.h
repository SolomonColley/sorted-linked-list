/**
Templated class interface for manipulating a sorted doubly linked
list abstract data type (ADT).

@author		Solomon Colley
@file		SortedListInterface.h
@since		03/31/2019
*/

#pragma once

template<class ItemType>
class SortedListInterface
{
public:
	/**
	Inserts an entry into this sorted list in its proper order
	so that the list remains sorted.
	@post		A new entry has been inserted into the chain, and the
					list is sorted.
	@param		const ItemType& newEntry - The entry to insert into
					the sorted list.
	@return		void
	*/
	virtual void insertEntry(const ItemType& newEntry) = 0;

	/**
	Removes the first or only occurrence of the given entry from this
	sorted list.
	@pre		The list is not empty.
	@post		If the removal is successful, the first occurrence of the
					given entry is no longer in the sorted list and the returned
					value is true. Else the sorted list is unchanged and the
					returned value is false.
	@param		const ItemType& anEntry - The entry to remove.
	@return		True if the removal is successful, or false if not.
	*/
	virtual bool removeEntry(const ItemType& anEntry) = 0;

	/**
	Returns the position of a specified entry within the chain. If
	the specified entry does not exist within the chain, the position
	at which the entry would exist is returned as a negative integer.
	@post		The chain remains unchanged.
	@param		const ItemType& anEntry - An entry to search for.
	@return		The position of the specified entry if it exists, or
					its position if it were in the chain as a negative
					integer.
	*/
	virtual int getPosition(const ItemType& anEntry) const = 0;

	/**
	Removes the entry at a given position from this list.
	@pre		The position is greater than or equal to one and is
					less than or equal to the number of entries in
					the list.
	@post		The entry at the specified position is removed from
					the list, or the list remains unchanged if
					@pre fails.
	@return		True if the removal is successful, or false if not.
	*/
	virtual bool removePosition(int position) = 0;

	/**
	Removes all entries from this list.
	@return		void
	*/
	virtual void clear() = 0;

	/**
	Gets the current number of entries in this list.
	@return		The number of entries in the list.
	*/
	virtual int getLength() const = 0;

	/**
	Gets the entry at the given position in this list.
	@pre		The position is greater than or equal to one and is
					less than or equal to the number of entries in
					the list.
	@post		The list remains unchanged.
	@return		The entry at the specified position within the chain,
					or a nullptr if @pre fails.
	*/
	virtual ItemType getEntry(int position) const = 0;

	/**
	Sees whether this list is empty or not.
	@return		True if the list is empty, or false if not.
	*/
	virtual bool isEmpty() const = 0;
}; // end class SortedListInterface
