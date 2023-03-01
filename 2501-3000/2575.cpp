class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        long long int x=0;
        vector<int>ans;
        for(int i=0;i<word.size();i++)
        {
            x=x*10+(word[i]-'0');
            if(x%m==0) ans.push_back(1);else ans.push_back(0);
            x%=m;
        }
        return ans;
    }
};
