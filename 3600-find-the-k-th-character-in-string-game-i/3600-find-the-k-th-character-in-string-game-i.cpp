class Solution {
public:
    char ans(string a,int k){
        if (a.size()>k){return a[k-1];}
        int x=a.size();
        for (int i=0;i<x;i++){
            if (a[i]=='z'){a+='a';}
            a+=a[i]+1;
        }
        return ans(a,k);
    }
    char kthCharacter(int k) {
        return ans("a",k);
    }
};