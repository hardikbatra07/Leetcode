class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        if(n==0) return 0;
        int i=0,j=0,c=0;
        int maxi=1;
        vector<int> hash(128,0);
        while(j<n){
            if(hash[s[j]]!=0){
                hash[s[i]]--;
                i++;
                c=j-i+1;
                maxi=max(maxi,c);
            }
            else{
                maxi=max(maxi,c); 
                hash[s[j]]++;
                j++;
                c=j-i+1;   
            }
        }
        return maxi;
    }
};