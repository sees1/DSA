#include <vector>
#include <string>

class ATM {
public:
  ATM() : cash(5, 0) { }

  void deposit(std::vector<int> banknotes)
  {
    for(size_t i = 0; i < banknotes.size(); ++i)
    {
      cash[i] += banknotes[i];
    }
  }

  std::vector<int> withdraw(int amount)
  {
    std::vector<int> res(5, 0);

    while (amount / 500 && cash[4] != 0)
    {
      amount -= 500;
      ++res[4];
      --cash[4];
    }
    while (amount / 200 && cash[3] != 0)
    {
      amount -= 200;
      ++res[3];
      --cash[3];
    }
    while (amount / 100 && cash[2] != 0)
    {
      amount -= 100;
      ++res[2];
      --cash[2];
    }
    while (amount / 50 && cash[1] != 0)
    {
      amount -= 50;
      ++res[1];
      --cash[1];
    }
    while (amount / 20 && cash[0] != 0)
    {
      amount -= 20;
      ++res[0];
      --cash[0];
    }

    if (amount != 0)
    {
      deposit(res);
      return {-1};
    }

    return res;
  }

private:
  std::vector<int> cash;
};

int main() {
  ATM a;

  a.deposit({0, 0, 1, 2, 1});
  a.withdraw(600);
  a.deposit({0, 1, 0, 1, 1});
  a.withdraw(600);
  a.withdraw(550);
}