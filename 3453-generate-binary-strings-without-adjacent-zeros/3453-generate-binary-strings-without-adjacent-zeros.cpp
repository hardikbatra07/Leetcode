class Solution {
vector<string> ans;
void generate(int ind,char last,string curr,int n){
    if(ind==n){
        ans.push_back(curr);
        return;
    }
    generate(ind+1,'1',curr+'1',n);
    if(last=='1') generate(ind+1,'0',curr+'0',n);
}
public:
    vector<string> validStrings(int n) {
        string curr="";
        generate(0,'1',curr,n);
        return ans;
    }
};