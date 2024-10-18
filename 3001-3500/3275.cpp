class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& v, int k) {
        priority_queue<int>q;
        vector<int>ans;
        int n = v.size();
        for(int i=0;i<n;i++) {
            q.push(abs(v[i][0])+abs(v[i][1]));
            if(q.size()>k)
                q.pop();
            if(q.size()==k) {
                ans.push_back(q.top());
            } else
                ans.push_back(-1);
        }
        return ans;
    }
};
