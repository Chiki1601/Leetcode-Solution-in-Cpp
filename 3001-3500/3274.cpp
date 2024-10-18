class Solution {
public:
    bool checkTwoChessboards(string c1, string c2) {
        int s1 = c1[0]-'a'+c1[1]-'0';
        int s2 = c2[0]-'a'+c2[1]-'0';
        if(s1%2==s2%2)
            return 1;
        return 0;
    }
};
