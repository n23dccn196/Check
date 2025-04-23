/*-------- nguyen_duc_thuan --------*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ldb = long double;
using ui = unsigned;
using ull = unsigned long long;

bool binarysearch(int a[], int n, int key) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] == key) return true;
        else if (a[mid] < key) l = mid + 1;
        else r = mid - 1; 
    }
    return false;
}

bool bin_ser_dequy(int a[], int l, int r, int key) {
    if (l > r) return false;
    int m = (l + r) / 2;
    if (a[m] == key) return true;
    else if (a[m] < key) return bin_ser_dequy(a, m + 1, r, key);
    else return bin_ser_dequy(a, l, m - 1, key);
}

int main() {
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "r", stdin);
    int a[10] = {5, 6, 3, 8, 99, 22, 10, 44, 43, 12};
    sort(a, a + 10);
    for (int i = 0; i < 10; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';
    int key;
    cin >> key;
    if (bin_ser_dequy(a, 0, 9, key)) cout << "found!\n";
    else cout << "Not found!\n";
    return 0;
}
