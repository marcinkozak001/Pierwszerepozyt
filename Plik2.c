// Obiekt listy dwukierunkowej
// Data: 14.02.2012
// (C)2012 mgr Jerzy Wa�aszek
//----------------------------

#include <iostream>
#include <iomanip>

using namespace std;

// Element listy
//--------------
struct dlistEl
{
  dlistEl * next;   // nast�pnik
  dlistEl * prev;   // poprzednik
  char data;
};

// Definicja obiektu listy dwukierunkowej
//---------------------------------------
class dlist
{
  public:
    dlistEl * head;  // pocz�tek listy
    dlistEl * tail;  // koniec listy
    unsigned count;  // licznik element�w

    dlist();         // konstruktor
    ~dlist();        // destruktor
    void printl();
    void push_front(char v);
    void push_back(char v);
    void insert_before(dlistEl * e, char v);
    void insert_after(dlistEl * e, char v);
    void remove(dlistEl * e);
    void pop_front();
    void pop_back();
};

//------------------------------------
// Metody obiektu listy dwukierunkowej
//------------------------------------

// Inicjuje pola zmiennej listy
//-----------------------------
dlist::dlist()
{
  head  = tail  = NULL;
  count = 0;
}

// Usuwa list� z pami�ci
//----------------------
dlist::~dlist()
{
  while(count) pop_front();
}

// Wy�wietla zawarto�� element�w listy
//----------------------------------------------
void dlist::printl()
{
  dlistEl * p;

  cout << setw(3) << count << " : [";
  p = head;
  while(p)
  {
    cout << " " << p->data;
    p = p->next;
  }
  cout << " ]\n\n";
}

// Dodaje nowy element na pocz�tek listy
//------------------------------------------------
void dlist::push_front(char v)
{
  dlistEl * p;

  p = new dlistEl;
  p->data = v;
  p->prev = NULL;
  p->next = head;
  head  = p;
  count++;
  if(p->next) p->next->prev = p;
  else tail = p;
}

// Dodaje nowy element na koniec listy
//----------------------------------------------
void dlist::push_back(char v)
{
  dlistEl * p;

  p = new dlistEl;
  p->data = v;
  p->next = NULL;
  p->prev = tail;
  tail  = p;
  count++;
  if(p->prev) p->prev->next = p;
  else head = p;
}

// Dodaje nowy element przed wybranym
//-----------------------------------
void dlist::insert_before(dlistEl * e, char v)
{
  dlistEl * p;

  if(e == head) push_front(v);
  else
  {
    p = new dlistEl;
    p->data = v;
    p->next = e;
    p->prev = e->prev;
    count++;
    e->prev->next = p;
    e->prev = p;
  }
}

// Dodaje nowy element za wybranym
//--------------------------------
void dlist::insert_after(dlistEl * e, char v)
{
  dlistEl * p;

  if(e == tail) push_back(v);
  else
  {
    p = new dlistEl;
    p->data = v;
    p->next = e->next;
    p->prev = e;
    count++;
    e->next->prev = p;
    e->next = p;
  }
}

// Usuwa wybrany element z listy
//------------------------------
void dlist::remove(dlistEl * e)
{
  count--;
  if(e->prev) e->prev->next = e->next;
  else        head = e->next;
  if(e->next) e->next->prev = e->prev;
  else        tail = e->prev;
  delete e;
}

// Usuwa element z pocz�tku listy
//-------------------------------
void dlist::pop_front()
{
  if(count) remove(head);
}

// Usuwa element z ko�ca listy
//----------------------------
void dlist::pop_back()
{
  if(count) remove(tail);
}

//---------------
// Program g��wny
//---------------

int main()
{
  dlist L;
  char i;

  L.printl();
  for(i = 'A'; i <= 'C'; i++) L.push_front(i);
  L.printl();
  for(i = 'D'; i <= 'F'; i++) L.push_back(i);
  L.printl();
  L.insert_before(L.tail,'#');
  L.printl();
  L.insert_after(L.head,'%');
  L.printl();
  L.pop_front();
  L.printl();
  L.pop_back();
  L.printl();
  L.remove(L.head->next->next);
  L.printl();

  return 0;
} 