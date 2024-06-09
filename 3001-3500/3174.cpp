class Solution {
public:
    string clearDigits(string s) {
        int i=0;
        int j=0;
        string ans="";
        while(i<s.length()){
            if(!isdigit(s[i])){
                ans+=s[i];
                i++;
            }else{
                i++;
                if(ans.size()>=1)
                ans.pop_back();
            }
        }
        return ans;
    }
};
