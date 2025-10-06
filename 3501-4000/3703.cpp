class Solution {
public:
    string removeSubstring(string s, int k) {
        string ans;
        for(auto it:s){
            ans.push_back(it);
            int size=ans.size();
            if(size>=2*k){
                bool valid=true;
                for(int i=0;i<k;i++){
                    if(ans[size-2*k+i]!='('){
                        valid=false;
                        break;
                    }
                    if(ans[size-k+i]!=')'){
                        valid=false;
                        break;
                    }
                }
                if(valid){
                    ans.resize(size-2*k);
                }
            }
        }
        return ans;
    }
};
