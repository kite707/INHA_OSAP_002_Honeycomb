#include <iostream>
#include "../header/bst_tree.h"
#include "../source/bst_tree.cc"

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    BinarySearchTree<int> tree;
    int Q;
    cin >> Q;
    string s;
    int n;
    for (int i = 0; i < Q; i++) {
      cin >> s;
      if (s == "insert") {
        cin >> n;
        tree.insert(tree.getRoot(), n);
        cout << tree.findDepthByValue(n) << "\n";
      }
    }
  }

  // tree.SelectMenu();

  return 0;
}