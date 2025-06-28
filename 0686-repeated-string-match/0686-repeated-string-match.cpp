class Solution {
    bool search(string pat, string txt) {
             int n=txt.size();
             int m=pat.size();
             int p=7,mod=101;
             int hashText=0,hashPat=0;
             int pRight=1,pLeft=1;
             for(int i=0;i<m;i++){
                 hashText+=((txt[i]-'a'+1)*pRight%mod)%mod;
                 hashPat+=((pat[i]-'a'+1)*pRight%mod)%mod;
                 pRight = (pRight * p) % mod;
             }
             for(int i=0;i<=n-m;i++){
                 if(hashPat==hashText){
                    if(txt.substr(i,m)==pat){
                        return true;
                    }
                 }
                hashText = (hashText - ((txt[i] - 'a'+1) * pLeft) % mod + mod) % mod;
            hashText = (hashText + ((txt[i+m] - 'a'+1) * pRight) % mod) % mod;
            hashPat = (hashPat * p) % mod;
                  pLeft = (pLeft * p) % mod;
            pRight = (pRight * p) % mod;
             }
             return false;
        }
public:
    int repeatedStringMatch(string a, string b) {
        int c=0;
        string s="";
        while(s.size()<b.size()){
            s+=a;
            c++;
        }
        if(search(b,s)) return c;
        s+=a;
         if(search(b,s)) return c+1;
         return -1;
    }
};