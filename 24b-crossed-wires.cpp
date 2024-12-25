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
	map<string, vector<string>> adj;
	struct Operation { string a, op, b; };
	map<string, Operation> in;
	map<string, int> val;
	map<string, int> deg;
	while (getline(cin, line)) {
		istringstream iss(line);
		if (line == "") continue;
		if (line.find(':') != line.npos) {
			string reg; int v;
			iss >> reg >> v; reg.pop_back();
			val[reg] = v;
		}
		else {
			string a, op, b, arrow, res;
			iss >> a >> op >> b >> arrow >> res;
			adj[a].push_back(res);
			adj[b].push_back(res);
			deg[res] += 2;
			in[res] = {a, op, b};
			cout << a << " " << res << " " << op << '\n';
			cout << b << " " << res << " " << op << '\n';
		}
	}
	// analyze adder by hand in graph visualizer
	vector<string> swaps = {
		"djg", "z12", 
		"sbg", "z19",
		"hjm", "mcq", // at z24
		"dsd", "z37",
	};
	string ans = "";
	ranges::sort(swaps);
	for (string s : swaps) {
		ans += s + ",";
	}
	ans.pop_back();
	cout << ans << '\n';
}
