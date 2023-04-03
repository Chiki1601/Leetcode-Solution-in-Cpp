class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        // vector v containing values of all the alphabets.
        vector<int> v(26);
        for(int i=0; i<26; i++) v[i]=i+1;
        for(int i=0; i<chars.size(); i++){
            v[chars[i]-'a'] = vals[i];
        }
        int n = s.size();
        // vector corresponding to string s
        vector<int> vt(n);
        for(int i=0; i<s.size(); i++){
            vt[i] = v[s[i]-'a'];
        }
        int ans=0, temp=0;
        for(int i=0; i<n; i++){
            temp += vt[i];
            if(temp<0) temp=0;
            // assign maximum value to ans
            ans = max(ans, temp);
        }
        return ans;
    }
};
// PLEASE UPVOTE IF YOU LIKE THE SOLUTION.🙂
