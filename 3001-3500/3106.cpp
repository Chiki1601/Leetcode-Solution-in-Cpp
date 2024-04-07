class Solution
{
public:
    string getSmallestString(string s, int k)
    {
        string ans = s;
        for (char &ch : s)
        {
            int left = ch - 'a';
            int right = 'z' - ch + 1;
            int mnn = min(left, right);
            if (k >= mnn)
            {
                k -= mnn;
                ch = 'a';
            }
            else
            {
                ch = ch - k;
                k = 0;
            }
        }
        return s;
    }
};
