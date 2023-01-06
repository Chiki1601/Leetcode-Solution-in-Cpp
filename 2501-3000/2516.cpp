class Solution {
public:
    int takeCharacters(string s, int k) {
        if(k==0)
            return 0;
        unordered_map<int, vector<int>>mp1, mp2;// store occurance of each character at every indx
        vector<int>v(3,0);
        vector<int>v1(3,0);
        mp1[-1]=v;
        for(int i=0;i<s.size();i++){// prefix storing
            v[s[i]-'a']++;
            mp1[i]=v;
        }
    
        mp2[s.size()]=v1;
          for(int i=s.size()-1;i>=0;i--){// suffix storing
            v1[s[i]-'a']++;
            mp2[i]=v1;
        }
        if(v1[0]<k || v1[1]<k || v1[2]<k) // lets check for invalid condition
            return -1;
   
  
        int st=0, hg=s.size();
        int ans=-1;
    
        while(st<=hg){
            int md= st+ (hg-st)/2; // lt assum md is our  required answer
            bool flag= false;
            int n= s.size();
          
            int i=md;
            for( i=md-1;i>=-1;i--){ // checking that md is valid or not
                
                if((mp1[i][0]+mp2[n][0] >=k) && (mp1[i][1]+ mp2[n][1]>=k) && (mp1[i][2]+mp2[n][2]>=k) ){ // check that every occurance of character is greater than k or not by taking i character for starting index  and md-i charcter form backword side
                    flag= true;
                    break; // if condition true break;
                }
                n--;
              
            }
         
                if(flag){
                    ans=i+1 + s.size()-n; // if md is valid it means it is our answr and check that can we reduce our search space
                    hg=md-1;
                }
                else{
                    st=md+1; // if md is less than our required answer than that time we need to increase our search space
                }
          
            
        }
       
        return ans; // final answer
        
    }
};
