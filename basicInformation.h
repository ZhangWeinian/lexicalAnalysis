#ifndef __BASIC_INFORMATION__
#define __BASIC_INFORMATION__

#pragma once

#include "basicHeader_part1.h"
#include "basicHeader_part2.h"

class Information
{
public:

	_NORETURN Information(void) = default;
	_NORETURN ~Information(void) = default;

	_str oneLine = "";
	_str oneWord = "";
};

class Flag
{
public:

	_NORETURN Flag(void) = default;
	_NORETURN ~Flag(void) = default;


	bool getOneLine = false;
	bool getOneWord = false;
};

#endif // !__BASIC_INFORMATION__
