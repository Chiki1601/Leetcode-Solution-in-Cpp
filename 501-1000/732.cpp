class MyCalendarThree {
 public:
  int book(int start, int end) {
    ++timeline[start];
    --timeline[end];

    int ans = 0;
    int activeEvents = 0;

    for (const auto& [_, count] : timeline) {
      activeEvents += count;
      ans = max(ans, activeEvents);
    }

    return ans;
  }

 private:
  map<int, int> timeline;
};


/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
