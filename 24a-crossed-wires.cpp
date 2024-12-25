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
		}
	}
	queue<string> q;
	for (auto &[reg, v] : val) q.push(reg);
	map<string, int, greater<string>> zval;
	while (!q.empty()) {
		auto v = q.front(); q.pop();
		debug(v);
		if (v[0] == 'z') zval[v] = val[v];
		for (string to : adj[v]) {
			deg[to]--;
			if (deg[to] == 0) {
				auto [a, op, b] = in[to];
				if (op == "XOR") val[to] = val[a] ^ val[b];
				if (op == "AND") val[to] = val[a] & val[b];
				if (op == "OR") val[to] = val[a] | val[b];
				q.push(to);
			}
		}
	}
	for (auto &[zreg, v] : zval) {
		ans = ans * 2 + v;
	}
	cout << ans << '\n';
}
