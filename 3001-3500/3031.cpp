class Solution 
{
public:
    int minimumTimeToInitialState(string word, int k) 
    {
        int n = word.size();
        vector<int>z(n);
        int l = 0, r = 0;

        for(int i = 1; i < n; i++)
        {
            if(i < r) z[i] = min(r-i, z[i-l]); 
            while(i+z[i] < n && word[z[i]] == word[i+z[i]]) z[i]++;

            if(i+z[i] > r)
            {
                l = i;
                r = i+z[i];
            }
        }

        int ans = 0;
        for(int i = 1; i < n; i++)
        {
            if(z[i] == n-i && i %k == 0)
            {
                ans = (i+k-1)/k;
                break;
            }

            if(i == n-1) ans = (n+k-1)/k;
        }

        return ans;
    }
};
