#ifndef ADAPTOR_H_
#define ADAPTOR_H_

template <typename T>  //
class Adaptor {
 public:
  virtual ~Adaptor() = default;
  virtual T minimum(T value) = 0;
  virtual T maximum(T value) = 0;
  virtual bool empty() = 0;
  virtual int size() = 0;
  virtual int find(T value) = 0;
  virtual int insert(T value) = 0;
};
#endif