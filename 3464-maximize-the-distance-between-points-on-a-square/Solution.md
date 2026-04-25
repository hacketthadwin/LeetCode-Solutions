# Barely Accepted Code | C++ 

# Intuition
whole intuition will come from code only, just follow 
also it is obvious from question that BS will be used

things were mistakes are possible

1. i was trying to find distance from one point to every other point and then picking the manhatten distance which went from 10^4*10^4*30, so obvious TLE
2. not doing lower bound and checking all points one by one and finding -> this is essential because in always perimeter>=manhatten distance, so you can safely choose perimeter (consider this as property)

# Complexity
- Time complexity:
O(n² log n)

- Space complexity:
O(n)

# Code
```cpp []
class Solution {
public:
bool g(vector<pair<long long,pair<int,int>>>&points, int k,int m)
{
    //the constraint are small, so that i can make an n^2 code run
    // i have to pick only maximum 25 numbers and their will be atleast 25 points
    //from each point i will pick the point greater than i+x and j+y where x+y>=m or i-x and j-y is also possible
    //or i-x and j+y or i+x and j-y
    //i.e. if i choose i=2, and m is 5, then i can choose 7,0 6,1 5,2 4,3 i.e. their sum should be 7
    //it mean for each point if i can find sum of their coordinates i can find the points i mentioned
    //nah but this will not be possible to find, also the n^2 code and fail due to overhead i guess

    int n = points.size() / 2;
    for(int p=0;p<n/2;p++)
    {
        int c=k;
        c--;
        int a=points[p].second.first;
        int b=points[p].second.second;
        int last_idx = p;
        // search limit is p + n (one full circle from p).
        if (c == 0) return true;
        for(int i=p+1;i<p+n;) 
        {
            long long target_perimeter = points[last_idx].first + m;
            auto it = lower_bound(points.begin() + i, points.begin() + p + n, make_pair(target_perimeter, make_pair(-2000000000, -2000000000)));
            
            if (it == points.begin() + p + n) break; // no more points far enough on perimeter
            i = distance(points.begin(), it);

            // after binary search, linearly scan instead of jumping back to top
            // jumping back to top was re-running lower_bound on every manhattan failure = O(n log n) per start
            for(;i<p+n;i++)
            {
                if((abs(points[i].second.first-a)+abs(points[i].second.second-b))>=m)
                {
                    //since the square is like a circle, so at last point i should check if the distance between last point and first point has manhatten distance or not
                    if(c==1)
                    {
                        if((abs(points[i].second.first-points[p].second.first)+abs(points[i].second.second-points[p].second.second))<m)
                        {
                            // i++; // manhattan check failed even though perimeter was okay,so check next point
                            continue;
                        }
                    }
                    a=points[i].second.first;
                    b=points[i].second.second;
                    last_idx = i;
                    c--;
                    i++;
                    break; // break inner loop, outer loop will binary search again from new last_idx
                }
                // else: i++ happens in for loop
                // else {
                //     i++; // manhattan check failed,so move to next neighbor
                // }
            }

            if (c == 0) return true;
        }

        if(c<=0)return true;
    }
    return false;
}
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
        long long l=0,r=1000000009;
        //according to constraint, i can have n^2 values of manhatten distance that means for each manhatten distance, i can pick the every other element and find manhatten distance between them
        //vector<vector<int>>v where v[i][j] will denote the ith index point on points array and j will denote the jth index point in the points array and then v[i][j] will denote the manhatten distance between them.
        // i am taking m as the manhatten distance
        // vector<vector<int>>v(points.size(),vector<int>(points.size(),0));
        // for(int i=0;i<points.size();i++)
        // {
        //     for(int j=0;j<points.size();j++)
        //     {
        //         int a=points[i][0];
        //         int b=points[i][1];
        //         int c=points[j][0];
        //         int d=points[j][1];
        //         v[i][j]=abs(a-c)+abs(b-d);
        //     }
        // }

        //this will give MLE 
        //the 2nd hint is the biggest way to solve this problem, as we have been given points on the boundary, we can convert them into a straight line like
        vector<int>lower_x,upper_x,left_y,right_y;
        for(int i=0;i<points.size();i++)
        {
            if(points[i][1]==0) lower_x.push_back(i);
            else if(points[i][0]==side) right_y.push_back(i);
            else if(points[i][1]==side) upper_x.push_back(i);
            else left_y.push_back(i);
        }
        //first i thought to make a single straight points containing the points in form of perimeter like which contains only the first of this vector of pair of pair, but then i found out perimeter>=manhatten distance
        vector<pair<long long,pair<int,int>>>straight_points;
        int x=0;
        int y=0;
        for(int i=0;i<lower_x.size();i++)
        {
            straight_points.push_back({points[lower_x[i]][0],{points[lower_x[i]][0],points[lower_x[i]][1]}});
        }
        // 0 2
        for(int i=0;i<right_y.size();i++)
        {
            straight_points.push_back({(long long)side+points[right_y[i]][1],{points[right_y[i]][0],points[right_y[i]][1]}});
        }
        // 0 2 3 4
        for(int i=0;i<upper_x.size();i++)
        {
            straight_points.push_back({(long long)2LL*side+(side-points[upper_x[i]][0]),{points[upper_x[i]][0],points[upper_x[i]][1]}});
        }
        // 0 2 3 4 5 
        for(int i=0;i<left_y.size();i++)
        {
            straight_points.push_back({(long long)3LL*side+(side-points[left_y[i]][1]),{points[left_y[i]][0],points[left_y[i]][1]}});
        }
        sort(straight_points.begin(),straight_points.end());
        int n = straight_points.size();
        for(int i=0; i<n; i++) {
            straight_points.push_back({straight_points[i].first + 4LL*side, straight_points[i].second});
        }

        while((r-l)>1)
        {
            int m=(l+((r-l)/2));
            if(g(straight_points,k,m))
            {
                l=m;
            }
            else
            {
                r=m;
            }
        }
        return l;
    }
};
```