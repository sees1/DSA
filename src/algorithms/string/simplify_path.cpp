#include <vector>
#include <algorithm>
#include <string>
#include <stack>

std::string simplifyPath(std::string path) {
  std::stack<std::string> s;
  path = path.substr(1);

  while(!path.empty())
  {
      size_t del = path.find("/");
      if (del == 0)
      {
          path = path.substr(del + 1);
      }
      else if (del == std::string::npos)
      {
        s.push(path);
        break;
      }
      else 
      {
          std::string temp = path.substr(0, del);
          s.push(temp);
          path = path.substr(del + 1);
      }
  }

  std::vector<std::string> tokens;

  int back = 0;
  while(!s.empty())
  {
      std::string elem = s.top();
      s.pop();

      if (elem == ".")
      {
        continue;
      }
      else if (elem == "..") {
        ++back;
        continue;
      }
      else
      {
        if (back != 0)
        {
          back--;
          continue;
        }

        tokens.push_back(elem);
      }
      
  }

  std::vector<std::string> res_v;
  std::string res;

  if (tokens.empty())
    return "/";
  else
  {
    std::for_each(tokens.rbegin(), tokens.rend(), [&res](auto& elem)
    {
      res += "/";
      res += elem;
    });

    return res;
  }

}

int main() {
  std::string path = "/a/./b/../../c/";
  auto res = simplifyPath(path);
}