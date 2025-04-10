class Solution {
    string expand(string &s,int l,int r){
        string ans="";
        while(l>=0 && r<s.size()){
            if(s[l]==s[r]){
                ans=s.substr(l,r-l+1);
                r++;
                l--;
            }
            else break;
        }
        return ans;
    }
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int start=0;
        string ans="";
        int maxi=0;
        for(int i=0;i<n;i++){
            string s2=expand(s,i,i);
            string s1=expand(s,i,i+1);
            if(s2.size()>s1.size() && s2.size()>maxi){
                ans=s2;
                maxi=s2.size();
            }
            else if(s1.size()>maxi){
                ans=s1;
                maxi=s1.size();
        }
        }
        return ans;
    }
};