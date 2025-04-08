class Solution {
public:
int func(vector<int> &s,int goal){
    int n=s.size();
    int i=0,j=0;
    int sum=0,c=0;
    while(j<n){
        if(goal<0) return 0;
        sum+=s[j];
        while(sum>goal){
            sum-=s[i];
            i++;
        }
        c+=j-i+1;
        j++;
    }
    return c;
}
    int numSubarraysWithSum(vector<int>& s, int goal) {
        int x=func(s,goal)-func(s,goal-1);
        return x;
    }
};