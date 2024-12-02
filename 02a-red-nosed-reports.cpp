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
    auto safe = [&](vector<int> v) -> bool {
        vector<int> f = v;
        vector<int> r = v;
        sort(f.begin(), f.end());
        sort(r.begin(), r.end(), greater<int>());
        if (v != f && v != r) return 0;
        bool ok = 1;
        for (int i = 1; i < (int)v.size(); ++i) {
            ok &= abs(v[i] - v[i-1]) <= 3 && abs(v[i] - v[i-1]) > 0;
        }
        return ok;
    };

	while (getline(cin, line)) {
		istringstream iss(line);
        vector<int> v;
        int x;
        while (iss >> x) v.push_back(x);
        if (safe(v)) {
            ans++;
            continue;
        }
	}
	cout << ans << '\n';
}
