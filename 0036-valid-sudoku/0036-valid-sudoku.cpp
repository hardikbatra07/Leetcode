class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& a) {
      map<char,int> m1;
      for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
             if(a[i][j]!='.')m1[a[i][j]]++;
        }
        for(auto it:m1){
            if(it.second>1) return false;
        }
        m1.clear(); 
      }
      for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
             if(a[j][i]!='.')m1[a[j][i]]++;
        }
        for(auto it:m1){
            if(it.second>1) return false;
        }
        m1.clear(); 
      }
      for(int p=0;p<9;p+=3){
      for(int k=0;k<9;k+=3){
      for(int i=k;i<k+3;i++){
        for(int j=p;j<p+3;j++){
            if(a[i][j]!='.')m1[a[i][j]]++;
        }
      }
      for(auto it:m1){
        if(it.second>1) return false;
      }
      m1.clear();
      }
      }
      return true;
    }
};