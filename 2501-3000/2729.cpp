class Solution {
public:
    bool isFascinating(int n) {
        string str = "";
        int a = n*2,b=n*3;
        str = to_string(n)+to_string(a)+to_string(b);
        vector<int> v(10,0);
        for(auto &i: str){
            v[i-'0']++;
        }
        for(int i = 0; i < 10; i++){
            if(i==0){
                if(v[i])return false;
            }else{
                if(v[i]!=1)return false;
            }
        }
        return true;
    }
};
