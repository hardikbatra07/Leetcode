class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n=s.size();
        vector<long long> pre(n);
        pre[n-1]=shifts[n-1];
        for(int i=n-2;i>=0;i--) pre[i]=pre[i+1]+shifts[i];
        for(int i=0;i<n;i++){
            cout<<s[i]<<" "<<pre[i]<<endl;
            s[i]=((s[i]-'a'+pre[i])%26)+'a';
        }
        return s;
    }
};