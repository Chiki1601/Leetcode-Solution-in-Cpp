class Solution {
public:
    
    void insertAndRemove(unordered_map<char,int>&mp, char toInsert, char toRemove){   // made this helper fxn for easy insert/ removal from map
        mp[toInsert]++;     // increment freq for char to be inserted
        mp[toRemove]--;     // decrement freq for char to be removed
        if(mp[toRemove]==0) mp.erase(toRemove);  // if freq of that char reaches zero, then remove the key from map
    }
	
	// Remember to pass map as address in C++   " & mp "
    
    bool isItPossible(string word1, string word2) {
        unordered_map<char,int> mp1, mp2;
        
        for(char w1: word1) mp1[w1]++;   // store freq of chars in word1 in mp1
        for(char w2: word2) mp2[w2]++;   // store freq of chars in word2 in mp2

        for(char c1='a'; c1<='z'; c1++){
            for(char c2='a'; c2<='z'; c2++){
                if(mp1.count(c1)==0 || mp2.count(c2)==0) continue; // if any of the char is not present then skip
				
                insertAndRemove(mp1, c2, c1); // insert c2 to word1 and remove c1 from word1
                insertAndRemove(mp2, c1, c2); // insert c1 to word2 and remove c2 from word2
                
                if(mp1.size()==mp2.size()) return true;  // if size of both maps are equal then possible return true
				
                // reset back the maps
                insertAndRemove(mp1, c1, c2); // insert c1 back to word1 and remove c2 from word1             
                insertAndRemove(mp2, c2, c1); // insert c2 back to word2 and remove c1 from word2
                
            }
        }
        
        return false;
    }
};
