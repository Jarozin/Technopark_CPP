#include <iostream>
#include <memory>

#include "ICalculatable.hpp"
#include "Parse.hpp"
int main() {
  std::string a("-2");
  std::unique_ptr<ICalculatable> res = ParseInput(a);
  std::cout << res->Calculate() << std::endl;
  return 0;
}
