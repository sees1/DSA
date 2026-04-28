#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

struct TrieNode
{
  std::unordered_map<char, TrieNode*> child;
  int value = 0;
  bool isWord = false;
};

class Trie
{
public:
  Trie() : root(new TrieNode()) {}

  void insert(std::string word, int val = 0)
  {
    TrieNode* cur = root;
    size_t word_s = word.size();

    for(size_t i = 0; i < word_s; ++i)
    {
      if(cur->child.find(word[i]) == cur->child.end())
      {
        cur->child[word[i]] = new TrieNode();
        cur = cur->child[word[i]];
        cur->value += val;
      }
      else
      {
        cur = cur->child[word[i]];
        cur->value += val;
      }
    }
    cur->isWord = true;
  }

  std::vector<std::string> parseString(std::string sentence)
  {
    size_t sentence_s = sentence.size();

    std::vector<std::string> concl;
    std::string temp;

    for(size_t i = 0; i < sentence_s; ++i)
    {
      if(sentence[i] == ' ')
      {
        concl.push_back(temp);
        temp.clear();
        ++i;
      }

      temp += sentence[i];
    }

    return concl;
  }

  std::string unparseString(std::vector<std::string> p_sentence)
  {
    size_t p_sentence_s = p_sentence.size();

    std::string temp;
    for(size_t i = 0; i < p_sentence_s; ++i)
    {
      temp += p_sentence[i];
      temp += " ";
    }
    temp.resize(temp.size() - 1);
    return temp;
  }

  std::string replaceWords(std::vector<std::string>&& dictionary, std::string sentence)
  {
    std::for_each(dictionary.begin(), dictionary.end(),[this](auto& item){ insert(item); });
    std::vector<std::string> p_sentence = parseString(sentence);

    std::vector<std::string> out_p_sentence;
    out_p_sentence.reserve(p_sentence.size());

    std::for_each(p_sentence.begin(), p_sentence.end(), [this, &out_p_sentence](auto& item){out_p_sentence.push_back(cutSuffix(item));});
    return unparseString(out_p_sentence);
  }

  int sum(std::string prefix) {
    TrieNode* cur = root;
    size_t prefix_s = prefix.size();

    int max = 0;
    for(size_t i = 0; i < prefix_s; ++i)
    {
      if(cur->child.find(prefix[i]) == cur->child.end())
        return 0;
      else
      {
        cur = cur->child[prefix[i]];
        max = std::max(cur->value, max);
      }
    }
    
    return max;
  }

  std::string cutSuffix(std::string word)
  {
    TrieNode* cur = root;
    size_t word_s = word.size();

    std::string temp;

    for(size_t i = 0; i < word_s; ++i)
    {
      if(cur->child.find(word[i]) == cur->child.end())
      {
        if(i == 0)
          return word;
        else
          break;
      }
      else
      {
        cur = cur->child[word[i]];
        temp += word[i];
      }
    }

    return temp;
  }

  bool search(std::string word)
  {
    TrieNode* cur = root;
    size_t word_s = word.size();

    for(size_t i = 0; i < word_s; ++i)
    {
      if(cur->child.find(word[i]) == cur->child.end())
        return false;
      else
        cur = cur->child[word[i]];
    }

    if(cur->isWord)
      return true;
    else
      return false;
  }

  bool startsWith(std::string prefix)
  {
    TrieNode* cur = root;
    size_t prefix_s = prefix.size();

    for(size_t i = 0; i < prefix_s; ++i)
    {
      if(cur->child.find(prefix[i]) == cur->child.end())
        return false;
      else
        cur = cur->child[prefix[i]];
    }

    return true;
  }

public:
  TrieNode* root;
};

int main()
{
  Trie* obj = new Trie();
  obj->replaceWords({"cat","bat","rat"}, "the cattle was rattled by the battery");
}