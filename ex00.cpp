#include <iostream>
#include <stdexcept>

using namespace std;

bool checkValid(const std::string& param) {
  // Dummy validation function
  return !param.empty();
}

void change(std::string& someParam) {
  if(someParam.empty()) {
    throw runtime_error("The parameter should not be empty");
  }
  if(!checkValid(someParam)) {
    throw runtime_error("The parameter is not valid");
  }
  //... Do something useful with someParam...
}

std::string changeAndMerge(std::string value1, std::string value2, std::string value3) {
  try {
    change(value1);
    change(value2);
    change(value3);
    return value1 + value2 + value3;
  }
  catch(const runtime_error& error) {
    cout << "Houston, we have a problem: " << error.what() << '\n';
    return "";
  }
}

int main() {
  cout << changeAndMerge("Hello", "World", "!");
  cout << changeAndMerge("", "World", "!");
  cout << changeAndMerge("Hello", "World", "");
  cout << changeAndMerge("Hello", "", "!");
  cout << changeAndMerge("", "", "");
  return 0;
}

// Exceptions vs. Error Codes: 
//   Throwing exceptions is much slower than returning error codes when an error occurs.
// Cost of Exceptions:
//   The performance cost of exceptions is only incurred when an exception is thrown.
// Non-Exceptional Case:
//   In the non-exceptional case, there is no performance cost for exceptions.
// Error Codes:
//   Returning and checking error codes always incurs a performance cost.
 
