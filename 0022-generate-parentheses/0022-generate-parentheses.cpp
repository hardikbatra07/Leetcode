class Solution {
    private:
    vector<string> a;
    void generate(string &s,int open,int close){
        if(open==0 && close==0){
        a.push_back(s);
        return;
        }
        if(open>0){
            s.push_back('(');
            generate(s,open-1,close);
            s.pop_back();
        }
        if(close>0 && close>open){
            s.push_back(')');
            generate(s,open,close-1);
            s.pop_back();
        }

    }
public:
    vector<string> generateParenthesis(int n) {
        string s;
        generate(s,n,n);
        return a;  
    }
};