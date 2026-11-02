class Solution {
	public:
	int row_n;
	int col_n;
	
	bool isValid(int i, int j) {
		if (i >= 0 && i < row_n && j < col_n && j >= 0) {
			return true;
		}
		
		return false;
	}
	
	int orangesRot(vector<vector<int>> & mat) {
		row_n = mat[0].size();
		col_n = mat.size();
		
		queue<pair<int, int>> q;
		int freshCount = 0;
		
		// Step 1: Initialize queue with all rotten oranges and count fresh oranges
		for (int i = 0; i < col_n; i++) {
			for (int j = 0; j < row_n; j++) {
				if (mat[i][j] == 2) {
					q.push({i, j});
				} else if (mat[i][j] == 1) {
					freshCount++;
				}
			}
		}
		
		// If there are no fresh oranges initially, 0 minutes are needed
		if (freshCount == 0)
			return 0;
			
		// fill q with already rotten oranges.
		for (int i = 0; i < col_n; i++)
			for (int j = 0; j < row_n; j++)
				if (mat[i][j] == 2)
					q.push(make_pair(i, j));
		
		int timer = 0;
		
		while (!q.empty()) {
			int current_rotted_oranges = q.size();
			timer++;
			
			while (current_rotted_oranges--) {
				// get rotten orange
				int col = q.front().first;
				int row = q.front().second;
				q.pop();
				
				// rot other oranges
				// top
				if (isValid(row, col - 1) && mat[col - 1][row] == 1) {
					mat[col - 1][row] = 2;
					q.push(make_pair(col - 1, row));
				}
				
				// bottom
				if (isValid(row, col + 1) && mat[col + 1][row] == 1) {
					mat[col + 1][row] = 2;
					q.push(make_pair(col + 1, row));
				}
				
				// left
				if (isValid(row - 1, col) && mat[col][row - 1] == 1) {
					mat[col][row - 1] = 2;
					q.push(make_pair(col, row - 1));
				}
				// right
				if (isValid(row + 1, col) && mat[col][row + 1] == 1) {
					mat[col][row + 1] = 2;
					q.push(make_pair(col, row + 1));
				}
			}
		}
		
		for (int i = 0; i < col_n; i++)
			for (int j = 0; j<row_n; j++) {
			if (mat[i][j] == 1)
				return - 1;
		}
		
		return timer - 1;
	}
};
