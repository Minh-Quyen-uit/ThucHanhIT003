
//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int n, k;
vector<int> a;


vector<int> get_ans(const vector<int>& A, int K) {
	map<int, int> Hash;
    for (int color : A) {
        Hash[color]++;
    }
    priority_queue<pair<int, int>> pq; 
    for (const auto& [color, count] : Hash) {
        pq.push({ count, color });
        if (pq.size() > K) {
            pq.pop(); 
        }
    }

    vector<int> result;
    while (!pq.empty()) {
        result.push_back(pq.top().second);
        pq.pop();
    }
    reverse(result.begin(), result.end()); 

    return result;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	cin >> n >> k;

	a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	vector<int> ans = get_ans(a, k);

	for (const int& x : ans) cout << x << ' ';
	return 0;
}
