// Program testowy dla list cyklicznych jednokierunkowych
// Data: 16.02.2012
// (C)2012 mgr Jerzy Wa³aszek
//-------------------------------------------------------

#include <iostream>
#include <iomanip>

using namespace std;

struct slistEl
{
  slistEl * next;
  char data;
};

// Funkcja oblicza liczbê elementów listy
//---------------------------------------
unsigned l_size(slistEl * head)
{
  unsigned  c = 0;
  slistEl * p = head;

  if(p)
  do
  {
    c++;
    p = p->next;
  } while(p != head);
  return c;
}

// Wyœwietla kolejne elementy listy
//---------------------------------
void l_printl(slistEl * head)
{
   slistEl * p;

  cout << setw(3) << l_size(head) << " [";
  p = head;
  if(p)
    do
    {
      cout << " " << p->data;
      p = p->next;
    } while(p != head);
  cout << " ]\n\n";
}

// Wstawia nowy element
//---------------------
void l_push(slistEl * & head, char v)
{
  slistEl * p = new slistEl;

  p->data = v;
  if(head)
  {
    p->next = head->next;
    head->next = p;
  }
  else p->next = p;
  head = p;
}

// Usuwa element
//--------------
void l_pop(slistEl * & head)
{
  if(head)
  {
    slistEl * p = head->next;
    head->next = p->next;
    if(p->next == p) head = NULL;
    delete p;
  }
}

//---------------
// Program g³ówny
//---------------

int main()
{
  slistEl * head = NULL;
  char i;

  l_printl(head);
  for(i = 'A'; i <= 'G'; i++)
  {
    l_push(head,i);
    l_printl(head);
  }
  while(head)
  {
    l_pop(head);
    l_printl(head);
  }

  return 0;
} 