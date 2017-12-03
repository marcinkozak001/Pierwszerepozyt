// Samoorganizuj�ce si� listy
// Przesuwanie na pocz�tek listy
// Data: 04.08.2012
// (C)2012 mgr Jerzy Wa�aszek
//------------------------------

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Element listy
//--------------
struct dlistEl
{
  dlistEl * next;   // nast�pnik
  dlistEl * prev;   // poprzednik
  int data;
};

// Definicja obiektu listy dwukierunkowej
//---------------------------------------
class dlist
{
  public:
    dlistEl * head;  // pocz�tek listy
    dlistEl * tail;  // koniec listy

    dlist();         // konstruktor
    ~dlist();        // destruktor
    void printl();
    void push_front(int v);
    void pop_front();
    dlistEl * find(int v);
};

//------------------------------------
// Metody obiektu listy dwukierunkowej
//------------------------------------

// Inicjuje pola zmiennej listy
//-----------------------------
dlist::dlist()
{
  head  = tail  = NULL;
}

// Usuwa list� z pami�ci
//----------------------
dlist::~dlist()
{
  while(head) pop_front();
}

// Procedura wy�wietla zawarto�� element�w listy
//----------------------------------------------
void dlist::printl()
{
  for(dlistEl * p = head; p; p = p->next)
    if(p == head) cout << "(" << p->data << ")";
    else          cout << " " << p->data << " ";
  cout << endl;
}

// Procedura do��czania na pocz�tek listy
//---------------------------------------
void dlist::push_front(int v)
{
  dlistEl * p = new dlistEl;   // tworzymy nowy element
  p->data = v;
  p->prev = NULL;
  p->next = head;
  head = p;
  if(p->next) p->next->prev = p; else tail = p;
}

// Procedura usuwa pierwszy element
//---------------------------------
void dlist::pop_front()
{
  if(dlistEl * p = head)
  {
    if(!(head = p->next)) tail = NULL; else head->prev = NULL;
    delete p;
  }
}

// Funkcja wyszukuje element, a je�li go znajdzie,
// to umieszcza go na pocz�tku listy. Zwraca
// adres znalezionego elementu lub nil
//------------------------------------------------

dlistEl * dlist::find(int v)
{
  dlistEl * p;

  for(p = head; p; p = p->next) // w p�tli przeszukujemy list�

    if(p->data == v)            // element znaleziony?
    {
      // od��czamy element od listy

      if(p->prev) p->prev->next = p->next; else head = p->next;
      if(p->next) p->next->prev = p->prev; else tail = p->prev;

      // umieszczamy go na pocz�tku listy

      p->next = head;
      p->prev = NULL;
      head = p;
      if(p->next) p->next->prev = p; else tail = p;

      break;                   // opuszczamy p�tl�

    }

  return p;                    // zwracamy wynik p
}

//---------------
// Program g��wny
//---------------

int main()
{
  dlist L;    // obiekt listy
  int i,v;

  srand(time(NULL));                       // inicjujemy liczby pseudolosowe

  for(i = 9; i >= 0; i--) L.push_front(i); // tworzymy list�

  for(i = 0; i < 20; i++)                  // przeszukujemy list�
  {
    v = rand() % 10;                       // losujemy element
    cout << v << ":  ";                    // wy�wietlamy go
    L.find(v);                             // szukamy elementu
    L.printl();                            // wy�wietlamy zawarto�� listy
  }
  return 0;
} 