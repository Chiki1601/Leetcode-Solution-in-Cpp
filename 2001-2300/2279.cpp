class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
          vector<int> v;
          for(int i = 0; i < rocks.size(); i++){
              v.push_back(capacity[i] - rocks[i]);
          }
        
          sort(v.begin(), v.end());
        
          int ans = 0;
          for(int i = 0; i < rocks.size(); i++){
              additionalRocks -= v[i];
              if(additionalRocks >= 0) {
                  ans++;
              }
              else break;
          }
        return ans;
    }
};
