class Solution {
 bool func(string s){
        int n = s.length();
        int i = 0, j = n-1;
        while(i < j){
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
    public:
    int longestPalindrome(string s, string t) {
        int n = s.length(), m = t.length();
        int result = 1;
        for(int i = 0; i < n; i++){
            string str = "";
            for(int j = i; j < n; j++){
                str += s[j];
                if(func(str)) result = max(result, j-i+1);
                for(int k = 0; k < m; k++){
                    string t1 = "";
                    for(int l = k; l < m; l++){
                        t1 += t[l];
                        if(func(t1)) result = max(result, l-k+1);
                        if(func(str + t1)){
                            int len = str.length() + t1.length();
                            result = max(result, len);
                        }
                    }
                }
            }
        }
        return result;
    }
};