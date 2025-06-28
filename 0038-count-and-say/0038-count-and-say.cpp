class Solution {
public:
    string countAndSay(int n) {
        int i=1;
        string s="1";
        string s1="";
        while(i<n){
          int j=0;
          while(j<s.length()){
          char c=s[j];
          int freq=0;
          while(j<s.length() && s[j]==c){
            freq++;
            j++;
          }
          s1.push_back(freq+'0');
          s1.push_back(c);
        }
        s=s1;
        s1="";
        i++;
    }
    return s;
    }
};