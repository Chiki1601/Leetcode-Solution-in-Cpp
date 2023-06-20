class Solution
{
	public:
		string smallestString(string s)
		{
			bool flag = 0;
			if (s.size() == 1)
			{
				if (s[0] == 'a') s[0] = 'z';
				else s[0] = s[0] - 1;
				return s;
            }
			for (int i = 0; i < s.size(); i++)
			{
				if (s[i] != 'a')
				{
					flag = 1;
					s[i] = s[i] - 1;
				}
				else if (flag) break;
			}
			if (flag == false)
				s[s.size() - 1] = 'z';
			return s;
		}
};
