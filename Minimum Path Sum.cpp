#include <vector>
using namespace std;
class Solution {
public:
	int minPathSum(vector<vector<int> > &grid) {
		int x = grid.size();
		int y = grid[0].size();
		for (int j = 1; j < y; j++){
			grid[0][j] += grid[0][j - 1];
		}
		for (int i = 1; i < x; i++){
			grid[i][0] += grid[i - 1][0];
		}
		for (int i = 1; i < x; i++){
			for (int j = 1; j < y; j++){
				int m = grid[i - 1][j] < grid[i][j - 1] ? grid[i - 1][j] : grid[i][j - 1];
				grid[i][j] += m;
			}
		}
		return grid[x - 1][y - 1];
	}
};