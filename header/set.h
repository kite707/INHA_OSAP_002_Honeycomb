#ifndef SET_H_
#define SET_H_

struct node {
    int key;
    node *left = nullptr;
    node *right = nullptr;
    int height = 1;
};
typedef node *NodePtr;

#endif
