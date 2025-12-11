class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int n=arr.size();
        map<string,int> m;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }
        int f=0;
        for(int i=0;i<n;i++){
            if(m[arr[i]]==1) f++;
            if(f==k) return arr[i];
        }
        return "";
    }
};