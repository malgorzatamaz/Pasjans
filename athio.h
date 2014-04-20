/*
Stworzone przez Adama Ma³ka.

Rozpowszechnianie na licencji Beerware.

Biblioteka zawiera podstawowe funkcje do obs³ugi konsoli windows.
Powsta³a, poniewa¿ conio nie œmiga pod Visualem :/

2014.

*/

#ifndef ATHIO


#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGREY 7
#define DARKGREY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 15
#define BLINK 128

void textcolor(int fontcolor);
void gotoxy(int x, int y);
void clrscr();
void textbackground(int);
int wherex();
int wherey();
void resetcolors();
void delay(int msec);
void help();
void showcolors();

#endif // !ATHIO