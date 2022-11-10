
#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>

// std::array is a container that encapsulates fixed size arrays.

void test_init_array() {
  // std::array<T, N> 定义了一个大小为N的数组，数组大小在编译期间就已经确定了
  std::array<int, 5> a1 = {1, 2, 3, 4, 5};
  std::cout << "a1: ";
  std::copy(a1.begin(), a1.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;

  std::array<std::string, 2> a2 = {std::string("a"), "b"};

  for (const auto& s : a2) std::cout << s << ' ';
  std::cout << std::endl;

  // C++ 17
  std::array a3{3.0, 1.0, 4.0};  // -> std::array<double, 3>
  std::reverse_copy(a3.begin(), a3.end(),
                    std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;

  std::cout << a3.at(2) << std::endl;
  try {
    a3.at(3) = 6;  // catch std::out_of_range
  } catch (std::out_of_range const& exc) {
    std::cout << exc.what() << '\n';
  }

  std::cout << a3.data() << std::endl;
}

int main() {
  test_init_array();

  return 0;
}
