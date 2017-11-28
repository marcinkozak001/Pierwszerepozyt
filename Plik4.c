// Liniowe przeszukiwanie listy
// Data: 12.02.2012
// (C)2012 mgr Jerzy Wa³aszek
//-------------------------------------------

#include <iostream>
#include <cstdlib>
#include <ctime>

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
    void printl();
    void push_front(char v);
    void pop_front();
    slistEl * find_first(char v);
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
  for(slistEl * p = head; p; p = p->next) cout << p->data << " ";
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
  slistEl * p = head; // zapamiêtujemy pocz¹tek

  if(p)
  {
    head = p->next;   // nowy pocz¹tek
    delete p;         // usuñ element z pamiêci
  }
}

// Wyszukuje pierwszy element listy o danej zawartoœci
//----------------------------------------------------
slistEl * slist::find_first(char v)
{
  slistEl * p = head;
  while(p && p->data != v) p = p->next;
  return p;
}

//---------------
// Program g³ówny
//---------------

int main()
{
  slist L;     // obiekt listy jednokierunkowej
  slistEl * p; // do wskazywania elementów listy
  int i;

  srand(time(NULL)); // inicjujemy generator liczb pseudolosowych

  // Tworzymy listê o 40 elementach. Kazdy element przechowuje
  // przypadkow¹ literê od A do G

  for(i = 0; i < 40; i++) L.push_front(65 + rand() % 7);
  L.printl();

  // Na liœcie wyszukujemy literki A i zastêpujemy je znakiem #

  do
  {
    p = L.find_first('A');
    if(p)
    {
      p->data = '.';
      L.printl();
    }
  } while(p);

  return 0;
} 