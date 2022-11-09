
class StockSpanner {
 public:
  int next(int price) {
    int span = 1;
    while (!stack.empty() && stack.top().first <= price)
      span += stack.top().second, stack.pop();
    stack.emplace(price, span);
    return span;
  }

 private:
  stack<pair<int, int>> stack;  // (price, span)
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
