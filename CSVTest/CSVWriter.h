#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <iterator>
#include <string>
#include <algorithm>
#include "Windows.h"


class CSVWriter
{
	std::string filnavn;
	std::string delimeter;
	int linje;

public:
	CSVWriter(std::string filnavn, std::string deler = ",") : //Bytte deler dersom vi vil splitte med noe annet. 
		filnavn(filnavn), delimeter(deler), linje(0)
	{}

	template<typename T>
	void addDatainRow(T first, T last);
};

template<typename T>
void CSVWriter::addDatainRow(T first, T last)
{
	std::fstream fil;

	fil.open(filnavn, std::ios::out | (linje ? std::ios::app : std::ios::trunc));

	for (; first != last; )
	{
		fil << *first;
		if (++first != last)
			fil << delimeter;
	}
	fil << "\n";
	linje++;

	fil.close();
}
