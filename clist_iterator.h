#ifndef _CLIST_ITERATOR_H
#define _CLIST_ITERATOR_H

template <typename T>
class clist_iterator
{
public:
  clist_iterator()
  {
    node = NULL;
  }

  clist_iterator(clist_node<T>* n)
  {
    node = n;
  }

  clist_iterator(clist_iterator& ci)
  {
    node = ci.node;
  }

  ~clist_iterator() {}
  
  clist_iterator& operator=(const clist_iterator& rhs)
  {
    if(this != &rhs)
    {
      node = rhs.node;
    }
    return *this;
  }

  bool operator==(const clist_iterator& other) const
  {
    if(other.node == node) { return true; }
    return false;
  }

  bool operator!=(const clist_iterator& other) const
  {
    return !(*this == other);
  }

  T value() { return node->get_value(); }

  T operator*()
  {
    return node->get_value();
  }

  T operator->()
  {
    return node->get_value();
  }
  
  // prefix ++
  clist_iterator& operator++()
  {
    node = node->get_next();
    return *this;
  }

  // postfix ++
  clist_iterator operator++(int)
  {
    clist_iterator ni = *this;
    ++(*this);
    return ni;
  }

  // prefix --
  clist_iterator& operator--()
  {
    node = node->get_prev();
    return *this;
  }
 
  // postfix --
  clist_iterator operator--(int)
  {
    clist_iterator ni = *this;
    --(*this);
    return ni;
  }

private:
  clist_node<T> *node;
};

#endif //  _CLIST_ITERATOR_H
