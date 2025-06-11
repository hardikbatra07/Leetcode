class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
       int n=arr.size();
        stack<int> s;
        vector<int> ans;
        for(int i=2*n-1;i>=0;i--){
        if(s.empty()) ans.push_back(-1);
        else{
            while(!s.empty() && s.top()<=arr[i%n]) s.pop();
             if(s.empty()) ans.push_back(-1);
            else ans.push_back(s.top());
        }
        s.push(arr[i%n]);
       }
       reverse(ans.begin(),ans.end());
       ans.erase(ans.begin()+n,ans.end());
       return ans;
    }
};