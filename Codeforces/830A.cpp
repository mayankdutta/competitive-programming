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

template <typename... T>
void read(T &... args) {
    ((cin >> args), ...);
}

template <typename... T>
void write(T &&... args) {
    ((cout << args), ...);
}

template <typename T>
void readContainer(T &t) {
    for (auto &e : t) read(e);
}

template <typename T>
void writeContainer(T &t) {
    for (const auto &e : t) write(e, " ");
    write("\n");
}

void solve(int tc) {
    int n, k, p;
    read(n, k, p);
    vector<int> a(n), b(k);
    readContainer(a);
    readContainer(b);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, LLONG_MAX));
    dp[0][0] = 0;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            if (j < n) {
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1], max(dp[i][j], abs(b[i] - a[j]) + abs(b[i] - p)));
            }
        }
    }
    write(dp[k][n]);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tc = 1;
    // read(tc);
    for (int curr = 1; curr <= tc; curr++) solve(curr);
    return 0;
}