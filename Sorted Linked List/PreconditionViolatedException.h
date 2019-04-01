/**
Basic logic error class for external functions to throw exceptions.
Exceptions are caught with an associated massage.

@author		Solomon Colley
@file		PreconditionViolatedException.h
@since		03/31/2019
*/

#pragma once

#include <string>

class PreconditionViolatedException : public std::logic_error
{
public:
	PreconditionViolatedException(const std::string& message = "");
}; // end class PreconditionViolatedException
