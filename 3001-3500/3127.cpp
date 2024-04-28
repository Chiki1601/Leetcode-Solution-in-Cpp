class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& v) {
        for(int i=0;i<2;i++) {
            int w=0,b=0;
            for(int j=0;j<2;j++) {
                if(v[i][j]=='W')
                    w++;
                else
                    b++;
                if(v[i+1][j]=='W')
                    w++;
                else
                    b++;
            }
            if(w>=3 || b>=3)
                return true;
            w=0,b=0;
            for(int j=1;j<3;j++) {
                if(v[i][j]=='W')
                    w++;
                else
                    b++;
                if(v[i+1][j]=='W')
                    w++;
                else
                    b++;
            }
            if(w>=3 || b>=3)
                return true;
            
        }
        return false;
    }
};
