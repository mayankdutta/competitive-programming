#pragma GCC optimize("O3")
#pragma GCC target("sse4")

#include <bits/stdc++.h>

using namespace std;

#define deb(x) cout << #x << " is " << x << "\n"
#define int long long
#define mod 1000000007
#define PI acos(-1)

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

template <typename T>
using max_heap = priority_queue<T>;

void solve(int tc) {
    int n, q, l, r;
    string s;
    cin >> n >> q >> s;
    int a[n + 1] = {0};
    for (int i = 1; i < n; i++) {
        if (s[i - 1] == 'A' && s[i] == 'C') {
            a[i + 1] = a[i] + 1;
        } else {
            a[i + 1] = a[i];
        }
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << a[r] - a[l] << "\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int tc = 1;
    // cin >> tc;
    for (int curr = 1; curr <= tc; curr++) solve(curr);
    return 0;
}