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
  int T;
  cin >> T;
  while (T--) {
    int Q;
    cin >> Q;
    Adaptor<int>* adaptor = new AVLTree<int>;
    Set<int> set(adaptor);
    string s;
    int n;
    for (int i = 0; i < Q; i++) {
      cin >> s;
      if (s == "insert") {
        cin >> n;
        set.insert(n);
      }
      if (s == "find") {
        cin >> n;
        set.find(n);
      }
      if (s == "minimum") {
        cin >> n;
        set.minimum(n);
      }
      if (s == "maximum") {
        cin >> n;
        set.maximum(n);
      }
      if (s == "empty") {
        set.empty();
      }
      if (s == "size") {
        set.size();
      }
      if (s == "rank") {
        cin >> n;
        set.rank(n);
      }
      if (s == "erase") {
        cin >> n;
        set.erase(n);
      }
    }
  }
}