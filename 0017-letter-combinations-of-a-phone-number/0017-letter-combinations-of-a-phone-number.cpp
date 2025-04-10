class Solution {
public:
    vector<string> letterCombinations(string s) {
        int n=s.length();
        vector<string> ans;
        map<char,vector<char>> mp;
        mp['2']={'a','b','c'};
        mp['3']={'d','e','f'};
        mp['4']={'g','h','i'};
        mp['5']={'j','k','l'};
        mp['6']={'m','n','o'};
        mp['7']={'p','q','r','s'};
        mp['8']={'t','u','v'};
        mp['9']={'w','x','y','z'};
        if(n==1){
        for(auto it:mp[s[0]]){
                        string st="";
                        st+=it;
                        ans.push_back(st);
        }
        }
        else if(n==2){
         for(auto it:mp[s[0]]){
            for(auto it1:mp[s[1]]){
                        string st="";
                        st+=it;
                        st+=it1;
                        ans.push_back(st);
                    }
         }
        }
        else if(n==3){
         for(auto it:mp[s[0]]){
            for(auto it1:mp[s[1]]){
                for(auto it2:mp[s[2]]){
                        string st="";
                        st+=it;
                        st+=it1;
                        st+=it2;
                        ans.push_back(st);
                    }
                }
         }
        }
        else{
         for(auto it:mp[s[0]]){
            for(auto it1:mp[s[1]]){
                for(auto it2:mp[s[2]]){
                    for(auto it3:mp[s[3]]){
                        string st="";
                        st+=it;
                        st+=it1;
                        st+=it2;
                        st+=it3;
                        ans.push_back(st);
                    }
                }
            }
         }
        }
         return ans;
    }
};