class Solution
{
public:
   bool isPossible(int target, multiset<int> &st)//try to find if it 
   {         //is possible to find target with sum of smaller value
      vector<int> arr;
      while (st.size() && (*st.begin()) < target)
      {
         arr.push_back(*st.begin());
         st.erase(st.begin());
      }
    //applied sliding window
      int i = 0;
      int sum = 0;
      int x = -1, y = -1;
      for (int j = 0; j < arr.size(); j++)
      {
         sum += arr[j];
         while (sum > target)
         {
            sum -= arr[i++];
         }
         if (sum == target)
         {
            x = i;
            y = j;
            break;
         }
      }
  
      for (int i = 0; i < arr.size(); i++)
      {
         if (i >= x && i <= y)
            continue;
         st.insert(arr[i]);//we will delete that window from set
      }
      if (x != -1)
         return true;
      else
         return false;
   }
   int operation(multiset<int> &temp, int target)
   {
      int ans = 0;
      auto val = temp.lower_bound(target);
      if (val == temp.end())
         return 0;
      int x = *val;
      while (x > target)
      {
         ans++;
         temp.erase(temp.find(x));
         x /= 2;
         temp.insert(x);
         temp.insert(x);
      }
      temp.erase(temp.find(target));
      return ans;
   }
   int minOperations(vector<int> &nums, int target)
   {
      set<int> st;
      for (int i = 0; i < 32; i++)
      {
         if (target & (1 << i))
         {
            int val = pow(2, i);
            st.insert(val);
         }
      }
      multiset<int> temp(nums.begin(), nums.end());
      int ans = 0;
      while (temp.size() && st.size())
      {
         int val = *st.begin();
         if (temp.count(val))
         {
            temp.erase(temp.find(val));
            st.erase(st.begin());
         }
         else if (*temp.begin() > val)
         {
            ans += operation(temp, val);
            st.erase(st.begin());
         }
         else
         {
            if (isPossible(*st.begin(), temp))
            {
               st.erase(st.begin());
               continue;
            }
            else
            {
               int op = operation(temp, val);
               if (!op)
                  return -1;
               ans += op;
               st.erase(st.begin());
            }
         }
      }
      return st.size() == 0 ? ans : -1;
   }
};
