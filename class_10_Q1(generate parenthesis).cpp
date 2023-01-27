class Solution {
public:
vector<string>ans;
   void generate (int open,int close ,int n,string s){
       if(s.size()==2*n)ans.push_back(s);
       if(open<n){
           s+="(";
           generate(open+1,close,n,s);
           s.pop_back();
       }
       if(close<open){
       s+=")";
       generate(open,close+1,n,s);
       s.pop_back();
       }
   }
    vector<string> generateParenthesis(int n) {
        generate(0,0,n,"");
        return ans;
    }
};
