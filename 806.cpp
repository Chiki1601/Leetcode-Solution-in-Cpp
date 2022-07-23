class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int lines = 1;
        int currWidth = 0;
        
        for(int i=0;i<S.length();i++) {
            if((widths[S[i]-'a'] + currWidth)<=100) {
                currWidth+=widths[S[i]-'a'];
            } else {
                lines++;
                currWidth = widths[S[i]-'a'];
            }
        }
        
        return vector<int>{lines,currWidth};
    }
};
