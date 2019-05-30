#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

void move(int& x, int& y, const int& c, const char& dir, unordered_set<int>& visited) {
	do {
		if (dir == 'N') {
			--x;
		} else if (dir == 'S') {
			++x;
		} else if (dir == 'E') {
			++y;
		} else {
			--y;
		}
	} while (visited.find(x * c + y) != visited.end());
	visited.insert(x * c + y);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		unordered_set<int> visited;
		int n, r, c, sr, sc;
		string walk;
		cin >> n >> r >> c >> sr >> sc;
		cin >> walk;
		visited.insert(sr * c + sc);

		for (const auto& dir : walk) {
			move(sr, sc, c, dir, visited);
		}
		cout << "Case #" << i << ": " << sr << " " << sc << "\n";
	}
	
	return 0;
}
