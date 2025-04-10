class Solution {

public:
    int reverse(int x) {
        int k=x;
        int c=0;
        int ans=1;
        if(x<0){ ans=-1;}
        while(k!=0){
            k/=10;
            c++;
        }
        c--;
        int ans1=0;
        while(x!=0){
            if(pow(10,c)*(x%10)>=(1LL<<31) || pow(10,c)*(x%10)<(-1*(1LL<<31))) return 0;
            if((ans1+pow(10,c)*(x%10))>=(1LL<<31) || (ans1+pow(10,c)*(x%10))<(-1*(1LL<<31)) ) return 0;
            ans1+=pow(10,c)*(x%10);
            x=x/10;
            c--;
        }
        return ans1;
    }
};