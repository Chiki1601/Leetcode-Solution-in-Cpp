class Solution {
public:
    class Node{
        public:
            int ind;
            Node* child[26];
            Node(int idx) {  
                ind = idx;
                for(int i = 0; i < 26; ++i) child[i] = NULL;
            }
    };
    
    void add(Node* ptr, vector<string>& wordsContainer, int i){
        for(int j = wordsContainer[i].size() - 1; j >= 0; --j){
            int c = wordsContainer[i][j] - 'a';
            if(ptr->child[c] == NULL) ptr->child[c] = new Node(i);
            ptr = ptr->child[c]; 
            if(wordsContainer[ptr->ind].size() > wordsContainer[i].size()) ptr->ind = i;
        }
    }
    
    int search(Node* ptr, string &s){
        int ans = ptr->ind;
        for(int i = s.size()-1; i >= 0; --i){
            ptr = ptr->child[s[i] - 'a'];
            if(!ptr) return ans;
            ans = ptr->ind;
        }
        return ans;
    }
    
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        vector<int> ans;
        Node* head = new Node(0);
        for(int i = 0; i < wordsContainer.size(); ++i) {
            if(wordsContainer[head->ind].size() > wordsContainer[i].size()) head->ind = i;
            add(head, wordsContainer, i);
        }
        for(auto q: wordsQuery) ans.push_back(search(head, q));
        return ans;
    }
};
