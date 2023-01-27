class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		queue<pair<int, int>>q;
		//vector<vector<int>>v(matrix.size(), vector<int>(matrix[0].size(), 0));
		for(int i=0; i<matrix.size(); i++){
			for(int j=0; j<matrix[0].size(); j++){
				if(matrix[i][j]==0){
					//v[i][j]=1;
					q.push({i, j});
				}
			}
		}
		while(!q.empty()){
			int x=q.front().first, y=q.front().second;
			q.pop();
			int x1=x, x2=x, x3=x, x4=x, y1=y, y2=y, y3=y, y4=y;
			//cout<<x<<" "<<y<<endl;
			if(x1>0){
				while(x1>0){
					//v[x1-1][y1]=1;
					matrix[x1-1][y1]=0;
					x1--;
				}
			}
			if(x2<matrix.size()-1){
				while(x2<matrix.size()-1){
					//v[x2+1][y]=1;
					matrix[x2+1][y2]=0;
					x2++;
				}
			}
			if(y3>0){
				while(y3>0){
					//v[x3][y3-1]=1;
					matrix[x3][y3-1]=0;
					y3--;
				}
			}
			if(y4<matrix[0].size()-1){
				while(y4<matrix[0].size()-1){
					//v[x4][y4+1]=1;
					matrix[x4][y4+1]=0;
					y4++;
				}
			}
		}
	}
};
