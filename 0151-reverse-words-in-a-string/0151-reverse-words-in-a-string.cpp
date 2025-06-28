class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int i=0,j=0;
        int start,end;
        while(j<s.size()){
            while(j<s.size() && s[j]==' ') j++;
            start=i;
            while(j<s.size() && s[j]!=' '){
                s[i]=s[j];
                i++;
                j++;
            }
            end=i;
            reverse(s.begin()+start,s.begin()+end);
            if(j<s.size()){ s[i]=' '; i++;} 
        }
        while(i>0){
            if(s[i-1]==' ') i--;
            else break;
        }
        return s.substr(0,i);
    }
};