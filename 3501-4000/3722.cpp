class Solution {
public:
    string lexSmallest(string s) {
       string ans=s;
        for(int k=1;k<=s.size();k++){
            string l=s;
            reverse(l.begin(),l.begin()+k);
            if(l<ans)ans=l;
        }

        for(int k=1;k<s.size();k++){
            string l=s;
            reverse(l.end()-k,l.end());
            if(l<ans)ans=l;
        }
        return ans;
    }
};
