/**
Basic logic error class for external functions to throw exceptions.
Exceptions are caught with an associated massage.

@author		Solomon Colley
@file		PreconditionViolatedException.cpp
@since		03/31/2019
*/

#include "PreconditionViolatedException.h"  

PreconditionViolatedException::PreconditionViolatedException(const std::string& message) :
	std::logic_error("Precondition Violated Exception: " + message)
{
}  // end parameterized constructor
