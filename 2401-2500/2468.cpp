class Solution {
public:
    vector<string> splitMessage(string message, int limit) {
        vector<int>dig(10001),cum(10001);// contains number of digits in N and cumulative sum of number of digits.
        // find number of digits in X.
        auto numdig=[](int x){
            int ret = 0;
            while(x){
                ret++;
                x/=10;
            }
            return ret;
        };
        for(int i=1;i<=10000;i++){
            dig[i] = numdig(i); 
            cum[i] = cum[i-1]+dig[i];
        }
        
        int actual_size = message.size();
        vector<string>ret;
        for(int i=1;i<=actual_size;i++){
            int newSize = actual_size+3*i+dig[i]*i+cum[i];
            int z = newSize - (i-1)*limit;
            
            //check if possible to achieve the result.
            if(z>0 && z<=limit){
                string s;
                int cur = 1;
                for(char&c:message){
                    s+=c;
                    if(s.size()+dig[cur]+dig[i]+3==limit){
                        s+="<"+to_string(cur)+"/"+to_string(i)+">";
                        ret.push_back(s);
                        s.clear();
                        cur++;
                    }
                }
                if(s.size()){
                      s+="<"+to_string(cur)+"/"+to_string(i)+">";
                        ret.push_back(s);
                        s.clear();
                }
                return ret;
            }
        }
        return ret;
    }
};
