class Solution {
public:
    void setZeroes(vector<vector<int>>& a) {
        int n=a.size();
        int m=a[0].size();
        set<int>s1,s2;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]==0){
                    s1.insert(i);
                    s2.insert(j);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(s1.find(i)!=s1.end() || s2.find(j)!=s2.end() ){
                    a[i][j]=0;
                }
            }
        }
        // for(auto it:s) cout<<it<<endl;
        //1 2 3 4
        //5 0 7 8
        //0 10 11 12
        //13 14 15 0
    }
};