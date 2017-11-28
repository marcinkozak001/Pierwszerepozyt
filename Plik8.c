// Zliczanie element�w listy
// Data: 19.02.2012
// (C)2012 mgr Jerzy Wa�aszek
//---------------------------

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Typ element�w listy
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
    void     printl();
    void     push_front(char v);
    void     pop_front();
    unsigned countv(char v);
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

// Procedura wy�wietla zawarto�� element�w listy
//----------------------------------------------
void slist::printl()
{
  slistEl * p;
  for(p = head; p; p = p->next) cout << p->data;
  cout << endl;
}

// Procedura do��czania na pocz�tek listy
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
  slistEl * p = head; // zapami�tujemy pocz�tek

  if(p)
  {
    head = p->next;   // nowy pocz�tek
    delete p;         // usu� element z pami�ci
  }
}

// Oblicza liczb� element�w zawieraj�cych v
//-----------------------------------------
unsigned slist::countv(char v)
{
  slistEl * p = head;
  unsigned c = 0;
  while(p)
  {
    if(p->data == v) c++;
    p = p->next;
  }
  return c;
}

//---------------
// Program g��wny
//---------------

int main()
{
  slist L;     // zawiera adres pocz�tku listy
  int i;

  srand(time(NULL));

  for(i = 0; i < 400; i++) L.push_front(65 + rand() % 26);
  L.printl();

  for(i = 'A'; i <= 'Z'; i++) cout << char(i) << " : " << setw(3) << L.countv(i) << endl;
  return 0;
} 