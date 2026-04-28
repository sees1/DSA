#include <list>
#include <unordered_map>

class LRUCache {
public:
    LRUCache(int capacity) : capa(capacity) { }
    
    int get(int key) {
      auto iter = key_value.find(key);

      if (iter != key_value.end())
      {
        if (iter->second != values.begin())
        {
          values.erase(iter->second);
          values.push_front(key);
          key_value[key] = values.begin();
        }
        return *(values.begin());
      }
      else
        return -1;
    }
    
    void put(int key, int value) {
      auto iter = key_value.find(key);

      if (iter != key_value.end())
      {
        values.erase(iter->second);
        values.push_front(value);
        key_value[key] = values.begin();
      }
      else
      {
        if (values.size() == capa)
          values.pop_back();

          values.push_front(value);
          key_value[key] = values.begin();
      }
    }

private:
  int capa;
  std::list<int> values;
  std::unordered_map<int, std::list<int>::iterator> key_value;
};

int main() {
  LRUCache l(2);

  l.put(1, 1);
  l.put(2, 2);
  l.get(1);
  l.put(3, 3);
  l.get(2);
  l.put(4, 4);
  l.get(1);
  l.get(3);
  l.get(4);
}