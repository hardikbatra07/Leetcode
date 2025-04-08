class Solution {
public:
    string minWindow(string s, string t) {
        int x=s.size();
        int y=t.size();
        map<char,int> mp;
        for(auto it:t) mp[it]++;
        int count=0;
        int l=0,r=0;
        int mini=INT_MAX;
        int sindex=-1;
        while(r<x){
            if(mp.find(s[r])!=mp.end()){
                if(mp[s[r]]>0)count++;
                mp[s[r]]--;
            }
            while(count==y){
            int curlen=r-l+1;
            if(mini>curlen){
                mini=curlen;
                sindex=l;
            }
             if(mp.find(s[l])!=mp.end()){
                mp[s[l]]++;
                if(mp[s[l]]>0)count--;
             }
             l++;
            }
            r++;
        }
        if(sindex==-1) return "";
        else return s.substr(sindex,mini);
    }
};