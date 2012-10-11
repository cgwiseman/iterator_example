#ifndef _CLIST_NODE_H
#define _CLIST_NODE_H

template <typename T>
class clist_node
{
public:
  clist_node()
  {
    next = NULL;
    prev = NULL;
    is_dummy = true;
  }

  clist_node(T t)
  {
    next = NULL;
    prev = NULL;
    value = t;
    is_dummy = false;
  }

  ~clist_node() {}
  
  T get_value() { return value; }
  void set_value(T t) { value = t; }
  
  clist_node *get_next() { return next; }
  void set_next(clist_node *n) { next = n; }
  clist_node *get_prev() { return prev; }
  void set_prev(clist_node *p) { prev = p; }
   
private:
  T value;    
  bool is_dummy;

  clist_node *next;
  clist_node *prev;
};

#endif //  _CLIST_NODE_H
