#include <iostream>
#include "athio.h"
#include <string>
#include <conio.h>
#include <time.h>
#include "Header.h"
using namespace std;

void UzywanieStrzalek(string tab[7][8], int x, int y)

{
	int i = 0, j = 0;
	char a = 'a';


	if (a == 100)
	{
		x = wherex() + 2;
		y = wherey();
	}
	else if (a == 97)
	{
		x = wherex() - 2;
		y = wherey();
	}
	else if (a == 115)
	{
		if (j > 0)
		{
			x = wherex();
			y = wherey() + 1;
		}
	}
	else if (a == 119)
	{

		if (tab[i][j].empty())
		{
		}
		else
		{
			j++;
			x = wherex();
			y = wherey() - 1;
		}
	}

	gotoxy(x, y);

}

void Podswietlenie(int x, int y)
{
	textbackground(RED);



	textbackground(BLINK);
}

void UlozTalie(Talia * wsk, string tab[7][8])
{

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 7; j++)
			tab[i][j] = 1;
	}

	for (int i = 5; i <= 8; i++)
	{
		for (int j = 0; j < 6; j++)
			tab[i][j] = 1;
	}


}


void WyswietlTalie(string tab[7][8])
{
	int x, y;
	x = 1;
	y = 4;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			gotoxy(x, y);
			cout << tab[i][j] << endl;
			y++;
		}
		x++;
		y = 4;
	}

	for (int i = 5; i <= 8; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			gotoxy(x, y);
			cout << tab[i][j] << endl;
			y++;
		}
		x++;
		y = 4;
	}
}


int main()
{
	Talia * wsk;
	char a, b;
	int x, y;
	x = 0;
	y = 0;
	string tab[7][8];


	clock_t start = clock();
	printf("Czas wykonywania: %lu ms\n", ((1000 * (clock() - start)) / CLOCKS_PER_SEC));
	return 0;
}