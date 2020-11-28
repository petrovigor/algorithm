#include <string>
#include <stack>

#include <cassert> //tests only

#if _DEBUG
#include <iostream>
#endif //_DEBUG

//returns reverse polish notation of source string
//doesn't check consistency expression passed
//doesn't process brackets & unary operators
std::string ReversePolishNotation(const std::string& src) {
  std::string dst;
  std::stack<char> q;

  for(const auto& c : src) {
    if(std::isdigit(c)) {
      dst += c;
    } else {
      auto getOperatorPriority = [](const char lhs) -> int {
        switch(lhs) {
          case '*':
          case '/':
            return 2;
          case '+':
          case '-':
            return 1;
        }
        return 0;
      };

      while(!q.empty() && getOperatorPriority(q.top()) >= getOperatorPriority(c)) {
        dst += q.top();
        q.pop();
      }

      q.push(c);
    }

#if _DEBUG
    std::cout << c << " ";
    auto qq = q;
    std::cout << "stack: ";
    while(!qq.empty()) {
      std::cout << qq.top() << " ";
      qq.pop();
    }
    std::cout << "dst: " << dst << " ";
    std::cout << std::endl;
#endif //_DEBUG
  }

  while(!q.empty()) {
    dst += q.top();
    q.pop();
  }

#if _DEBUG
  std::cout << dst << std::endl;
#endif //_DEBUG

  return dst;
}

int main() {

  assert(ReversePolishNotation("") == "");
  assert(ReversePolishNotation("2+3*5+9") == "235*+9+");
  assert(ReversePolishNotation("2*9+9+9/8/7/6/5*1*3") == "29*9+98/7/6/5/1*3*+");
  assert(ReversePolishNotation("1+2+3+4+5") == "12+3+4+5+");
  assert(ReversePolishNotation("1+2-3+4-5") == "12+3-4+5-");

  return 0;
}
