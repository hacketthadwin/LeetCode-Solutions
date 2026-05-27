class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.size();
        unordered_map<char,vector<int>>mp;

        for(int i=0;i<n;i++) 
        {
            mp[word[i]].push_back(i);
        }

        int res=0;

        for(char ch='a';ch<='z';ch++) {
            if(mp[ch].empty() || mp[ch-32].empty()) 
            {
                continue;
            }

            int loweridx=mp[ch].back();
            int upperidx=mp[ch-32].front();

            if(loweridx<upperidx) 
            {
                res++;
            }
        }
        return res;

    }
};