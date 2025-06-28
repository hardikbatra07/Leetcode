class Solution {

public:
    int candy(vector<int>& a) {
        int n = a.size();
        int i=1;
        int sum=1;
        while(i<n){
            if(a[i]==a[i-1]){
                sum++; i++;
                continue;
            }
            int peak=1;
            while(i<n && a[i]>a[i-1]){
                peak++;
                sum+=peak;
                i++;
            }
            int down=1;
            while(i<n && a[i]<a[i-1]){
                sum+=down;
                down++;

                i++;
            }
            if(down>peak) sum+=(down-peak);
        }
        return sum;
    }
};
