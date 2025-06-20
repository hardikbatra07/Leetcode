class Solution {
    bool is_palindrome(string &s){
        int left=0,right=s.length()-1;
        while(left<=right){
            if(s[left]==s[right]){
                left++;
                right--;
            }
            else return false;
        }
        return true;
    }
    void generate(int ind,vector<string> temp,vector<vector<string>> &ans,string &s){
        if(ind==s.length()){
            ans.push_back(temp);
            return;
        }
        for(int j=ind;j<s.length();j++){
            string s1=s.substr(ind,j-ind+1);
            if(is_palindrome(s1)){
                temp.push_back(s1);
                generate(j+1,temp,ans,s);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> temp;vector<vector<string>> ans;
        generate(0,temp,ans,s);
        return ans;
    }
};