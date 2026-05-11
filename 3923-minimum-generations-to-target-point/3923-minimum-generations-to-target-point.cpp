class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
        //let's see if brute passes or not, constraint are weak though
        set<vector<int>>st;
        for(auto x:points)
        {
            st.insert(x);
        }
        int c=0;
        while(c<=15)
        {
            int n=points.size();
            for(int i=0;i<n;i++)
            {
                if(points[i][0]==target[0] && points[i][1]==target[1] && points[i][2]==target[2])
                {
                    return c;
                }
            }
            vector<vector<int>>temp;
            for(int i=n-1;i>=0;i--)
            {
                for(int j=i-1;j>=0;j--)
                {
                    int a1=points[i][0];
                    int b1=points[i][1];
                    int c1=points[i][2];
                    int a2=points[j][0];
                    int b2=points[j][1];
                    int c2=points[j][2];
                    vector<int>curr={(a1+a2)/2,(b1+b2)/2,(c1+c2)/2};
                    if(!st.count(curr))
                    {
                        st.insert(curr);
                        temp.push_back(curr);
                    }
                }
            }
            for(auto x:temp)
            {
                points.push_back(x);
            }
            c++;
        }
        return -1;
    }
};