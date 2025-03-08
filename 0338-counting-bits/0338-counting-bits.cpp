class Solution {
public:
//so we have to count the number of numbers divisible by 2 in this;
    vector<int> countBits(int n) {
        int num = 1;
        vector<int> divby2;
        divby2.push_back(num);
        while (num < 1e5) {
            num *= 2;
            divby2.push_back(num);
        }
        int sz = divby2.size();
        vector<int> ans;
        for (int c = 0; c <= n; c++) {
            int cnt = 0;
            int temp = c;  
            for (int i = sz - 1; i >= 0; i--) {  
                if (temp >= divby2[i]) {
                    temp -= divby2[i];
                    cnt++;
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};