#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<tuple>

using namespace std;

namespace lt1631 {
	vector<int> arr;
	vector<int> size;
	int find(int x) {
		if (arr[x] == x)
			return x;
		return find(arr[x]);
	}
	bool unionx(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) {
			return false;
		}
		if (size[x] < size[y])
			swap(x, y);

		arr[y] = x;
		size[x] += size[y];
		return true;
	}
	bool connect(int x, int y) {
		x = find(x);
		y = find(y);
		return x == y;
	}
	int minimumEffortPath(vector<vector<int>>& heights) {
		if (heights.empty() || heights[0].empty())
			return 0;
		int cow = heights.size(), row = heights[0].size();
		vector<tuple<int, int, int>> vec;
		for (int i = 0; i < cow; i++)
		{
			for (int j = 0; j < row; j++) {
				int id = i * row + j;
				arr.push_back(id);
				size.push_back(1);
				if (i > 0) {
					vec.emplace_back(id - row, id, abs(heights[i][j] - heights[i - 1][j]));
				}
				if (j > 0) {
					vec.emplace_back(id - 1, id, abs(heights[i][j] - heights[i][j - 1]));
				}
			}
		}
		sort(vec.begin(), vec.end(), [](const auto&e1, const auto&e2) {
			auto&&[x1, y1, v1] = e1;
			auto&&[x2, y2, v2] = e2;
			return v1 < v2;
		});

		int ans = 0;
		/*for (const auto[x, y, v] : vec) {
			unionx(x, y);
			if (connect(0, cow*row - 1)) {
				ans = v;
				break;
			}
		}*/
		return ans;

	}
}

int main() {

}