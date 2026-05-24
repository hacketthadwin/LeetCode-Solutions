class Solution {
public:
    int passwordStrength(string password) {
        int ans=0;
        map<char,bool>mp;
        for(int i=0;i<password.size();i++)
        {
            if(mp[password[i]])continue;
                mp[password[i]]=true;
                if(password[i]>='a' && password[i]<='z')ans++;
                if(password[i]>='A' && password[i]<='Z')ans+=2;
                if(password[i]>='0' && password[i]<='9')ans+=3;
                if(password[i]=='!' || password[i]=='@' || password[i]=='#' || password[i]=='$')ans+=5;
            
        }
        return ans;
    }
};