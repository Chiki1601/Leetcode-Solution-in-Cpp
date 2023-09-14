class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0, j = 0, a = str1.length(), b = str2.length();
        while(i<a && j<b){
            if(str1[i]==str2[j]){
                j++;
            }else{
                str1[i] = (((str1[i]-'a'+1)%26)+'a');
                if(str1[i]==str2[j]){
                    j++;
                }
            }
            i++;
        }
        return (j==b);
    }
};
