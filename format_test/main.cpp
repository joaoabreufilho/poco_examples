/*!
 * @file main.cpp
 *
 * @brief Show Poco format capabilities similar to fmt library.
 */
#include <Poco/Format.h>
#include <iostream>
#include <assert.h>

void testBool() {
  bool b = true;
  std::string s = Poco::format("%b", b);
  assert(s == "1");

  b = false;
  s = Poco::format("%b", b);
  /// @details Evaluate bool assertion through string
  assert(s == "0");

  std::vector<Poco::Any> bv;
  bv.push_back(false);
  bv.push_back(true);
  bv.push_back(false);
  bv.push_back(true);
  bv.push_back(false);
  bv.push_back(true);
  bv.push_back(false);
  bv.push_back(true);
  bv.push_back(false);
  bv.push_back(true);

  s.clear();
  /// @details Format boolean vector to string
  format(s, "%b%b%b%b%b%b%b%b%b%b", bv);
  std::cout << "Post format string: " << s << std::endl;
  /// @details Evaluate assertion through string
  assert(s == "0101010101");
  std::cout << "Bool string: " << s << std::endl;
}

int main(int argc, char* argv[]) {
  testBool();
  return 0;
}