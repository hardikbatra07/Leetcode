class Solution {
public:
    int characterReplacement(string s, int k) {
            //your code goes here
        int n=s.length();
        vector<int> m(26,0);
        int l=0,r=0;
        int maxi=0,ans=0;
        while(r<n){
            m[s[r]-'A']++;
            maxi=max(maxi,m[s[r]-'A']);
            if(r-l+1-maxi>k){
                m[s[l]-'A']--;
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
            
        }
        return ans;
    }
};