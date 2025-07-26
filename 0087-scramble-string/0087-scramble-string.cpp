//common this was so easy problem (couldn't do on my own but my thought process method to start was correct)
//so what mistakes i made
//wrong state defination
//wrong transition
//so i defined state wrongly
//what i learned from it
//we must define our state such that it can be used to solve our subproblem uniquely
//like even if i would not have been given original problem and only state will be given, still i should be able to understand the state and the subproblem
//also my transition method was if the string becomes equal on swapping then return true
//but that was not whole problem
//if the s1 in the left is equal to s2 in the left and s1 in the right is equal to s2 in the right
//then return true
//also if s1 in the left is equal to s2 in the right and s1 in the right is equal to s2 in the left
//then also return true
//else return false
//got many things and new methods to learn from problem
class Solution {
public:
    //now let's use memoisation in this code
    unordered_map<string,bool>mp;   //yes first time i used a key different than int
    //first let's create the solve function
    bool rec(string s1,string s2)
    {
        //base case
        if(s1==s2)return true;
        //pruning case
        string temp1=s1;
        string temp2=s2;
        sort(temp1.begin(),temp1.end());
        sort(temp2.begin(),temp2.end());
        if(temp1!=temp2)return false;
        string key= s1 + "_" + s2;
        //cache check
        if(mp.count(key))return mp[key];
        //compute and transition
        int n=s1.size();
        bool ans=false;
        //we cannot take i=0 because
        //         rec("", "")         // base case returns true 
        // rec("great", "rgeat")       // AGAIN the original problem (in s1.substr(i) and s2.substr(i))
        //so it will return in infinite loop and will give runtime error 

        for(int i=1;i<n;i++)   
        {
            bool ans1=rec(s1.substr(0,i),s2.substr(0,i));
            bool ans2=rec(s1.substr(i),s2.substr(i));

            if(ans1 && ans2)
            {
                ans=true;
                break;
            }
            ans1 = rec(s1.substr(0, i), s2.substr(n - i)); // swapped
            ans2 = rec(s1.substr(i), s2.substr(0, n - i)); //n-i gives last i characters

            if(ans1 && ans2)
            {
                ans=true;
                break;
            }
        }

        return mp[key]=ans;
    }
    bool isScramble(string s1, string s2) {
        return rec(s1,s2);
    }
};