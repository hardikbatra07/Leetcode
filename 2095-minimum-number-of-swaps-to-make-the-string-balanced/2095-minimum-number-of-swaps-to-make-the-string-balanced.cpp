class Solution {
public:
    int minSwaps(string s) {
        int n = s.length();
        int o=0,c=0;
        for(char cc:s) {
            if(cc=='[') o++;
            else c++;
        }
        int open = 0, close = 0;
        for (char c : s) {
            if (c == '[') open++;
            else {
                if (open > 0) open--;
                else close++;
            }
        }
        if(o==c)return ((open+1)/2);
        else return -1;
    }
};