#ifndef _CLIST_H
#define _CLIST_H

#include "clist_node.h"
#include "clist_iterator.h"

template <typename T>
class clist
{
public:

  typedef clist_iterator<T> iterator;

  clist()
  {
    head = new clist_node<T>();
    //head->next = head;
    head->set_next(head);
    //head->prev = head;
    head->set_prev(head);
    _size = 0;
  }
  ~clist()
  {
    clear();
    delete head;
  }

  int size()
  {
    return _size;
  }

  bool empty()
  {
    if(head == head->get_next()) { return true; }
    return false;
  }

  void clear()
  {
    while(head != head->get_next())
    {
      remove_node(head->get_next());
    }
  }

  void push_front(T value)
  {
    clist_node<T> *new_node = new clist_node<T>(value);
    add_node(head, new_node, head->get_next());
  }

  void push_back(T value)
  {
    clist_node<T> *new_node = new clist_node<T>(value);
    add_node(head->get_prev(), new_node, head);
  }

  T pop_front()
  {
    T value = head->get_next()->get_value();
    remove_node(head->get_next());
    return value;
  }

  T pop_back()
  {
    T value = head->get_prev()->get_value();
    remove_node(head->get_prev());
    return value;
  }

  T front() { return head->get_next()->get_value(); }
  T back() { return head->get_prev()->get_value(); }

  iterator begin()
  {
    iterator first(head->get_next());
    return first;
  }

  iterator end()
  {
    iterator last(head);
    return last;
  }

private:
  void add_node(clist_node<T> *prev, clist_node<T> *new_node, clist_node<T> *next)
  {
    if(prev == NULL || new_node == NULL || next == NULL) { return; }
    //new_node->next = next;
    new_node->set_next(next);
    //new_node->prev = prev;
    new_node->set_prev(prev);
    //prev->next = new_node;
    prev->set_next(new_node);
    //next->prev = new_node;
    next->set_prev(new_node);
    _size++;
  }

  void remove_node(clist_node<T> *node)
  { 
    if(node == NULL) { return; }
    //node->prev->next = node->next;
    node->get_prev()->set_next(node->get_next());
    //node->next->prev = node->prev;
    node->get_next()->set_prev(node->get_prev());
    delete node;
    _size--;
  }

private:
  clist_node<T> *head;
  int _size;
};

#endif // _CLIST_H
