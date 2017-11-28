// Sortowanie przez wstawianie z list¹ jednokierunkow¹
// Data: 21.08.2012
// (C)2012 mgr Jerzy Wa³aszek
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
  slistEl * L;                       // wskaŸnik pocz¹tku listy
  slistEl * e, * p;                  // wskaŸniki elementów listy
  int n;                             // liczba elementów do posortowania
  int v;                             // wartoœæ elementu

  L = new slistEl;                   // tworzymy pierwszego stra¿nika
  L->next = new slistEl;             // tworzymy drugiego stra¿nika
  L->next->next = NULL;              // drugi stra¿nik jest ostatni na liœcie
  L->next->data = 2147483647;        // wartoœæ drugiego stra¿nika

  cin >> n;                          // odczytujemy liczbê elementów

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
                                     // listê przesy³amy na wyjœcie
  for(p = L->next; p->next; p = p->next) cout << p->data << " ";

  cout << endl;

  while(L)                           // usuwamy listê z pamiêci
  {
    e = L;
    L = L->next;
    delete e;
  }

  return 0;
} 