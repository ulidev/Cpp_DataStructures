#ifndef _BST_HPP_
#define _BST_HPP_

template <typename T>
class BST {

private:
  struct BST_Node {
    T data;
    BST_Node *right;
    BST_Node *left;
  };

  BST_Node *_root;
  int _size;

  BST_Node* _insert(BST_Node *n, T data);
  void _delete(BST_Node *n);
  BST_Node* _copy(BST_Node *n);
  BST_Node* _sum_nodes(BST_Node *pi_node, BST_Node *p_node);

public:

  /* Iterator */
  friend class iterator;
  class iterator {
    friend class BST;

  public:
    iterator();
    iterator(const iterator &it);
    iterator& operator=(const iterator &t);
    ~iterator();

    T operator*() const;
    iterator left() const;
    iterator right() const;
    operator bool() const;

  private:
    BST<T>::BST_Node *_root;
  };
  /* End iterator */

  BST();
  BST(const BST &tree);
  BST& operator=(const BST &tree);
  BST operator+(const BST &tree);
  ~BST();

  int size() const;
  void insert(T data);

  iterator root() const;
};

#include "BST.t"
#endif
