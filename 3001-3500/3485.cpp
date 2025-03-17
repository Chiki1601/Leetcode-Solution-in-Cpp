#define ll long long 

map<ll, ll> m;
set<ll, greater<ll>> st;

struct Node 
{
    Node *links[26];
    bool flag = false;
    
    int cnt = 0; // frequency variable. 

    bool containKey(char ch) 
    {
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node *node) 
    {
        links[ch - 'a'] = node;
    }

    Node *get(char ch) 
    {
        return links[ch - 'a'];
    }

    void setEnd() 
    {
        flag = true;
    }

    bool isEnd() 
    {
        return flag;
    }
};



class Trie 
{
public:
    Node* root;

    Trie() 
    {
        root = new Node();
    }

    void insert(string &word, int k) 
    {

        Node *node = root;
        
        
        for (int i = 0; i < word.size(); i++) 
        {
            if (!node->containKey(word[i])) 
            {
                node->put(word[i], new Node());
            }

            node = node->get(word[i]);
            node->cnt ++;
            
            if(node->cnt >= k)
            {
                m[i+1]++;
                
                if(m[i+1] == 1) // add to the set when new length with frequency over k is found.
                    st.insert(i+1);
            }
        }
        
        node->setEnd();
    }

    void erase(string &word, int k) 
    {
        Node *node = root;
        
        for (int i = 0; i < word.size(); i++) 
        {
            if (!node->containKey(word[i])) 
            {
                node->put(word[i], new Node());
            }

            node = node->get(word[i]);
            node->cnt --;
            
            if(node->cnt == k-1)
            {
                m[i+1]--;
                
                if(m[i+1] == 0)  // remove from the set when the frequency in the map becomes 0. 
                    st.erase(i+1);
            }
        }
        
        node->setEnd();
    }
};



class Solution {
public:
    vector<int> longestCommonPrefix(vector<string>& v, int k) {
        
        m.clear();
        st.clear();

        Trie* tr = new Trie;
        vector<int> res;
        
        for(ll i=0; i<v.size(); ++i)
            tr->insert(v[i], k);
        
        for(ll i=0; i<v.size(); ++i)
        {
            tr->erase(v[i], k);
            
            if(st.size() == 0) // when set is empty there is no prefix with frequency greater than or equal to k. 
                res.push_back(0);

            else
            {
                ll now = *st.begin(); // largest value in the set. 
                res.push_back(now);
            }
            
            tr->insert(v[i], k);
        }
    
        return res;
    }
};
