class Solution {
    void func(vector<int> &arr,int n,vector<int> &pse,vector<int> &nse,vector<int> &pge,vector<int> &nge){
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
        st=stack<pair<int,int>> ();
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top().first<arr[i]){
                st.pop();
            }
            if(st.empty()) pge[i]=-1;
            else pge[i]=st.top().second;
            st.push({arr[i],i});
        }
        st=stack<pair<int,int>> ();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top().first<=arr[i]){
                st.pop();
            }
            if(st.empty()) nge[i]=n;
            else nge[i]=st.top().second;
            st.push({arr[i],i});
        }
    }
     
public:
    long long subArrayRanges(vector<int> &arr) {
      int n=arr.size();
      vector<int> nse(n),pse(n),nge(n),pge(n);
      long long ans=0;
      func(arr,n,pse,nse,pge,nge);
      for(int i=0;i<n;i++){
        ans=(ans-(1LL*(((i-pse[i]))*((nse[i]-i)))*arr[i]));
        ans=(ans+(1LL*(((i-pge[i]))*((nge[i]-i)))*arr[i]));
      }
      return ans;
    }
};