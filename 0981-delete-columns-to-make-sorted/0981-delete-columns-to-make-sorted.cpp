class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size();
        int m=strs[0].size();
        int c=0;
        for(int i=0;i<m;i++){
            int last=strs[0][i];
            for(int j=1;j<n;j++){
                if(strs[j][i]<last){
                    c++;
                    cout<<i<<endl;
                    break;
                }
                else last=strs[j][i];
            }
        }
        return c;
    }
};