#include <iostream>
using namespace std;

#include "clist.h"

int main()
{
  clist<int> my_list;

  my_list.push_front(3);
  my_list.push_front(2);
  my_list.push_front(1);
  my_list.push_front(0);
  my_list.push_back(4);
  my_list.push_back(5);
  my_list.push_back(6);
  my_list.push_back(7);
  
  cout << "front: " << my_list.front() << endl;
  cout << "back: " << my_list.back() << endl;

  cout << "size: " << my_list.size() << endl;
  cout << endl;
 
  clist<int>::iterator it;
  for(it = my_list.begin(); it != my_list.end(); it++)
  {
    cout << *it << endl;
  }

/*
  while(!my_list.empty())
  {
    my_list.pop_back();
  }

  cout << endl;
  cout << "size: " << my_list.size() << endl;

  my_list.push_front(0);
*/
  my_list.clear();

  cout << endl;
  cout << "size: " << my_list.size() << endl;

  return 0;
}
