// Sortowanie przez wstawianie z list� jednokierunkow�
// Data: 21.08.2012
// (C)2012 mgr Jerzy Wa�aszek
//---------------------------------------------

#include <iostream>

using namespace std;

struct slistEl                       // typ elementu listy jednokierunkowej
{
  slistEl * next;
  int data;
};

int main()
{
  slistEl * L;                       // wska�nik pocz�tku listy
  slistEl * e, * p;                  // wska�niki element�w listy
  int n;                             // liczba element�w do posortowania
  int v;                             // warto�� elementu

  L = new slistEl;                   // tworzymy pierwszego stra�nika
  L->next = new slistEl;             // tworzymy drugiego stra�nika
  L->next->next = NULL;              // drugi stra�nik jest ostatni na li�cie
  L->next->data = 2147483647;        // warto�� drugiego stra�nika

  cin >> n;                          // odczytujemy liczb� element�w

  for(int i = 0; i < n; i++)
  {
    cin >> v;                        // czytamy element
                                     // szukamy miejsca wstawienia
    for(p = L; v > p->next->data; p = p->next) ;

    e = new slistEl;                 // tworzymy nowy element

    e->data = v;                     // inicjujemy element
    e->next = p->next;

    p->next = e;                     // element wstawiamy do listy L

  }
                                     // list� przesy�amy na wyj�cie
  for(p = L->next; p->next; p = p->next) cout << p->data << " ";

  cout << endl;

  while(L)                           // usuwamy list� z pami�ci
  {
    e = L;
    L = L->next;
    delete e;
  }

  return 0;
} 