/**
This is a program that briefly demonstrates the capabilities of a
templated and sorted doubly linked list abstract data type (ADT).
The program does not demonstrate the full capabilities of this ADT.
Its implementation here is simply meant to show how it can be
used throughout a program.

@author		Solomon Colley
@file		Main.cpp
@since		03/31/2019
*/

#include <ctime>
#include <iostream>
#include <random>
#include "SortedLinkedList.h" // ADT sorted linked list operations

using namespace std;

int main()
{
	int counter = 0;
	SortedListInterface<int>* listPtr = new SortedLinkedList<int>();

	// Generate random integers and populate a new sorted linked list with them.
	cout << "Generating 100 random integers 0 < x < 1,000 and inserting them into\n"
		<< "the sorted linked list ~\n" << endl;
	int* randInts = new int[100];
	srand((unsigned int) time(NULL));
	for (int i = 0; i < 100; ++i)
	{
		randInts[i] = rand() % 1000 + 0;
		listPtr->insertEntry(randInts[i]);
	} // end for
	delete[] randInts;

	cout << "The sorted linked list now contains " << listPtr->getLength() << " integers.\n";

	// Display the newly-created sorted linked list forwards, 10 ints per row on the console.
	cout << "Displaying the sorted linked list forwards (from least to greatest in value) ~\n" << endl;
	for (int position = 1; position <= listPtr->getLength(); ++position)
	{
		++counter;
		cout << listPtr->getEntry(position) << " ";
		if (counter % 10 == 0)
			cout << "\n"; // end if-else
	} // end for
	cout << "\n";

	// Remove all the odd ints from within the sorted linked list.
	/* Because we are removing odd integers from the sorted linked list as we traverse it,
	it must be traversed backwards. Otherwise integers will be skipped as the list's
	length changes with every removal. */
	cout << "Removing all odd integers from within the sorted linked list ~\n" << endl;
	int curEntry = 0;
	counter = 0;
	for (int position = listPtr->getLength(); position > 0; --position)
	{
		curEntry = listPtr->getEntry(position);
		if (curEntry % 2 != 0)
		{
			listPtr->removePosition(position);
			++counter;
		} // end if-else
	} // end for
	cout << counter << " odd integers were removed from the sorted linked list.\n";

	cout << "The sorted linked list now contains " << listPtr->getLength() << " intergers. \n";

	// Display the sorted linked list backwards, 10 ints per row on the console.
	cout << "Displaying the sorted linked list backwards (from greatest to least in value) ~\n" << endl;
	counter = 0;
	for (int position = listPtr->getLength(); position > 0; --position)
	{
		++counter;
		cout << listPtr->getEntry(position) << ", ";
		if (counter % 10 == 0)
			cout << "\n"; // end if-else
	} // end for
	cout << "\n" << endl;

	// Clear out the contents of the sorted linked list and delete it.
	cout << "Destroying the sorted linked list and cleaning up allocated memory ~\n" << endl;
	listPtr->clear();
	cout << "The sorted linked list contains " << listPtr->getLength() << " entries and "
		<< "will now be deleted.\n" << endl;
	delete listPtr;
	listPtr = nullptr;

	cout << "Thank you for checking out my implementation of the sorted linked list ADT!\n" << endl;

	cout << "Enter any character to exit: ";
	cin.get();
	cin.ignore();

	return 0;
} // end main
