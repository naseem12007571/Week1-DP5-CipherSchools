class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<int> ans;

        int row =0 , col = 0;
        int lr = 0 , rr = r-1 , lc = 0 , rc = c-1;
        while(lr <= rr && lc <= rc){
            for(int j = lc ; lr <= rr && lc <= rc && j <= rc ; j++){
                ans.push_back(matrix[lr][j]);
            }
            lr++;
            for(int i = lr ; lr <= rr && lc <= rc && i <= rr ; i++){
                ans.push_back(matrix[i][rc]);
            }
            rc--;
            for(int j = rc ; lr <= rr && lc <= rc && j >= lc ; j--){
                ans.push_back(matrix[rr][j]);
            }
            rr--;
            for(int i = rr ; lr <= rr && lc <= rc && i >= lr ; i--){
                ans.push_back(matrix[i][lc]);
            }
            lc++;
        }
        return ans;
    }
};
