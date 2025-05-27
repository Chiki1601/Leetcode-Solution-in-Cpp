class Solution {
public:
    string resultingString(string s) {
        stack<char> st;
        for(char& ch : s){
            if(st.empty()){
                st.push(ch);
                continue;
            }
            char currCh = st.top();
            if(abs(currCh-ch) == 1 || abs(currCh-ch) == 25)    
                st.pop();
            else
                st.push(ch);
        }
        s = "";
        while(!st.empty()){
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
