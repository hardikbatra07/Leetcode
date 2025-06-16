class Solution {
         const int M=1e9+7;
    void func(vector<int> &arr,int n,vector<int> &pse,vector<int> &nse){
        stack<pair<int,int>> st;
        for(int i=0;i<n;i++){
         while(!st.empty() && st.top().first>arr[i]){
            st.pop();
         }
         if(st.empty()) pse[i]=-1;
         else pse[i]=st.top().second;
         st.push({arr[i],i});
        }
        // st.clear();
        stack<pair<int,int>> st1;
        for(int i=n-1;i>=0;i--){
         while(!st1.empty() && st1.top().first>=arr[i]){
            st1.pop();
         }
         if(st1.empty()) nse[i]=n;
         else nse[i]=st1.top().second;
         st1.push({arr[i],i});
        }
    }
public:
    int sumSubarrayMins(vector<int> &arr) {
       int n=arr.size();
       vector<int> pse(n),nse(n);
       func(arr,n,pse,nse);
      long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            ans = (ans + (arr[i] * left % M * right % M)) % M;
        }
       return ans;
    }
};