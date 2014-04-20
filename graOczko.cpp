#include <iostream>
#include <ctime>
#include <string>
#include "Header.h"
using namespace std;

class Karta
{
 public:
	int figura;
	string figura1;
	int kolor;
	string kolor1;
	Karta *next;
	Karta *prev;
	void NazwaKarty(Karta * karta);
	string nazwakarty;
	void PolaczNazwy(Karta * karta);

};


class Talia
{
 public:
  Karta *head;
	Karta *tail;
  Talia();
	void UtworzTalie(); 
	void Tasuj();
  void UsunKarte(Karta *usun);
  void DodajdoKoncaKarte(Karta *wstaw);
  void WyswietlTalie();
  Karta *WziacKartezTalii();
};

Talia::Talia()
{
  head=NULL;
	tail=NULL;
}

class Reka
	:public Talia
{
  public:
	 int ObliczycPunkty(Reka gracza);
};

class Stol_Gry
{
 public:
  Talia MainTalia;
  Stol_Gry();
};

Stol_Gry::Stol_Gry()
{
  MainTalia.UtworzTalie();
  MainTalia.Tasuj();
}
void Karta::PolaczNazwy(Karta * karta)
{

	karta->nazwakarty.append(karta->figura1, karta->kolor1);


}
void NazwaKarty(Karta *wsk)
{
	switch (wsk->figura)
	{
	  case 1: wsk->figura1 = "A";
	  break;
	  case 2: wsk->figura1 = "2";
		break;
	  case 3: wsk->figura1 = "3";
		break;
	  case 4: wsk->figura1 = "4";
		break;
	  case 5: wsk->figura1 = "5";
		break;
	  case 6: wsk->figura1 = "6";
		break;
	  case 7: wsk->figura1 = "7";
		break;
	  case 8: wsk->figura1 = "8";
		break;
	  case 9: wsk->figura1 = "9";
		break;
	  case 10: wsk->figura1 = "10";
		break;
	  case 11: wsk->figura1 = "J";
		break;
	  case 12: wsk->figura1 = "D";
		break;
	  case 13: wsk->figura1 = "K";
		break;
	}
	switch (wsk->kolor)
	{
	  case 0: wsk->kolor1 = "/3";
		break;
	  case 1: wsk->kolor1 = "/4";
		break;
	  case 2: wsk->kolor1 = "/5";
		break;
	  case 3:	wsk->kolor1 = "/6";
		break;
	}
}

void Talia::UtworzTalie()
{
  int i, j;
  Karta *tmp;
  for(i=1; i<=13; i++)
  {
    for(j=0; j<4; j++)
    {
      tmp=new Karta;
      tmp->figura=i;
      tmp->kolor=j;
      if(i==1 && j==0)
      {
        tmp->prev=NULL;
        head=tmp;
        tail=tmp;
      }
      else
      {
        tmp->prev=tail; 
        tail->next=tmp;
        tail=tmp;
      }
      tmp->next=NULL;
      NazwaKarty(tmp);
    }
  }
}

void Talia::UsunKarte(Karta *usun)
{
  Karta *poprzedni, *nastepny; 
  poprzedni=usun->prev;
  nastepny=usun->next;
  if(poprzedni!=NULL || nastepny!=NULL)
  {
    if(usun==head)
    {
      nastepny->prev=NULL;
      head=nastepny;
    }
    else
    {
      if(usun==tail)
      {
        poprzedni->next=NULL;
        tail=poprzedni;
      }
      else
      {
        poprzedni->next=nastepny;
        nastepny->prev=poprzedni;
      }
    }
  }
}

void Talia::DodajdoKoncaKarte(Karta *wstaw)
{
  if(head==NULL && tail==NULL)
  {
    head=wstaw;
    head->next=NULL;
    head->prev=NULL;
    tail=wstaw;
    tail->next=NULL;
    tail->prev=NULL;
  }
  else
  {
    tail->next=wstaw;
    wstaw->prev=tail;
    wstaw->next=NULL;
    tail=wstaw;
  }
}
    
void Talia::Tasuj()
{
	int i, j, losuj;
	Karta *wsk;
	for(i = 0; i < 80; i++)
	{
		losuj = rand()%53;
		wsk = head;
		for(j = 0; j < losuj && wsk->next!=NULL; j++)
			wsk = wsk->next;
    UsunKarte(wsk);
    DodajdoKoncaKarte(wsk);
	}
}

void Talia::WyswietlTalie()
{
	Karta *wsk;
	wsk = head;
	int i=1;
	do
	{	
		cout << "Karta numer " << i << " to : ";
		cout << wsk->figura1 << " ";
		cout << wsk->kolor1 << endl;
		i++;
    wsk=wsk->next;
	} while(wsk!=NULL);
}


Karta *Talia::WziacKartezTalii()
{
  Karta *nastepny, *usun; 
  usun=head;
  nastepny=head->next;
  UsunKarte(usun);
  if(nastepny!=NULL)
    nastepny->prev=NULL;
  head=nastepny;
  return usun;
}

