// Podzia³ listy jednokierunkowej na dwie podlisty
// Data: 25.02.2012
// (C)2012 mgr Jerzy Wa³aszek
//------------------------------------------------

#include <iostream>

using namespace std;

// Typ elementów listy
//--------------------
struct slistEl
{
  slistEl * next;
  char data;
};

// Definicja typu obiektowego slist
//---------------------------------

class slist
{
  public:
    slistEl * head;

    slist();  // konstruktor
    ~slist(); // destruktor
    unsigned size();
    void printl();
    void push_front(char v);
    void pop_front();
    void split(slist & l1, slist & l2);
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

// Funkcja oblicza liczbê elementów listy
//---------------------------------------
unsigned slist::size()
{
  unsigned c = 0;
  slistEl * p = head;
  while(p)
  {
    c++;
    p = p->next;
  }
  return c;
}

// Procedura wyœwietla zawartoœæ elementów listy
//----------------------------------------------
void slist::printl()
{
  slistEl * p;

  cout << size() << " : ";
  for(p = head; p; p = p->next) cout << p->data << " ";
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

//---------------
// Program g³ówny
//---------------

int main()
{
  slist L,L1,L2;    // obiekty list jednokierunkowych
  char i;

  for(i = 'Z'; i >= 'A'; i--) L.push_front(i);
  L.printl();
  cout << endl;

  L.split(L1,L2);   // dzielimy L, wynik w L1 i L2
  L1.printl();      // wyœwietlamy L1
  L2.printl();      // wyœwietlamy L2

  return 0;
} 