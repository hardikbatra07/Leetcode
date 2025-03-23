

class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(); 
        int m = mana.size();  

        long long time = 0, st;
        vector<long long> temp(n, 0); 
        for (int i = 0; i < m; i++) {    
            for (int j = 0; j < n; j++) { 
                if (j == 0) {
                    st = temp[j]; 
                } else {
                    st = max(temp[j - 1], temp[j]); 
                }
                time = (long long) skill[j] * mana[i]; 
                temp[j] = st + time; 
            }
            for (int j = n - 2; j >= 0; j--) {
                temp[j] = max(temp[j], temp[j + 1] - skill[j + 1] * mana[i]);
            }
        }

        return temp.back();
    }
};
