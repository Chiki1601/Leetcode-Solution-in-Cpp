class Solution {
public:
    int minDeletion(string s, int k) {
        unordered_map<char, int> map;
        for (auto& ch : s)
            map[ch]++;
        if (map.size() <= k)
            return 0;
        
        int cnt = 0;
        
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto& [k, v] : map)
            pq.push (v);
        
        while (pq.size() > k) {
            cnt += pq.top();
            pq.pop();
        }
        return cnt;
    }
};
