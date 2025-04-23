/*-------- nguyen_duc_thuan --------*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ldb = long double;
using ui = unsigned;
using ull = unsigned long long;

int lomuto(int a[], int l, int r) {
    int pivot = a[r];
    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (a[j] <= pivot) {
            ++i;
            swap(a[i], a[j]);
        } 
    }
    swap(a[i + 1], a[r]);
    return i + 1;
}

int hoare(int a[], int l, int r) {
    int pivot = a[l];
    int i = l - 1;
    int j = r + 1;

    while(1) {
        do {
            ++i;
        } while (a[i] < pivot);
        do {
            --j;
        } while (a[j] > pivot);
        if (i < j) swap(a[i], a[j]);
        else return j;
    }
}

int ndt(int a[], int l, int r) {
    int pivot = (l + r) / 2;
    int i = l - 1;
    int j = r + 1;

    while(1) {
        do {
            ++i;
        } while (a[i] < pivot);
        do {
            --j;
        } while (a[j] > pivot);
        if (i < j) swap(a[i], a[j]);
        else return j;
    }
}

void qs_hoare(int a[], int l ,int r) {
    if (l >= r) return;
    int p = hoare(a, l, r);
    qs_hoare(a, l, p);
    qs_hoare(a, p + 1, r);
}

void qs_ndt(int a[], int l ,int r) {
    if (l >= r) return;
    int p = ndt(a, l, r);
    qs_hoare(a, l, p);
    qs_hoare(a, p + 1, r);
}

void qs_lomuto(int a[], int l, int r) {
    if (l >= r) return;
    int p = lomuto(a, l, r);
    qs_lomuto(a, l, p - 1);
    qs_lomuto(a, p + 1, r);
}

int main() {
    // freopen("../input.txt", "r", stdin);
    // int a[1000] = {100, 84, 72, 144, 15, 38, 260, 345, 98};
    int a[1000];
    int n;
    cin >> n;
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        // a[i] = rand() % 100;
        cin >> a[i];
    }
    qs_ndt(a, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    return 0;
}
