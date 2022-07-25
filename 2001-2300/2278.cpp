class Solution {
    
public:
    int percentageLetter(string s, char letter) {
    
        map<char,int>mymap;
        for(int i=0;i<s.length();i++)
        {
    
            mymap[s[i]]++;
        }
        return floor((mymap[letter]*100.0)/s.length());
    }
};
