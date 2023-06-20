    class Solution {
    public:
        int distanceTraveled(int mainTank, int additionalTank) {
            int ans=0;
                for(auto i=1;i<=mainTank;i++)
                {
                    if(additionalTank!=0 && i%5==0 )
                        {   
                            additionalTank-=1;
                            mainTank+=1;
                        }
                        ans+=10;
                }
            return ans;
        }
    };
