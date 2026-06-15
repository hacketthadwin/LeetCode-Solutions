class Solution {
public:
    int candy(vector<int>& ratings) {
        //so my first approach will be to increase the candies count linearly first after sorting...then i will again loop in to compute if it can be decreased or not

        unordered_map<int,int>mp;
        vector<int>sorted_ratings=ratings;
        sort(sorted_ratings.begin(),sorted_ratings.end());
        int rank=1;
        for(int i=0;i<ratings.size();i++)
        {
            if(i>0 && sorted_ratings[i]>sorted_ratings[i-1]) rank++;
            mp[sorted_ratings[i]]=rank;
        }

        vector<int>candies(ratings.size(), 1);
        for(int i=1;i<ratings.size();i++)
        {
            if(ratings[i]>ratings[i-1])
            {
                candies[i]=candies[i-1]+1;
            }
        }
        for(int i=ratings.size()-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1])
            {
                candies[i]=max(candies[i],candies[i+1]+1);
            }
        }

        for(int i=0;i<ratings.size();i++)
        {
            
            bool lower_one_true=false;
            bool higher_one_true=false;
            if(i>0)
            {
                //i can decrement
                //will consider i-1 case here
                
                if(ratings[i]<=ratings[i-1])
                {
                    lower_one_true=true;
                }

            }
            else lower_one_true=true;
            if(i<(ratings.size()-1))
            {
                //will consider i+1 case here
                if(ratings[i]<=ratings[i+1])
                {
                    higher_one_true=true;
                }
            }
            else higher_one_true=true;

            //now will evaluate based on the true of lower and higher one
            if(lower_one_true && higher_one_true && candies[i] > mp[ratings[i]])
            {
                candies[i]=1;
            }

        }

        int total_candies=0;
        for(int i=0;i<candies.size();i++)
        {
            total_candies+=candies[i];
        }
        return total_candies;
    }
};