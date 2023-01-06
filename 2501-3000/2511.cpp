class Solution {
public:
    int captureForts(vector<int>& forts) {
        int n = forts.size(), ans = 0;
        for(int i=0; i<n; i++) {
            if(forts[i] == 1) {
                int cnt = 0;
                int j = i-1;
                while(j >= 0) {
                    if(forts[j] == 0) cnt++;
                    else if(forts[j] == -1) {
                        ans = max(ans, cnt);
                        break;
                    }
                    else if(forts[j] == 1) break;
                    j--;
                }
                cnt = 0;
                j = i+1;
                while(j < n) {
                    if(forts[j] == 0) cnt++;
                    else if(forts[j] == -1) {
                        ans = max(ans, cnt);
                        break;
                    }
                    else if(forts[j] == 1) break;
                    j++;
                }
            }
        }
        return ans;   
    }
};
