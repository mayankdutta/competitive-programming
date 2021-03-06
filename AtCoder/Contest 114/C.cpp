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

int ans = 0;

bool check(int n) {
    bool x = false, y = false, z = false;
    while (n > 0) {
        int curr = n % 10;
        if (curr == 3) {
            x = true;
        } else if (curr == 5) {
            y = true;
        } else if (curr == 7) {
            z = true;
        } else {
            return false;
        }
        n /= 10;
    }
    return x && y && z;
}

void dfs(int n, int x) {
    if (check(n)) {
        if (n <= x) ans++;
    }
    if (n <= 1e9) {
        dfs(10 * n + 3, x);
        dfs(10 * n + 5, x);
        dfs(10 * n + 7, x);
    }
}

void solve(int tc) {
    int n;
    read(n);
    dfs(0, n);
    write(ans);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int tc = 1;
    // read(tc);
    for (int curr = 1; curr <= tc; curr++) solve(curr);
    return 0;
}