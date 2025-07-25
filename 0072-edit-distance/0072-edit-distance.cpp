
class Solution {
public:
    //see we have came again to our way of solving dp problems which is
    //FORMULATION
    //STATE DEFINATION
    //TRANSITION DEFINATION
    //now how can we formulate this problem
    //we see that we have been given word1 and word2, to convert from word1 to word2, we can do 3 operations
    //first we start checking from last index
    //so if the last index of both strings are matching, then do nothing
    //come to second last index
    //now if they are not matching
    //then you can do replace one character
    //either replace last character from first string or replace it from second string
    //now consider one thing also
    //adding one character to the first string is same as deleting one character from second string
    //like "abfe" and "abf" now you can either add "e" to second string or delete "e" from first string, both will result same string
    //so now we will take minimum of our answer till now and what would have happened if we delete the char from first string or add in second string
    //and again minimum of this with what would have happened if we delete the char from second string and add char to the first string
    //understand that above two operations are different...adding and deleting from each other is same but adding or deleting from different strings is different
    //now our base case will be if one string has ended but another one has still some characters. so in this case, we will return our answer as number of remaining characters from another string
    //now we have formulated our problem

    int minDistance(string word1, string word2) {
        //NOTE: In general this problem is taught in LCS (longest common subsequence) but these all are just patterns to understand the state, not putting the same thing everywhere
        //so what we got it from here
        //the state will be dp[i][j] where i is what is minimum number of operations to convert from 0 to i of first string to 0 to j of second string
        //this is same as LCS (just remember the states)
        //whenever we are given 2 strings, just think about this state only
        //now what will be our transition based upon the formulation above
        //we see that first we check if the last chars are matching or not
        //if they are matching then we simply visit to second last char i.e. dp[i][j]=dp[i-1][j-1];
        //if they are not then, dp[i][j]=dp[i-1][j-1] + 1, i.e. we replaced one of the char to make them match
        //now what if we delete the last char from first string
        //we check check by dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
        //then what would have happened if we deleted the last char from second string
        //dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
        //this was whole process
        vector<vector<int>>dp(word1.size()+5,vector<int>(word2.size()+5,-1));
        //now we see that dp[i][j] is dependent on dp[i-1][j-1], so it means both loops will start from i=1 (because if 0, then our base case will come)

        //base case
        for(int i=0;i<=word1.size();i++)
        {
            dp[i][0]=i;
        }

        for(int i=0;i<=word2.size();i++)
        {
            dp[0][i]=i;
        }

        for(int i=1;i<=word1.size();i++)
        {
            for(int j=1;j<=word2.size();j++)
            {
                int last_char_of_word1= word1[i-1];
                int last_char_of_word2= word2[j-1];
                if(last_char_of_word1==last_char_of_word2)
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }

                dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
                dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
            }
        }
        return dp[word1.size()][word2.size()];

    }
};