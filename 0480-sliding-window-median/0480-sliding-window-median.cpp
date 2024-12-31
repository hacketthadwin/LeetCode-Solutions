#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
             tree_order_statistics_node_update>
    pbds; // you can use less/greater/less_equal/greater_equal instead of
          // less<int> as per your requirement

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        pbds s;
        vector<double> ans;
        for (int i = 0; i < k; i++) {
            s.insert({nums[i], i});
        }
        bool iseven = false;
        if (k % 2 == 0)
            iseven = true;
        if (iseven) {
            double c1 = s.find_by_order((k - 1) / 2)->first;
            double c2 = s.find_by_order(k / 2)->first;
            ans.push_back((c1 + c2) / 2.0);
        } else {
            int c2 = s.find_by_order((k - 1) / 2)->first;
            ans.push_back(c2);
        }
        for (int i = k; i < nums.size(); i++) {
            s.erase({nums[i - k], i - k});
            s.insert({nums[i], i});
            if (iseven) {
                double c1 = s.find_by_order((k - 1) / 2)->first;
                double c2 = s.find_by_order(k / 2)->first;
                ans.push_back((c1 + c2) / 2.0);
            } else {
                int c2 = s.find_by_order((k) / 2)->first;
                ans.push_back(c2);
            }
        }
        return ans;
    }
};