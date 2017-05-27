#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
		int nRow = matrix.size();
		int nCol = matrix[0].size();
		vector<vector<int>> answer(nRow, vector<int>(nCol));
		queue<pair<int, int>> reachable;
		for (int i = 0; i < nRow; i++)
		{		
			for (int j = 0; j < nCol; j++)
			{				
				if (matrix[i][j] == 0) // reachable
				{
					reachable.push(make_pair(i, j));
					answer[i][j] = 0;
				}
				else
					answer[i][j] = INT_MAX;
			}
		}

		vector<pair<int, int>> dir = vector<pair<int, int>>({make_pair(-1,0),make_pair(1,0),make_pair(0,-1),make_pair(0,1)});

		while (!reachable.empty())
		{
			pair<int, int> cur = reachable.front();
			for (int i = 0; i < 4; i++)
			{
				int x = dir[i].first;
				int y = dir[i].second;
				int cx = cur.first;
				int cy = cur.second;
				if (cx + x < 0 || cx + x > nRow - 1 || cy + y < 0 || cy + y > nCol - 1) // boundary test
					continue;
				if (matrix[cx+x][cy+y] == 1) // not visited
				{
					matrix[cx + x][cy + y] = 0; // label visited
					answer[cx + x][cy + y] = answer[cx][cy] + 1;
					reachable.push(make_pair(cx + x, cy + y));
				}
			}
			reachable.pop();
		}
		return answer;
	}
};

//void main()
//{
//	vector<vector<int>> matrix = { {0,0,0},{0,1,0},{0,0,0} };
//	Solution s;
//	vector<vector<int>> ans = s.updateMatrix(matrix);
//	int a;
//	cin >> a;
//}