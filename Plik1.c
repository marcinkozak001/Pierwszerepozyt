// Program testowy dla list jednokierunkowych
// WOWOWOOWOOWWWo jest cos tu nowego ?
// (C)2012 mgr Jerzy Wa³aszek
//-------------------------------------------

#include <iostream>

using namespace std;

// Typ elementów listy
//--------------------
struct slistEl
{
  slistEl * next;
  char data;
};

// Funkcja oblicza liczbê elementów listy
//---------------------------------------
unsigned l_size(slistEl * p)
{
  unsigned c = 0;

  while(p)
  {
    c++;
    p = p->next;
  }
  return c;
}

// Procedura wyœwietla zawartoœæ elementów listy
//----------------------------------------------
void l_printl(slistEl * p)
{
  unsigned i;

  cout << "Number of elements : " << l_size(p) << endl;

  for(i = 1; p; p = p->next)
    cout << "Element #" << i++ << "  data = " << p->data << endl;
  cout << endl;
}

// Procedura do³¹czania na pocz¹tek listy
//---------------------------------------
void l_push_front(slistEl * & head, char v)
{
  slistEl * p;

  p = new slistEl;
  p->data = v;
  p->next = head;
  head = p;
}

// Procedura usuwa pierwszy element
//---------------------------------
void l_pop_front(slistEl * & head)
{
  slistEl * p = head;

  if(p)
  {
    head = p->next;
    delete p;
  }
}

//---------------
// Program g³ówny
//---------------

int main()
{
  slistEl * L = NULL;

  l_push_front(L,'A');
  l_push_front(L,'B');
  l_push_front(L,'C');
  l_printl(L);
  l_pop_front(L);
  l_pop_front(L);
  l_printl(L);

  return 0;
} 