class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int n=s.length(),m=strs.size(),z=0,o=0;
        for(char&ch:s)
            ++(ch=='0'?z:o);
        vector<bool>res(m,false);
        for(int i=0;i<m;++i){
            int cz=0,co=0,mark=0;
            for(char&ch:strs[i]){
                if(ch=='?')
                    ++mark;
                else
                    ++(ch=='0'?cz:co);
            }
            if(cz>z||(cz+mark)<z)
                continue;
            int z_need=z-cz,cur_z_str=0,cur_z_s=0;
            bool match=1;
            for(int j=0;j<n;++j){
                if(s[j]=='0')
                    ++cur_z_s;
                char ch=strs[i][j];
                if(ch=='?'){
                    if(z_need>0){
                        --z_need;
                        ch='0';
                    }
                    else
                        ch='1';
                }
                if(ch=='0')
                    ++cur_z_str;
                if(cur_z_str<cur_z_s){
                    match=false;
                    break;
                }
            }
            if(match)
                res[i]=true;
        }
        return res;
    }
};
