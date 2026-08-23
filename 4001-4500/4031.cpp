class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        set<int> st;

        for(int i=lower;i<=upper;i++){
            st.insert(i);
        }
        for(int i : nums){
            st.erase(i);
        }

        vector<vector<int>> ans;
        for(int i : st){
            ans.push_back({i,i});
        }

        vector<vector<int>> fa;

        for(auto& p : ans){
            if(fa.empty() || fa.back()[1] < p[0]-1){
                fa.push_back(p);
            }else{
                fa.back()[1] = max(fa.back()[1],p[1]);
            }
        }
        return fa;
    }
};
