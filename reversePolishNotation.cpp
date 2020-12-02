#include <string>
#include <stack>
#include <cctype>

#if _DEBUG
#include <iostream>
#endif //_DEBUG

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
