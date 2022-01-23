#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include "conio.h"
#define N 128
using namespace std;

char buffer[N];

struct base
{
	int cod;
	char name[N];
	int price;
	base *prev;
	base *next;
};

struct discont
{
	int num;
	discont *prev1;
	discont *next1;
};
base *headb = NULL, *tailb = NULL, *curb = NULL;
discont *headc = NULL, *tailc = NULL, *curc = NULL;

void loaddata(FILE *xdata)
{
	xdata = fopen("xdata.txt", "r");
	while (fgets(buffer, N, xdata) != NULL)
	{
			curb = new(base);
			curb->prev = tailb;
			curb->cod = atoi(buffer);
			fgets(buffer, N, xdata);
			strcpy((curb->name),buffer);
			fgets(buffer, N, xdata);
			curb->price = atoi(buffer);
			if (headb == NULL) headb = tailb = curb;
			else
			{
				tailb->next = curb;
				tailb = curb;
			}
			tailb->next = NULL;
	}
	fclose(xdata);
}

void loadcard(FILE *card)
{
	card = fopen("card.txt", "r");
	while (fgets(buffer, N, card) != NULL)
	{
		curc = new(discont);
		curc->prev1 = tailc;
		curc->num = atoi(buffer);
		if (headc == NULL) headc = tailc = curc;
		else
		{
			tailc->next1 = curc;
			tailc = curc;
		}
		tailc->next1 = NULL;
	}
}

void list1()
{
	base *temp;
	temp = headb;
	while (temp != NULL)
	{
		cout << temp->cod << " " << temp->name << " " << temp->price << "\n";
		temp = temp->next;
	}
}

void list2()
{
	FILE *history;
	history = fopen("history.txt", "r");
	while (fgets(buffer, N, history) != NULL)
		cout << buffer;
	fclose(history);
}

void buy()
{
	FILE *history;
	history = fopen("history.txt", "w");
	bool check, checkcard;
	base *temp;
	discont *tempcard;
	int card, i, cod, col, price, allprice = 0;

	while (true)
	{
		checkcard = false;
		check = false;
		temp = headb;
		cout << "Штрихкод товара - ";
		cin >> cod;
		if (cod == 0) break;
		else
		{
			while (temp != NULL)
			{
				if (temp->cod == cod)
				{
					check = true;
					break;
				}
				temp = temp->next;
			}
			if (check)
			{
				cout << temp->name;
				cout << "Количество - ";
				cin >> col;
				price = col * temp->price;
				allprice += price;
				fprintf(history, "\n%s%d", temp->name, price);
			}
			else cout << "Такого товара нет, повторите попытку.\n";
		}
	}
	cout << "Есть ли у вас дисконтная карта?(1 - да, 0 - нет)";
	i = _getch();
	if (i == 48)
	{
		cout << "\nОбщая стоимость - " << allprice;
		fprintf(history, "\n%s%d", "Общая стоимость - ", allprice);
	}
	if (i == 49)
	{
		cout << "\nВведите номер вашей карты\n";
		cin >> card;
		tempcard = headc;
		while (tempcard != NULL)
		{
			if (tempcard->num == card)
			{
				checkcard = true;
				break;
			}
			tempcard = tempcard->next1;
		}
		if (checkcard)
		{
			allprice *= 0.9;
			cout << "\nОбщая стоимость со скидкой - " << allprice;
			fprintf(history, "\n%s%d", "Общая стоимость со скидкой - ", allprice);
		}
		else
		{
			cout << "Карта не существует, оплата без скидки\n";
			cout << "\nОбщая стоимость - " << allprice;
			fprintf(history, "\n%s%d", "Общая стоимость - ", allprice);
		}
	}
	fclose(history);
}