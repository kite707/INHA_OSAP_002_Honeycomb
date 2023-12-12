// MIT License

// Copyright(c) 2023 HONEYCOMB

//     Permission is hereby granted,
//     free of charge,
//     to any person obtaining a copy of this software and associated
//     documentation files(the "Software"), to deal in the Software without
//     restriction, including without limitation the rights to use, copy,
//     modify, merge, publish
//     ,
//     distribute, sublicense, and / or sell copies of the Software,
//     and to permit persons to whom the Software is furnished to do so,
//     subject to the following conditions :

//     The above copyright notice and this permission notice shall be included
//     in all copies or substantial portions of the Software.

//     THE SOFTWARE IS PROVIDED "AS IS",
//     WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
//     INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//     FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL
//     THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
//     OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
//     ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//     OTHER DEALINGS IN THE SOFTWARE.
//
//     2023.11 HONEYCOMB
#include <iostream>
#include "../header/adaptor.h"
#include "../header/avl_tree.h"
#include "../header/bst_tree.h"
#include "../header/set.h"
#include "../source/avl_tree.cc"
#include "../source/bst_tree.cc"
#include "../source/set.cc"
using namespace std;

int main() {
  Adaptor<int>* adaptor = new AVLTree<int>;
  Set<int> set(adaptor);
  set.insert(1);
  set.insert(2);
  set.insert(3);
  set.insert(4);
  set.find(4);
  set.size();
  set.empty();
  set.maximum(2);
  set.minimum(2);
  cout << "ttt" << endl;
  set.size();
  set.erase(2);
  set.find(1);
  set.find(3);
  set.find(4);
  set.size();
  cout << "ttt" << endl;
  set.rank(3);

  /* Adaptor insert
  Adaptor<int>* ad = new AVLTree<int>;
  ad->insert(1);
  ad->insert(2);
  ad->insert(3);
  ad->insert(4);
  cout << ad->find(1) << endl;
  cout << ad->find(4) << endl;
  cout << ad->empty() << endl;
  cout << ad->size() << endl;
  */
  /*AVLTree<int> avl;
  Node<int>* root = nullptr;
  root = avl.Insert(root, 42);
  cout << root->key << endl;*/
}