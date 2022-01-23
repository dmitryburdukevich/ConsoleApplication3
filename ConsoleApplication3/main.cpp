// ConsoleApplication3.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "iostream"
#include "conio.h"
#include "print.h"
#include "load.h"
using namespace std;

void first();
FILE *xdata, *card;
int e;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	loaddata(xdata); //«агрузка списка товаров из базы данных
	loadcard(card); //«агрузка списка скидочных карт из базы данных
	title();
	while (true)
	{
		menu();
		first();
	}
	cin >> e;
	return 0;
}

void first()
{
	setlocale(LC_ALL, "rus");
	int i;
	i = _getch();
	switch (i)
	{

	case 49:
		buy();
		break;

	case 50:
		list1();
		break;

	case 51:
		list2();
		break;

	case 52:
		about();
		break;

	case 53:
		exit(0);
	}
}

