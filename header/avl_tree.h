#ifndef AVLTREE_H_
#define AVLTREE_H_
#include "set.h"

class AVLtree{
  private:

  NodePtr Insert(NodePtr r, int item);
  NodePtr Delete(NodePtr r, int item);
  void Balancing(NodePtr &r, int item);
  NodePtr RotateRight(NodePtr y);
  NodePtr RotateLeft(NodePtr y);
  int getBalanceFactor(NodePtr r);

  public:

  int getHeight(NodePtr r);
};

#endif
