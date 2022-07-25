class Solution {
public:
    string decodeMessage(string key, string message) {
        string ans="";
        vector<bool> v(26,false);
        map<char,char> m;
        char ch='a';
        for(auto x:key){
            if(x>='a' && x<='z' && v[x-'a']==false && ch<='z'){
                v[x-'a']=true;
                m[x]=ch;
                ch++;
            }
        }
        
        for(auto x:message){
            if(x>='a' && x<='z'){
                ans+=m[x];
            }
            else{
                ans+=x;
            }
        }

        return ans;
    }
};
