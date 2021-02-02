#include<iostream>
//package
#include<algorithm>
//data struct
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<tuple>

using namespace std;


class unionfind {
public:
	vector<int> record;
	vector<int> size;
	int area;
	unionfind(int len) {
		area = len;
		for (int i = 0; i < len; i++) {
			record.push_back(i);
			size.push_back(1);
		}
	}
	int find(int x) {
		if (x == record[x])
			return x;
		return find(record[x]);
	}
	bool un_ion(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y)
			return false;
		if (size[x] < size[y]) {
			swap(x, y);
		}
		area--;
		size[x] = size[x] + size[y];
		record[y] = x;
		return true;
	}
	bool connect(int x, int y) {
		x = find(x);
		y = find(y);
		return x == y;
	}
};




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
namespace lt778{
	//778. 水位上升的泳池中游泳
	int swimInWater(vector<vector<int>>& grid) {
		if (grid.empty() || grid[0].empty())
			return 0;
		vector<tuple<int, int, int>> cmap;
		int cow = grid.size(), row = grid[0].size();
		for (int i = 0; i < cow; i++) {
			for (int j = 0; j < row; j++) {
				int id = i * row + j;
				if (i > 0) {
					cmap.emplace_back(id, id - row, max(grid[i][j], grid[i - 1][j]));
				}
				if (j > 0) {
					cmap.emplace_back(id, id - 1, max(grid[i][j], grid[i][j - 1]));
				}
			}
		}
		sort(cmap.begin(), cmap.end(), [](const auto&e1, const auto&e2) {
			auto&&[x1, y1, v1] = e1;
			auto&&[x2, y2, v2] = e2;
			return v1 < v2;
		});
		unionfind f(cow*row);
		for (const auto e : cmap) {
			int x = get<0>(e);
			int y = get<1>(e);
			int val = get<2>(e);
			f.un_ion(x, y);
			if (f.connect(0, cow*row-1))
				return val;
			
		}
		return 0;
	}
}
namespace lt839 {
	// 839. 相似字符串组
	bool similar(string&s1,string&s2) {
		int count = 0;
		int index1 = -1, index2 = -1;
		if (s1.size() != s2.size())
			return false;
		for (int i = 0; i < s1.size(); i++) {
			if (s1[i] != s2[i]) {
				if (count == 2)
					return false;
				if (count == 0)
					index1 = i;
				else if (count == 1)
					index2 = i;
				count++;
			}
		}
		if (count == 1)
			return false;

		if (count==0||(count==2&&s1[index1] == s2[index2] && s1[index2] == s2[index1]))
			return true;
		return false;
	}
	int numSimilarGroups(vector<string>& strs) {

		unionfind f(strs.size());
		for (int i = 0; i < strs.size();i++) {
			for (int j = i + 1; j < strs.size(); j++) {
				if (!f.connect(i, j)&&similar(strs[i],strs[j])) {
					f.un_ion(i, j);
				}
			}
		}
		return f.area;
	}
}
namespace lt888 {
	int sumc(vector<int>&arr) {
		int ans = 0;
		for (int i = 0; i < arr.size(); i++) {
			ans += arr[i];
		}
		return ans;
	}
	vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
		int suma = sumc(A);
		int sumb = sumc(B);
		int c = sumb - suma;
		c = c / 2;
		map<int, int> cmap;
		for (int i = 0; i < A.size(); i++) {
			cmap[A[i] + c] = A[i];
		}
		vector<int> ans;
		for (int i = 0; i < B.size(); i++) {
			if (cmap.count(B[i]) == 1)
			{

				ans.push_back(cmap[B[i]]);
				ans.push_back(B[i]);
				return ans;
			}
		}
		return ans;
	}
}
int main() {

}