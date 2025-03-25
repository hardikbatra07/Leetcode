class Solution {
public:
    int combine(int a, int b)
    {
        int ab=0;
        int tempb=b;
        for(int i=0,j=0;i<32;i++)
        {
            //ab calculation
            int bit=1&tempb;
            if(tempb==0)
            {
                bit=(a>>j)&1;
                j++;
            }   
            else
               tempb>>=1;
            ab^=(bit<<i);
        }
        return ab;
    }
    int maxGoodNumber(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end(),[&](int a, int b){
            int ab=combine(a,b),ba=combine(b,a);
            return ab>ba;
        });
        int res=combine(nums[1],nums[2]);
        res=combine(nums[0],res);
        return res;
    }
};