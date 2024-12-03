class Solution {
public:
//dedicated to "kis color ki chaddi pehni hai wali aunty"
    int nthSuperUglyNumber(int n, vector<int>& primes) 
    {
         vector<int> prime(primes.size(), 1);
        vector<int> arr(n + 1);
        arr[1] = 1;
        
        for (int i = 2; i <= n; i++) 
        {
            vector<int> values;
            for (int j = 0; j < primes.size(); j++) 
            {
                values.push_back(arr[prime[j]] * primes[j]);
            }

            int mini = *min_element(values.begin(), values.end());
            arr[i] = mini;

            for (int j = 0; j < primes.size(); j++) 
            {
                if (values[j] == mini) 
                {
                    prime[j]++;
                }
            }
        }

        return arr[n];
    }
};