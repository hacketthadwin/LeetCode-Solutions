class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int m = potions.size();
        vector<int> ans;

        for (int spell : spells) {
            long long threshold = (success + spell - 1) / spell;
            auto it = lower_bound(potions.begin(), potions.end(), threshold);
            ans.push_back(m - (it - potions.begin()));
        }

        return ans;
    }
};