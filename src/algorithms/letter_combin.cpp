#include <unordered_map>
#include <string>
#include <vector>

using std::string;
using std::unordered_map;
using std::vector;

class Solution {
private:
    std::unordered_map<int, std::string> num_to_letter;
public:
    
    Solution()
    {
        num_to_letter[2] = "abc";
        num_to_letter[3] = "def";
        num_to_letter[4] = "ghi";
        num_to_letter[5] = "jkl";
        num_to_letter[6] = "mno";
        num_to_letter[7] = "pqrs";
        num_to_letter[8] = "tuv";
        num_to_letter[9] = "wxyz";
    }
    
    void combinHelper(int pos, int size, std::string& digits, std::string& combin, vector<string>& res)
    {
        if (pos == size - 1)
        {
            res.push_back(combin);
            return;
        }
        
        string curr_letters = num_to_letter[digits[pos] - '0'];
        
        for(char& c : curr_letters)
        {
            combin.push_back(c);
            
            combinHelper(pos + 1, size, digits, combin, res);
            
            combin.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        std::string combin;
        vector<string> res;
        combinHelper(0, combin.size(), digits, combin, res);
        
        return res;
    }
};

int main() {
  std::string digit = "23";

  Solution s;
  s.letterCombinations(digit);
}