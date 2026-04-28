#include <vector>
#include <algorithm>

int maxProfit(std::vector<int>& prices)
{
  int buy = prices[0];
  int profit = 0;

  std::for_each(prices.begin() + 1, prices.end(), [&buy, &profit](auto& price)
  {
    if (price < buy)
    {
      buy = price;
    } else if (price - buy > profit) {
      profit = price - buy;
    }
  });

  return profit;
}

int main() {
  std::vector<int> prices = {7, 1, 5, 3, 6, 4};

  auto res = maxProfit(prices);
}