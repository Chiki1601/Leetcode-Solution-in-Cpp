class Solution {
public:
    int similarPairs(vector<string>& words) {
        int count=0;
        for(int i=0;i<words.size();i++){
            vector<int>mapping1(26,0);
            for(auto b : words[i]){
                mapping1[b-'a']++;
            }
            
            for(int j=i+1;j<words.size();j++){
                vector<int>mapping2(26,0);
                for(auto k:words[j]){
                    mapping2[k-'a']++;
                }
                bool equal=true;
                for(int k=0;k<mapping1.size();k++){
                    if((mapping1[k]!=0 && mapping2[k]==0) || (mapping1[k]==0 && mapping2[k]!=0) ){
                        equal=false;
                        break;
                    }
                }

            if(equal) count++;
            
            }
            
        }
        return count;
    }
};
