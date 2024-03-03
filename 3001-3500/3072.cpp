#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    oset;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        oset o1, o2;
        vector<int> arr1, arr2;
        o1.insert(nums[0]);
        o2.insert(nums[1]);
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        for (int i = 2; i < nums.size(); i++) {
            int val = nums[i];
            int a = o1.order_of_key(val + 1), b = o2.order_of_key(val + 1);
            a = o1.size() - a;
            b = o2.size() - b;
            if (a > b) {
                o1.insert(val);
                arr1.push_back(val);
            } else if (a < b) {
                o2.insert(val);
                arr2.push_back(val);
            } else {
                if (o2.size() < o1.size()) {
                    o2.insert(val);
                    arr2.push_back(val);
                } else {
                    o1.insert(val);
                    arr1.push_back(val);
                }
            }
        }
        for (int i : arr2)
            arr1.push_back(i);
        return arr1;
    }
};
