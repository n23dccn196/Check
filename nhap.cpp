/*------- ndtnoob_kkk -------*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ldb = long double;
using ui = unsigned;
using ull = unsigned long long;

void solve() {
    // vector<int> mp;
    string s;
    int q;
    cin >> s;
    cin >> q;
    // int n = s.length() - 4;
    for (int k = 0; k < q; k++) {
        int i;
        char v;
        cin >> i >> v;
        s[i - 1] = v;
        if (s.find("1100") != string::npos) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main() {
    // freopen("test_input0.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) 
        solve();
    return 0;
}
