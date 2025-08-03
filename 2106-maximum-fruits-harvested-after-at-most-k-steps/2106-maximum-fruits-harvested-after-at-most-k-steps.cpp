class Solution {
private:
    bool g(int m,const vector<long long>& forward,const vector<long long>& backward,int startPos,int k,long long fruitAtStart) {
        int n = forward.size();
        long long best = 0;
        for (int i = 0; i <= k; ++i) {
            int rawR = startPos + i;
            int rawL = startPos - (k - 2*i);
            int r = rawR < 0 ? 0 : (rawR >= n ? n-1 : rawR);
            int l = rawL < 0 ? 0 : (rawL >= n ? n-1 : rawL);
            best = max(best, forward[r] + backward[l] - fruitAtStart);
        }
        for (int i = 0; i <= k; ++i) {
            int rawL = startPos - i;
            int rawR = startPos + (k - 2*i);
            int l = rawL < 0 ? 0 : (rawL >= n ? n-1 : rawL);
            int r = rawR < 0 ? 0 : (rawR >= n ? n-1 : rawR);
            best = max(best, forward[r] + backward[l] - fruitAtStart);
        }
        return best >= m;
    }

public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        const int maxPos = 1'000'000;
        int n = maxPos + 1;
        vector<long long> fruit(n, 0), forward(n, 0), backward(n, 0);

        for (auto& f : fruits) {
            fruit[f[0]] = f[1];
        }

        forward[startPos] = fruit[startPos];
        for (int i = startPos + 1; i < n; ++i)
            forward[i] = forward[i - 1] + fruit[i];

        backward[startPos] = fruit[startPos];
        for (int i = startPos - 1; i >= 0; --i)
            backward[i] = backward[i + 1] + fruit[i];

        long long totalFruit = 0;
        for (auto& f : fruits) totalFruit += f[1];

        int lo = 0, hi = totalFruit + 1;
        long long fruitAtStart = fruit[startPos];
        while (hi - lo > 1) {
            int mid = lo + (hi - lo) / 2;
            if (g(mid, forward, backward, startPos, k, fruitAtStart))
                lo = mid;
            else
                hi = mid;
        }
        return lo;
    }
};
