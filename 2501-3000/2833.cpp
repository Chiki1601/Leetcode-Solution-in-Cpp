class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int cnt=0,cnt1=0;
        for(auto it: moves){
            if(it=='L'){cnt--; cnt1--;}
            else if(it=='_'){cnt--; cnt1++;}
            else if(it=='R'){cnt++; cnt1++ ;}
        }
        return max(abs(cnt1),abs(cnt));
    }
};
