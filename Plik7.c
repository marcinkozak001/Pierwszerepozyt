// Sortowanie listy jednokierunkowej przez scalanie
// Data: 25.02.2012
// (C)2012 mgr Jerzy Wa³aszek
//-------------------------------------------------

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Typ elementów listy
//--------------------
struct slistEl
{
  slistEl * next;
  int data;
};

// Definicja typu obiektowego slist
//---------------------------------

class slist
{
  public:
    slistEl * head;

    slist();  // konstruktor
    ~slist(); // destruktor
    void printl();
    void push_front(char v);
    void pop_front();
    void split(slist & l1, slist & l2);
    void merge(slist & l1, slist & l2);
    void merge_sort();
};

// Konstruktor listy
//------------------
slist::slist()
{
  head = NULL;
}

// Destruktor listy
//-----------------
slist::~slist()
{
  while(head) pop_front();
}

// Procedura wyœwietla zawartoœæ elementów listy
//----------------------------------------------
void slist::printl()
{
  slistEl * p;

  for(p = head; p; p = p->next) cout << setw(4) << p->data;
  cout << endl;
}

// Procedura do³¹czania na pocz¹tek listy
//---------------------------------------
void slist::push_front(char v)
{
  slistEl * p;

  p = new slistEl;
  p->next = head;
  p->data = v;
  head = p;
}

// Procedura usuwa pierwszy element
//---------------------------------
void slist::pop_front()
{
  slistEl * p = head;

  if(p)
  {
    head = p->next;
    delete p;
  }
}

// Dokonuje podzia³u listy
//------------------------
void slist::split(slist & l1, slist & l2)
{
  slistEl * p1, * p2;
  bool s = false;
  l1.push_front(0);
  l2.push_front(0);
  p1 = l1.head;
  p2 = l2.head;
  while(head)
  {
    if(s)
    {
      p2->next = head;
      p2 = p2->next;
    }
    else
    {
      p1->next = head;
      p1 = p1->next;
    }
    head = head->next;
    s = !s;
  }
  p1->next = p2->next = NULL;
  l1.pop_front();
  l2.pop_front();
}

// Scala dwie obce listy
//----------------------
void slist::merge(slist & l1, slist & l2)
{
  slistEl * p;
  push_front(0);
  p = head;
  while(l1.head && l2.head)
  {
    if(l1.head->data > l2.head->data)
    {
      p->next = l2.head;
      l2.head = l2.head->next;
    }
    else
    {
      p->next = l1.head;
      l1.head = l1.head->next;
    }
    p = p->next;
  }
  while(l1.head)
  {
    p->next = l1.head;
    l1.head = l1.head->next;
    p  = p->next;
  }
  while(l2.head)
  {
    p->next = l2.head;
    l2.head = l2.head->next;
    p  = p->next;
  }
  pop_front();
}

// Sortuje listê przez scalanie
//-----------------------------
void slist::merge_sort()
{
  slist h1,h2;
  if(head && head->next)
  {
    split(h1,h2);
    h1.merge_sort();
    h2.merge_sort();
    merge(h1,h2);
  }
}

//---------------
// Program g³ówny
//---------------

int main()
{
  slist L;     // obiekt listy jednokierunkowej
  int i;

  srand(time(NULL));

  for(i = 0; i < 200; i++) L.push_front(rand() % 199 - 99);
  L.printl();

  cout << endl;

  L.merge_sort();
  L.printl();

  return 0;
} 