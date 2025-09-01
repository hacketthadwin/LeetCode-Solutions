class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int e) {

    //so this was a really really good problem
    //i don't know how it has 73% acceptance rate but it is not easy to come up with this idea if you haven't seen it before,
    //so my logic was wrong to add in the least pass/total ratio and then taking the min out and adding +1 to both numerator and denominator
    //it will surely increase the averageRatio but it will not be the maxAverageRatio.
    //maximum will come when we can push that which pair gives maximum gain on increment and then taking out that pair from the max heap
    //nice problem, difficult to come with this idea
    priority_queue<pair<double, pair<int,int>>> pq;   

    int n = classes.size();
    for (int i = 0; i < n; i++) 
    {
        double ratio = ((double)(classes[i][0]+1) / (classes[i][1]+1) ) - ((double)(classes[i][0]) / (classes[i][1]) );
        pq.push({ratio, {classes[i][0], classes[i][1]}});
    }

    for (int i = 1; i <=e; i++) 
    {
        auto temp = pq.top();
        pq.pop();
        
        temp.second.first++;
        temp.second.second++;
        temp.first = ((double)(temp.second.first + 1) / (temp.second.second + 1)) - ((double)(temp.second.first) / (temp.second.second));
        pq.push(temp);
    }

    double ans = 0;
    while (!pq.empty()) 
    {
        ans += ((double)pq.top().second.first/pq.top().second.second);
        pq.pop();
    }

    return (double)ans / n;

    }
};