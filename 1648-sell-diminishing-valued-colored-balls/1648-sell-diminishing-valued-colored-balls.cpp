class Solution {
public:
// bool g(int m, priority_queue<int> pq, int orders)
// {
//     //now we want to maximise profit, the m here denotes number of balls
//     //if we can make m within the orders numbers of balls, then it's fine
    


// }
    int maxProfit(vector<int>& inventory, int orders) {
        int l=0,r=INT_MAX;
        priority_queue<int>pq;
        for(int i=0;i<inventory.size();i++)
        {
            pq.push(inventory[i]);
        }
        // while((r-l)>1)
        // {
        //     int m = (l + ((r-l)/2));
        //     if(g(m,pq,orders))
        //     {
        //         l=m;
        //     }
        //     else
        //     {
        //         r=m;
        //     }
        // }

        // return l;

        long long curr_orders=0;
        long long balls_taken=0;
        const int MOD = 1000000007;

        while(!pq.empty() && balls_taken < orders)
        {
            int curr = pq.top();
            pq.pop();

            int count = 1;

            // count how many same max elements
            while(!pq.empty() && pq.top() == curr)
            {
                pq.pop();
                count++;
            }

            int curr_2 = pq.empty() ? 0 : pq.top();

            long long height = curr - curr_2;
            long long total_can_take = height * count;
            long long balls_that_can_be_taken = orders - balls_taken;

            if(total_can_take <= balls_that_can_be_taken)
            {
                // take full block
                long long sum = ( (long long)curr*(curr+1)/2 - (long long)curr_2*(curr_2+1)/2 ) % MOD;
                curr_orders = (curr_orders + (sum * count) % MOD) % MOD;
                balls_taken += total_can_take;
            }
            else
            {
                // partial take
                long long full_levels = balls_that_can_be_taken / count;
                long long rem = balls_that_can_be_taken % count;

                long long next_val = curr - full_levels;

                // sum from curr to next_val
                long long sum = ( (long long)curr*(curr+1)/2 - (long long)next_val*(next_val+1)/2 ) % MOD;
                curr_orders = (curr_orders + (sum * count) % MOD) % MOD;

                // remaining
                curr_orders = (curr_orders + (rem * next_val) % MOD) % MOD;

                break;
            }

            // push back reduced values
            if(curr_2 > 0)
            {
                for(int i=0;i<count;i++)
                    pq.push(curr_2);
            }
        }

        return curr_orders % MOD;
    }
};