class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char,int>mp;
        for( auto s:text)
        {
            mp[s]++;
        }

        //what i want
        int b=1;
        int a=1;
        int l=2;
        int o=2;
        int n=1;

        int mini=INT_MAX;
        int got_b=mp['b'];
        int got_a=mp['a'];
        int got_l=mp['l'];
        int got_o=mp['o'];
        int got_n=mp['n'];

        if(got_b==0 || got_a==0 || got_l==0 || got_o==0 || got_n==0)
        {
            return 0;
        }
        return min({got_b/b,got_a/a,got_l/l,got_o/o,got_n/n});
        
    }
};