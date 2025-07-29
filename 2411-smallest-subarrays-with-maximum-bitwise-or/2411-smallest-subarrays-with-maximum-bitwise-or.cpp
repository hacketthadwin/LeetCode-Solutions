class Solution {
    private:
    int setBits(int a, int b) 
    {
    return b | a;
    }
    int unsetBits(int a, int b)
    {
    return b & (~a);
    }

public:
    vector<int> smallestSubarrays(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return {};

        vector<int> max_or(n);
        max_or[n-1] = arr[n-1];
        for (int i = n - 2; i >= 0; --i) {
            max_or[i] = setBits(arr[i], max_or[i+1]);
        }

        vector<int> answer(n, 0);
        vector<int> bitCount(31, 0);   
        int temp = 0;             
        int i = 0;

        for (int j = 0; j < n; ++j) 
        {
            for (int b = 0; b < 31; ++b) 
            {
                if (arr[j] & (1 << b)) 
                {
                    if (bitCount[b]++ == 0) 
                    {

                        temp = setBits(1 << b, temp);
                    }
                }
            }

            while (i <= j && temp == max_or[i]) 
            {
                answer[i] = j - i + 1;
                for (int b = 0; b < 31; ++b) 
                {
                    if (arr[i] & (1 << b)) 
                    {
                        if (--bitCount[b] == 0) 
                        {
                            temp = unsetBits(1 << b, temp);
                        }
                    }
                }
                i++;
            }
        }

        return answer;
    }
};