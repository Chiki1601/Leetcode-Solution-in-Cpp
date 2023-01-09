class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        long long score = 0;
        for(auto it : nums) {
            pq.push(it);
        }
        
        while(k--){
            int top = pq.top(); // max element
            int add;
            if(top % 3 == 0) add = top / 3;
            else add = top/3 + 1;
            
            score += top;
            pq.pop();
            pq.push(add); // ceil(top/3)
        }
        
        return score;
    }
};
