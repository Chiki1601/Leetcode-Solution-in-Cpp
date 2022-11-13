class Solution {
public:
    string reverseWords(string s) {
        stack <string> st;
        for(int i=0; i<s.length(); i++){
            while(s[i]==' '){
                i++;
            }
            string word="";
            while (s[i]!=' ' && i<s.length()){
                if(s[i]==' '){
                    break;
                }                                                   
                else{
                word+=s[i];
                }
                i++;
            }
            st.push(word);
        }
        string ans="";
        while(!st.empty()){
            if(ans==""){
                ans=st.top();                                                          
                st.pop();
            }
            else{
                ans=ans+' '+st.top();
            st.pop();
            }
            
        }
       
        
        
        return ans;
    }
};
