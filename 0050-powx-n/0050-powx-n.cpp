class Solution {
public:
    double myPow(double x, int n) {
        long long num=n;
        if(num==0) return 1;
        if(num<0){
         num=-num;
         x=1/x;
        }
          if(num%2){
            return x*myPow(x,num-1);
          }
          else return myPow(x*x,num/2);
    }
};