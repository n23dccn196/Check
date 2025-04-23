/*------- ndtnoob_kkk -------*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ldb = long double;
using ui = unsigned;
using ull = unsigned long long;

void solve() {
    string s;
    cin >> s;

    int cnt = 0, n = s.length() - 4;
    for (int i = 0; i <= n;) {
        if (s[i] == '1' && s[i + 1] == '1' 
            && s[i + 2] == '0' && s[i + 3] == '0') {
            cnt++;
            i += 4;
        }
        else i += 1;
    }

    int q;
    cin >> q;

    for (int k = 0; k < q; k++) {
        int i; char v;
        cin >> i >> v;
        i -= 1;

        int j = (i >= 3) ? i - 3 : 0;
        bool found = s.substr(j, 7).find("1100") != string::npos;
        s[i] = v;
        bool check = s.substr(j, 7).find("1100") != string::npos;
        if (!found && check) cnt++;
        else if (found && !check) cnt--;
       
        if (cnt > 0) cout << "YES\n";
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
