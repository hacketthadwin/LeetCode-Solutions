struct State {
    long long count = 0;
    long long sum_Z = 0;
    long long sum_Z_sq = 0;
};

class Solution {
    int OFFSET;
    vector<State> bitA;
    vector<State> bitB;

    void add(vector<State>& bit, int idx, long long Z, long long sign)
    {
        long long Z_sq = Z * Z;
        for (; idx < bit.size(); idx += idx & -idx)
        {
            bit[idx].count += sign;
            bit[idx].sum_Z += sign * Z;
            bit[idx].sum_Z_sq += sign * Z_sq;
        }
    }

    State query(vector<State>& bit, int idx)
    {
        State res;
        if (idx <= 0) return res;
        if (idx >= bit.size()) idx = bit.size() - 1;
        for (; idx > 0; idx -= idx & -idx)
        {
            res.count += bit[idx].count;
            res.sum_Z += bit[idx].sum_Z;
            res.sum_Z_sq += bit[idx].sum_Z_sq;
        }
        return res;
    }

    long long eval(vector<State>& bit, long long C, int offset)
    {
        State st = query(bit, C + offset);
        if (st.count == 0 && st.sum_Z == 0 && st.sum_Z_sq == 0) return 0;
        
        long long term1 = (C * C + 3 * C + 2) * st.count;
        long long term2 = (-2 * C - 3) * st.sum_Z;
        long long term3 = st.sum_Z_sq;
        
        return (term1 + term2 + term3) / 2;
    }

public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        //so my approach for this is simple mathematics...first find the position of each target in the nums
        //so i need to find total number
        //so i can do it properly if i am able to store all the windows storing 2 continously...then in that i will add the answer till last window...so basically answer will be going to add for each window...like a prefix sum

        vector<pair<int,int>> window_idx;
        for(int i = 0; i < (int)nums.size();)
        {
            if(nums[i] == target)
            {
                //capture contigous window
                int st = i;
                while(i < (int)nums.size() && nums[i] == target)
                {
                    i++;
                }
                int end = i;
                window_idx.push_back({st, end});
            }
            else
            {
                i++;
            }
        }

        //so window has been captured now...
        int W = window_idx.size();
        if(W == 0) return 0LL;

        //precompute window sizes and gap information
        vector<long long> wsz(W), gap_left(W), gap_right(W);
        vector<long long> gap_internal(W > 1 ? W - 1 : 0, 0LL);

        for(int i = 0; i < W; i++)
            wsz[i] = window_idx[i].second - window_idx[i].first;

        for(int i = 0; i < W; i++)
        {

            gap_left[i]  = (i == 0) ? window_idx[0].first : window_idx[i].first - window_idx[i-1].second;                
            gap_right[i] = (i == W-1) ? (int)nums.size() - window_idx[i].second  : window_idx[i+1].first - window_idx[i].second;
                                      
        }

        for(int i = 0; i < W - 1; i++)
            gap_internal[i] = window_idx[i+1].first - window_idx[i].second;

        int n = nums.size();
        OFFSET = n + 2; 
        bitA.assign(2 * n + 5, State());
        bitB.assign(2 * n + 5, State());

        long long ans = 0;
        long long current_T = 0;
        long long current_N = 0;

        for(int j = 0; j < W; j++)
        {
            long long T_single = wsz[j];  
            long long A_single = wsz[j] - 1; 
            long long B_single = wsz[j] - 1;
            long long L_minus_1 = gap_left[j] - 1;  
            long long R_minus_1 = gap_right[j] - 1;
            
            ans += countPairs(T_single, A_single, B_single);
            ans += countPairs(T_single - 1, L_minus_1, B_single);
            ans += countPairs(T_single - 1, A_single, R_minus_1);
            ans += countPairs(T_single - 2, L_minus_1, R_minus_1);

            if (j > 0)
            {
                current_T += wsz[j];
                current_N += gap_internal[j-1];
                
                long long X = current_T - current_N; 
                long long B = wsz[j] - 1;
                long long R_m_1 = gap_right[j] - 1;

                // Call 1 equivalent logic across Fenwick Tree A
                ans += eval(bitA, X - 1, OFFSET);
                ans -= eval(bitA, X - B - 2, OFFSET);

                // Call 2 equivalent logic across Fenwick Tree B
                ans += eval(bitB, X - 2, OFFSET);
                ans -= eval(bitB, X - B - 3, OFFSET);

                // Call 3 equivalent logic across Fenwick Tree A
                ans += eval(bitA, X - 2, OFFSET);
                ans -= eval(bitA, X - R_m_1 - 3, OFFSET);

                // Call 4 equivalent logic across Fenwick Tree B
                ans += eval(bitB, X - 3, OFFSET);
                ans -= eval(bitB, X - R_m_1 - 4, OFFSET);
            }

            long long Y = current_T - current_N - wsz[j]; 
            
            // Register this window for future queries
            add(bitA, Y + OFFSET, Y, 1);
            add(bitA, Y + wsz[j] + OFFSET, Y + wsz[j], -1);

            add(bitB, Y + OFFSET, Y, 1);
            add(bitB, Y + gap_left[j] + OFFSET, Y + gap_left[j], -1);
        }

        return ans;
    }

private:

    long long countPairs(long long S, long long A, long long B)
    {
        if(S <= 0 || A < 0 || B < 0) return 0;
        long long M = S - 1; 
        return tri(M) - tri(M - A - 1) - tri(M - B - 1) + tri(M - A - B - 2);
    }

    long long tri(long long M)
    {
        if(M < 0) return 0;
        return (M + 1) * (M + 2) / 2;
    }
};