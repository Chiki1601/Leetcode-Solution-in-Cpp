class Solution{
public:
    vector<int> gcdValues(vector<int>& v, vector<long long>& q){
        int n = v.size();
        int maxx = *max_element(v.begin(), v.end());
        vector<int> cntDivisors(maxx + 1, 0);
        for(auto x : v){
            for(int i = 1; i * i <= x; i++){
                if(x % i == 0){
                    cntDivisors[i]++;
                    if(i != x / i){
                        cntDivisors[x / i]++;
                    }
                }
            }
        }
        vector<long long int> gcdCount(maxx + 1, 0);
        for(int g = maxx; g >= 1; g--){
            long long int count = cntDivisors[g];
            gcdCount[g] = 1ll * count *(count - 1) / 2;
            for(int mult = 2 * g; mult <= maxx; mult += g){
                gcdCount[g] -= gcdCount[mult];
            }
        }
        
        vector<long long int> pref(maxx + 1, 0);
        for(int g = 1; g <= maxx; g++){
            pref[g] = pref[g - 1] + gcdCount[g];
        }
        vector<int> ans;
        for(auto q : q){
            long long int left = 1, right = maxx, answer = -1;
            while(left <= right){
                long long int mid =(left + right) / 2;
                if(pref[mid] > q){
                    answer = mid;
                    right = mid - 1;
                } else{
                    left = mid + 1;
                }
            }
            ans.push_back(answer);
        }

        return ans;
    }
};
