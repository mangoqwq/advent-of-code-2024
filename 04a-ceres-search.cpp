#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string line;
	ll ans = 0;
	vector<string> g;
	while (getline(cin, line)) {
		g.push_back(line);
	}
	int N = g.size(), M = g[0].size();
	string want = "XMAS";
	auto in = [&](int i, int j) { return i >= 0 && j >= 0 && i < N && j < M; };
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			for (int dx = -1; dx <= 1; ++dx) for (int dy = -1; dy <= 1; ++dy) {
				bool ok = [&]() -> bool {
					for (int k = 0; k < 4; ++k) {
						int x = i + dx * k, y = j + dy * k;
						if (!in(x, y)) return 0;
						if (g[x][y] != want[k]) return 0;
					}
					return 1;
				}();
				ans += ok;
			}
		}
	}
	cout << ans << '\n';
}
