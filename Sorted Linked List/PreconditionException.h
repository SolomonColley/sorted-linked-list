/**
Basic logic error class for external functions to throw exceptions.
Exceptions are caught with an associated massage.

@author		Solomon Colley
@file		PreconditionException.h
@since		03/31/2019
*/

#pragma once

#include <stdexcept>
#include <string>

class PreconditionException : public std::logic_error
{
public:
	PreconditionException(const std::string& message = "");
}; // end class PreconditionViolatedException
