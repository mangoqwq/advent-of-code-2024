#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string line;
	ll ans = 0;
	vector<vector<int>> top, bot;
	while (getline(cin, line)) {
		vector<string> cur;
		cur.push_back(line);
		while (getline(cin, line)) {
			if (line == "") break;
			cur.push_back(line);
		}
		bool flag = 1;
		vector<int> lock;
		for (int j = 0; j < 5; ++j) {
			if (cur[0][j] == '#') flag = 0;
			int cnt = -1;
			for (int i = 0; i < 7; ++i) {
				if (cur[i][j] == '#') cnt++;
			}
			lock.push_back(cnt);
		}
		if (flag) bot.push_back(lock);
		else top.push_back(lock);
	}
	for (auto lock1 : top) {
		for (auto lock2 : bot) {
			bool ok = [&]() -> bool {
				for (int i = 0; i < 5; ++i) {
					if (lock1[i] + lock2[i] > 5) return 0;
				}
				return 1;
			}();
			ans += ok;
		}
	}
	cout << ans << '\n';
}
