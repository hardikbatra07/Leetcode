class Solution {
public:
    bool checkValidString(string s) {
        int n=s.length();
        int mini=0,maxi=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                mini++;
                maxi++;
            }
            else if(s[i]==')'){
                 mini=max(0,mini-1);
                maxi--;
            }
            else{
                mini=max(0,mini-1);
                maxi=maxi+1;
            }
            if(maxi<0) return false;
        }
        if(mini!=0) return false;
        else return true;
    }
};