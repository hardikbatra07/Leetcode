class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n=code.size();
        vector<pair<string,string>> ans;
        vector<string> ans2;
        set<string> s;
        s.insert("electronics");
        s.insert("grocery");
        s.insert("pharmacy");
        s.insert("restaurant");
        for(int i=0;i<n;i++){
            string curr=code[i];
            if(isActive[i] && curr!="" && s.find(businessLine[i])!=s.end()){
            int flag=1;
            for(auto it:curr){
                if((it>='a' && it<='z') || (it>='A' && it<='Z') || (it>='0' && it<='9') || it=='_'){
                    continue;
                }
                else{
                    flag=0;
                    break;
                }  
            }
            if(flag==1){
                ans.push_back({businessLine[i],code[i]});
            }
            }
        }
        sort(ans.begin(),ans.end());
        for(auto it:ans) ans2.push_back(it.second);
        return ans2;
    }
};