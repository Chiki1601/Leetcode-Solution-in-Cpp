class Solution {
public:
    
    int kk;
    int dp[11][2][20][100];
    int dp1[11][20][100];
    
    
    int solve(int index, int tight, int even, int val, string &s)
    {
        if(index>s.size()){
             if(2*even == s.size() && val==0){
                return 1;
            }
            return 0;
        }
        if(dp[index][tight][even][val]!=-1)
            return dp[index][tight][even][val];
        
        int add=0;
        
        if(tight){
            for(int i=0; i<= (s[index-1]-'0') ; i++)
            {
                if(index==1 && i==0)continue;
                
                int num= val*10+i;
                add+= solve(index+1, (i==s[index-1]-'0'), even+ (i%2 == 0), num%kk, s );
            }
        }
        else{
            for(int i=0; i<=9; i++)
            {
                if(index==1 && i==0)continue;
                
                int num= val*10+i;
                add+= solve(index+1, 0, even+ (i%2==0), num%kk, s );
            }
        }
        
        return dp[index][tight][even][val]= add;
    }
    
    int solve1(int index, int even, int val, int len)
    {
        if(index>len){
            if(2*even == len && val==0){
                return 1;
            }
            return 0;
        }
        
        if(dp1[index][even][val]!=-1)
            return dp1[index][even][val];
        
        
        int add=0;
        
        for(int i=0; i<=9; i++)
        {
            if(index==1 && i==0)continue;
            
            if(i%2==0){
                int num= val*10+i;
                
                add+= solve1(index+1, even+1, num%kk, len);
            }
            else{
                int num= val*10+i;
                
                add+= solve1(index+1, even, num%kk, len);
            }
        }
        
        return dp1[index][even][val]= add;
    }
    
        
    int numberOfBeautifulIntegers(int low, int high, int k) {
        
        kk=k;
        string a= to_string(high);
        string b= to_string(low);
        
        int fox=0;
        
        for(int le= b.size(); le<a.size(); le++)
        {
            memset(dp1,-1,sizeof(dp1));
            fox+= solve1(1,0,0,le);
        }
         
        
        memset(dp,-1,sizeof(dp));
        
        fox+= solve(1,1,0,0,a);
    
        
        memset(dp,-1,sizeof(dp));
        int take= solve(1,1,0,0,b);
        
    
        
        fox-= take;
        
        int count=0;
        
        for(int i=0; i<b.size() ; i++)
        {
            if( (b[i]-'0')%2==0 )
                count++;
        }
        if(low%k ==0 && count*2==b.size())
            fox++;
        
        return fox;
        
    }
};
