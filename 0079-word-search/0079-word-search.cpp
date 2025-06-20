class Solution {
    bool is_Valid(int i,int j,int n,int m){
        if(i>=0 && j>=0 && i<n && j<m) return true;
        return false;
    }
    bool func(int ind,int i,int j,vector<vector<int>> &vis,int n,int m,string &word,vector<vector<char>>& matrix){
        if(ind==word.length()) return true;
        vis[i][j]=1;   
           int dx[]={-1,0,1,0};
           int dy[]={0,1,0,-1};
           for(int k=0;k<4;k++){
            int new_x=dx[k]+i;
            int new_y=dy[k]+j;
            if(is_Valid(new_x,new_y,n,m) && !vis[new_x][new_y]){
                if(matrix[new_x][new_y]==word[ind])
                if(func(ind+1,new_x,new_y,vis,n,m,word,matrix)) return true;
            } 
           }
           vis[i][j]=0;
           return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0])
                if(func(1,i,j,vis,n,m,word,board)) return true;
              }
            }
        return false;
    }
};