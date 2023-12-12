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

#include "../header/set.h"
#include <iostream>
#include "../header/adaptor.h"

using namespace std;

template <typename T>
Set<T>::Set(Adaptor<T>* adaptor) : adaptor_(adaptor){};

template <typename T>
void Set<T>::insert(T value) {
  cout << adaptor_->insert(value) << '\n';
}

template <typename T>
int Set<T>::find(T value) {
  int result = adaptor_->find(value);
  cout << result << '\n';
  return result;
}

template <typename T>
int Set<T>::size() {
  int size = adaptor_->size();
  cout << size << '\n';
  return size;
}

template <typename T>
bool Set<T>::empty() {
  bool boolean_empty = adaptor_->empty();
  cout << boolean_empty << '\n';
  return boolean_empty;
}

template <typename T>
T Set<T>::maximum(T value) {
  T maximumValue = adaptor_->maximum(value);
  cout << maximumValue << " " << adaptor_->find(maximumValue) << "\n";
}

template <typename T>
T Set<T>::minimum(T value) {
  T minimumValue = adaptor_->minimum(value);
  cout << minimumValue << " " << adaptor_->find(minimumValue) << "\n";
}

template <typename T>
int Set<T>::erase(T value) {
  int result = adaptor_->erase(value);
  cout << result << "\n";
  return result;
}

template <typename T>
int Set<T>::rank(T value) {
  int depth = adaptor_->find(value);
  if (depth == 0) {
    cout << depth << "\n";
    return depth;
  }
  cout << depth << " " << adaptor_->rank(value) << "\n";
  return adaptor_->rank(value);
}
