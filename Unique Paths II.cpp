#include <vector>
using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		vector<vector<int>> mat;
		for (int i = 0; i < m; i++){
			mat.push_back(vector<int>(n));
		}
		if (obstacleGrid[0][0] == 0)
			mat[0][0] = 1;
		for (int i = 1; i < m; i++){
			if (obstacleGrid[i][0] == 0)
				mat[i][0] = mat[i - 1][0];
		}
		for (int j = 1; j < n; j++){
			if (obstacleGrid[0][j] == 0)
				mat[0][j] = mat[0][j - 1];
		}
		for (int i = 1; i < m; i++){
			for (int j = 1; j < n; j++){
				if (obstacleGrid[i][j] == 0)
					mat[i][j] = mat[i - 1][j] + mat[i][j - 1];
			}
		}
		return mat[m - 1][n - 1];
	}
};