class Solution {
public:
    int longestSubarray(vector<int>& a, int k) {
        int n = a.size();
        vector<vector<int>> adj(k);
       
        
        int len = 0;
        for(int i = 0;i<n;i++){
            a[i] = (a[i]%k + k)%k;
            adj[a[i]].push_back(i);
        }

        vector<int> st(k, -2), end(k, -1);
        int s = 0;
        st[0] = -1;
        for(int i = 0;i<n;i++){
            s += a[i];
            s = s%k;
            if(st[s] == -2) st[s] = i;
            end[s] = i;

        }

        for(int i = 0;i<k;i++){
            if(end[i] != -1) len = max(len, end[i] - st[i]);
            for(int j = 0;j<k;j++){
                int newj = (j - 2*i%k + k)%k;
                if(end[j] == -1) continue;

                int l = 0, r = adj[i].size()-1;
                int it = -1;
                while(l <= r){
                    int mid = (l + r)/2;
                    if(adj[i][mid] <= end[j]){
                        it = adj[i][mid];
                        l = mid + 1;
                    }
                    else r = mid - 1;
                }

                if(it == -1) continue;

                if(st[newj] != -2 && st[newj] < it){
                    len = max(len, end[j] - st[newj]);
                }
            }
        }

        return len;
    }
};
