class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals, int len) {
        if (intervals.empty()) return {};
        int n = intervals.size();

        vector<vector<int>> res;
        res.push_back(intervals[0]);

        for(int i=1; i<n; i++){
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];

            if(currStart <= res.back()[1] && (currStart - res.back()[0] + 1) <= len) res.back()[1] = max(res.back()[1], currEnd);
            else res.push_back(intervals[i]);
        }
        return res;
    }
    
    bool isPoss(string s, int op, int mid){
        int n = s.size();
        int i=0, j = 0;
        int zero = 0, one = 0;
        vector<vector<int>> intervals;
        while(j < n){
            if(s[j] == '0') zero++;
            else one++;
            
            while((j - i + 1) > mid){
                if(s[i] == '0') zero--;
                else one--;
                i++;
            }
            
            if((j - i + 1) == mid){
                if(!zero || !one){
                    intervals.push_back({i, j});
                }
            }
            j++;
        }
        

        vector<vector<int>> merged = merge(intervals, mid);
        return merged.size() <= op;
    }
    
    int getMini(string s, char even, char odd){
        int n = s.size();
        int op = 0;
        for(int i=0; i<n; i++){
            if(i % 2 && s[i] != odd) op++;
            else if(i % 2 == 0 && s[i] != even) op++;
        }
        return op;
    }
    
    int minLength(string s, int numOps) {
        int n = s.size();
        int start = 3, end = n;
        int res = 2;
        
        int op = n+1;
        op = min(op, getMini(s, '0', '1'));
        op = min(op, getMini(s, '1', '0'));
        if(op <= numOps) return 1;
        
        while(start <= end){
            int mid = (start) + (end - start)/2;
            bool curr = isPoss(s, numOps, mid);
            if(curr){
                end = mid - 1;
            }
            else {
                res = mid;
                start = mid + 1;
            }
        }
        return res;
    }
};
