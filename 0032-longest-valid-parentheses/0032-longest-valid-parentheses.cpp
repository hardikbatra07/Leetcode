class Solution {
public:
    int longestValidParentheses(string s) {
        int c1=0,c2=0;
        int n=s.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') c1++;
            else c2++;
            if(c1==c2) maxi=max(maxi,2*c1);
            if(c2>c1){
                c1=0;
                c2=0;
            }
        }
        c1=0,c2=0;
       for(int i=n-1;i>=0;i--){
            if(s[i]=='(') c1++;
            else c2++;
            if(c1==c2) maxi=max(maxi,2*c1);
            if(c1>c2){
                c1=0;
                c2=0;
            }
        }
       
        return maxi;
    }
};