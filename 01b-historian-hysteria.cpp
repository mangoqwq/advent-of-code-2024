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
	vector<ll> a;
	map<int, int> cnt;
	while (getline(cin, line)) {
		istringstream iss(line);
		int x, y; iss >> x >> y;
		a.push_back(x);
		cnt[y]++;
	}
	for (int i = 0; i < (int)a.size(); ++i) {
		ans += cnt[a[i]] * a[i];
	}
	cout << ans << '\n';
}
