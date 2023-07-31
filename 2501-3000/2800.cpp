class Solution {
public:
    string getMinString(string a, string b) {    //compare two string with min size or if equal then return lexicographically smaller string 
        return (a.size() < b.size() || (a.size() == b.size() && a < b) )?a : b;
    }
    
    string addTwoStrings(string &a, string &b){    //try to add b at the end of a with optimal way
        if(b.find(a) != string::npos) return b; 
        for(int i = 0; i < a.size(); ++i){
            string t1 = a.substr(i), t2 = b.substr(0,  t1.size());
            if(t1 == t2) return a + b.substr(t1.size());
        }
        return a+b;
    }
    
    string solve(string& a, string& b, string& c) {    //merge a,b first and then merge with c in sequence
        string t1 = addTwoStrings(a, b), t2 = addTwoStrings(b, a);
        string res1 = getMinString(addTwoStrings(t1, c), addTwoStrings(c, t1));
        string res2 = getMinString( addTwoStrings(t2, c), addTwoStrings(c, t2));
        return getMinString(res1, res2);
    }
    
    string minimumString(string a, string b, string c) { 
        string res = getMinString( solve(a, b, c), solve(b, c, a));
        return getMinString( res , solve(c,a,b));
    }
};
