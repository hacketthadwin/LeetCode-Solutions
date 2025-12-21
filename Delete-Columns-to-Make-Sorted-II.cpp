1class Solution {
2public:
3    int minDeletionSize(vector<string>& strs) {
4        int n = strs.size();
5        int m=strs[0].size();
6        int ans=0;
7
8        // set<int>removed;
9        // for(int i=0;i<n-1;i++)
10        // {
11        //     bool is_sorted=true;
12        //     if(strs[i]>strs[i+1])
13        //     {
14        //         is_sorted=false;
15        //     }
16
17        //     if(!is_sorted)
18        //     {
19        //         //here we will compare which index to remove and will push that to set (if it isn't already)
20
21        //     }
22        // }
23
24        // return s.size()
25
26        //so after multiple attempts, i looked out to solution and found the approach like this (sound simple but my approach was completelely deviated from this one and therefore it is a good problem for me)
27
28        //we need to calculate the number of deletions required, what is the most fundamental process you will follow?
29        //if strs[i][j]>strs[i+1][j] , delete that index, simple?
30        //now just make one more change in this that delete this only and only if the once we checked all previous indices and they are not sorted, if they are already sorted, don't delete it..simple
31        //this is a visa type problem, can be asked in VISA
32        //now let's code
33        vector<bool>already_sorted(n-1,false);
34        for(int j=0;j<m;j++)
35        {
36            bool deleted=false;
37            for(int i=0;i<n-1;i++)
38            {
39                if(!already_sorted[i] && strs[i][j]>strs[i+1][j])
40                {
41                    deleted=true;
42                    ans++;
43                    break;
44                }
45            }
46            if(deleted)continue;
47            for(int i=0;i<n-1;i++)
48            {
49                already_sorted[i]=already_sorted[i]|(strs[i][j]<strs[i+1][j]);
50            }
51        }
52
53        return ans;
54    }
55};
56