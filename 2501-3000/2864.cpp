class Solution {
public:
   string maximumOddBinaryNumber(string s) {
    int oneCount= -1;
    string ans = "";
    for(auto c: s){ oneCount += (c == '1')?1:0; }
    for(int i = 0; i < s.size(); ++i, --oneCount){
        ans +=  (oneCount > 0)?'1':'0';
    }
    ans.pop_back();
    return ans + '1';
}
};
