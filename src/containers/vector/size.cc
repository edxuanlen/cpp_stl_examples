#include <iostream>
#include <iterator>
#include <vector>

int main() {
  // 创建含有整数的 vector
  std::vector<int> v = {7, 5, 16, 8};

  // 固定长度为4
  std::cout << "cap: " << v.capacity() << std::endl;  // 4
  v.push_back(25);
  v.push_back(13);
  // 动态扩容长度为2倍
  std::cout << "cap: " << v.capacity() << std::endl;  // 8

  // 手动返回多余空间
  v.shrink_to_fit();
  std::cout << "cap: " << v.capacity() << std::endl;  // 6

  v.push_back(19);  // 12

  // 主动分配更大的空间，分配小于当前capacity的空间不会起作用
  v.reserve(15);
  std::cout << "cap: " << v.capacity() << std::endl;  // 15

  std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, ", "));
  std::cout << std::endl;
}
