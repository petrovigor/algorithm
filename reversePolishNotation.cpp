#include <string>
#include <stack>
#include <cctype>

#include <cassert> //tests only

#if _DEBUG
#include <iostream>
#endif //_DEBUG

//returns reverse polish notation of source string
//doesn't process unary operators
std::string ReversePolishNotation(const std::string& src) {
  std::string dst;
  std::stack<char> q;

  int n = 0;
  bool flg = 0;

  for(const auto& c : src) {
    if(std::isspace(c))
      continue;

    if(c == '(') {
      if(flg) {
        dst += std::to_string(n) + ' ';
        flg = 0;
        n = 0;
      }
      q.push(c);
    } else if(std::isdigit(c)) {
      if(!flg) {
        flg = 1;
      }
      n *= 10;
      n += static_cast<int>(c - 48);
    } else {
      if(flg) {
        dst += std::to_string(n) + ' ';
        flg = 0;
        n = 0;
      }
      if(c == ')') {
        while(!q.empty() && q.top() != '(') {
          dst += q.top();
          q.pop();
        }

        if(q.top() == '(') {
          q.pop();
        }
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
          return 0; // '('
        };

        while(!q.empty() && getOperatorPriority(q.top()) >= getOperatorPriority(c)) {
          if(q.top() != '(')
            dst += q.top();
          q.pop();
        }

        q.push(c);
      }
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
  if(flg) {
    dst += std::to_string(n) + ' ';
  }
  while(!q.empty()) {
    if(q.top() != '(')
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
  assert(ReversePolishNotation("2+3*5+9") == "2 3 5 *+9 +");
  assert(ReversePolishNotation("2*9+9+9/8/7/6/5*1*3") == "2 9 *9 +9 8 /7 /6 /5 /1 *3 *+");
  assert(ReversePolishNotation("1+2+3+4+5") == "1 2 +3 +4 +5 +");
  assert(ReversePolishNotation("1+2-3+4-5") == "1 2 +3 -4 +5 -");

  return 0;
}
