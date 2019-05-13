/**
Basic logic error class for external functions to throw exceptions.
Exceptions are caught with an associated massage.

@author		Solomon Colley
@file		PreconditionException.cpp
@since		03/31/2019
*/

#include "PreconditionException.h"  

PreconditionException::PreconditionException(const std::string& message)
	: std::logic_error("Precondition Exception: " + message)
{
}  // end parameterized constructor
