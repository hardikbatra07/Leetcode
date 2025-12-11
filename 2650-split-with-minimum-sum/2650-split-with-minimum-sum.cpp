class Solution {
public:
    int splitNum(int num) {
        vector<int> num1,num2,temp;
        while(num>0){
           temp.push_back(num%10);
           num/=10;
        }
        sort(temp.begin(),temp.end());
        int i=0;
        int n=temp.size();
        while(i<n){
            if(i%2==0){
                num1.push_back(temp[i]);
            }
            else{
                num2.push_back(temp[i]);
            }
            i++;
        }
        int first=0,second=0;
        int p1=1;
        int i1=num1.size()-1;
        while(i1>=0){
           first+=num1[i1]*p1;
           p1*=10;
           i1--;
        }
        int p2=1;
        int i2=num2.size()-1;
        while(i2>=0){
           second+=num2[i2]*p2;
           p2*=10;
           i2--;
        }
        return first+second;
    }
};