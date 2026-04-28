#include <vector>
#include <string>
#include <iostream>

using std::vector;
    
int compress(vector<char>& chars) {
  size_t left_idx = 0;
  char current_c = chars[0];

  size_t chars_s = chars.size();

  size_t current_c_size = 0;

  for(size_t right_idx = 1; right_idx < chars_s; ++right_idx)
  {
    if(chars[right_idx] == current_c)
    {
      current_c_size++;
    }
    else
    {
      if ((current_c_size + 1) > 9)
      {
        chars[left_idx++] = current_c;
        for(const char c : std::to_string(current_c_size + 1))
          chars[left_idx++] = c;
      }
      else if (current_c_size == 0)
      {
        chars[left_idx++] = current_c;
      }
      else
      {
        chars[left_idx++] = current_c;
        chars[left_idx++] = '0' + (current_c_size + 1);
      }
      current_c = chars[right_idx];
      current_c_size = 0;
    }
  }

  if ((current_c_size + 1) > 9)
  {
    chars[left_idx++] = current_c;
    for(const char c : std::to_string(current_c_size + 1))
      chars[left_idx++] = c;
  }
  else if (current_c_size == 0)
  {
    chars[left_idx++] = current_c;
  }
  else
  {
    chars[left_idx++] = current_c;
    chars[left_idx++] = '0' + (current_c_size + 1);
  }

  return left_idx;
}

int main() 
{
  vector<char> in = {'a'
    , 'b', 'b', 'c', 'c', 'c'};

  int size = compress(in);

  std::cout << size << std::endl;

  return 0;
}