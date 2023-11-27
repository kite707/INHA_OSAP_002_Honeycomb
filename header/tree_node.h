/* Node struct */
template <typename T>
struct Node {
  T key;
  Node* left = nullptr;
  Node* right = nullptr;
  int height = 1;
};