#include "stdafx.h"
#include "CSVWriter.h"
int main()
{
	CSVWriter writer("Data.csv");
	bool end = false;
	int counter = 0;
	int x = 0, y = 0;

	std::set<int> dataList_2 = { x, y };

	while (end == false) {
		x = x + 1;
		y = y + 1;
		dataList_2 = { x, y };

		writer.addDatainRow(dataList_2.begin(), dataList_2.end());
		counter++;
		if (counter == 10) { end = true; };
		Sleep(1000);
	}
	return 0;
}