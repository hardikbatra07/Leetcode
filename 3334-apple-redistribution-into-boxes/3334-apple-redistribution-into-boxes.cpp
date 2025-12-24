class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum=accumulate(apple.begin(),apple.end(),0);
        int n=capacity.size();
        sort(capacity.begin(),capacity.end(),greater<int>());
        int i=0;
        int currsum=0;
        while(i<n && currsum<sum){
            currsum+=capacity[i];
            i++;
        }
        return i;
    }
};