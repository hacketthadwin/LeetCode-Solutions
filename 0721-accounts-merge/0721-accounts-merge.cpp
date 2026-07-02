class unionfind{
    private:vector<int>p,rank;
    public:
    unionfind(int n)
    {
        rank.assign(n,0);p.assign(n,0);
        iota(p.begin(),p.end(),0);
    }
    int find_set(int i){return (p[i]==i) ? i : p[i]=find_set(p[i]);}
    bool is_same_set(int i,int j){return find_set(i)==find_set(j);}
    void union_set(int i,int j){
        if(!is_same_set(i,j))
        {
            int x=find_set(i),y=find_set(j);
            if(rank[x]>rank[y])p[y]=x;
            else
            {
                p[x]=y;
                if(rank[x]==rank[y])rank[y]++;
            }
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // map<string,int>mp;  //this denotes...this email is owned by this person
        // // map<int,set<string>>person_email_list;  //this denotes email_number
        // int curr=0;
        //what my approach i will hash all email with a specific number..then i will find the owner of that email
        // for(int i=0;i<accounts.size();i++)
        // {
        //     string name=accounts[i][0];
        //     int is_present_before=-1;
        //     int which_person_owns_this=-1;
        //     for(int j=1;j<accounts[i].size();j++)
        //     {
        //         if(mp.count(accounts[i][j]))
        //         {
        //             is_present_before=j;
        //             which_person_owns_this=mp[accounts[i][j]];
        //             break;
        //         }
                
        //     }

        //     if(is_present_before!=-1)
        //     {
        //         //it means this email list belongs to a person
        //         for(int j=1;j<accounts[i].size();j++)
        //         {
        //             person_email_list[which_person_owns_this].insert(accounts[i][j]);
        //              mp[accounts[i][j]]=which_person_owns_this;
                     
        //         }
               
        //     }
        //     else
        //     {
        //         //it means this is brand new person..so i will have to create a new list based on this person
        //         for(int j=1;j<accounts[i].size();j++)
        //         {
        //             person_email_list[i].insert(accounts[i][j]);
        //             mp[accounts[i][j]]=i;
        //         }
        //     }
        // }

        // vector<vector<string>>ans(person_email_list.size());
        // int curr_idx=0;
        // for(auto m:person_email_list)
        // {
        //     int idx=m.first;
        //     set<string>emails=m.second;
        //     ans[curr_idx].push_back(accounts[idx][0]);
        //     for(auto s:emails)
        //     {
        //         ans[curr_idx].push_back(s);
        //     }
        //     curr_idx++;
        // }

        // return ans;
        map<string,int>mp;  //this will hash the emails to make it linear id
        map<int,string>pm; //this will be used in resolution of the emails
        map<string,string>email_to_person;
        int curr=0;
        for(int i=0;i<accounts.size();i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                email_to_person[accounts[i][j]]=accounts[i][0];
                if(!mp.count(accounts[i][j]))
                {
                    mp[accounts[i][j]]=curr;
                    pm[curr]=accounts[i][j];
                    curr++;
                }
                else
                {
                    continue;
                }
            }
        }

        unionfind DSU(curr);
        for(int i=0;i<accounts.size();i++)
        {

            for(int j=1;j<accounts[i].size()-1;j++)
            {
                DSU.union_set(mp[accounts[i][j+1]],mp[accounts[i][j]]); 
            }
        }
        map<int,vector<int>>email_to_real_set;
        for(int i=0;i<accounts.size();i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                int real_set=DSU.find_set(mp[accounts[i][j]]);
                email_to_real_set[real_set].push_back(mp[accounts[i][j]]);
            }
        }

        //so mp.first will tell us one of the parent email..then we will need to fetch name of that person from the map
        vector<vector<string>>ans;
        for(auto m:email_to_real_set)
        {
            int parent_email_hash=m.first;
            vector<int>all_other_emails=m.second;

            string parent_email=pm[m.first];

            string parent=email_to_person[parent_email];
            set<string>temp;
            vector<string>temp_ans;
            temp_ans.push_back(parent);
            for(auto all_other:all_other_emails)
            {
                temp.insert(pm[all_other]);
            }
            for(auto s:temp)
            {
                temp_ans.push_back(s);
            }
            ans.push_back(vector<string>(temp_ans.begin(),temp_ans.end()));
        }

        return ans;

    }
};