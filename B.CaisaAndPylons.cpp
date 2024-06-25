#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
    cerr << ' ' << H;
    dbg_out(T...);
}
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

// Utility functions for comparison
template<typename S, typename T> void smax(S& a, const T& b) { if (a < b) a = b; }
template<typename S, typename T> void smin(S& a, const T& b) { if (a > b) a = b; }

// Random number generator setup
#define rng_init mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define rng_seed(x) mt19937 rng(x)
#define rng(x) rng(x)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
const int MXN = 1e5 + 5, INF = 1e9 + 5;




void solve () {
    int N;
    cin >> N;
    vector<int> arr(N + 1);
    arr[0] = 0;

    for (int i = 1; i < N + 1 ; i++)
        cin >> arr[i];

    int energy = 0 , dollar = 0;


    for (int i = 0 ; i < N ; i++) {
        const int diff = arr[i] - arr[i + 1];
        if (diff < 0) {
            if (abs(diff) > energy) {
                dollar = dollar + abs(abs(diff) - energy);
                energy = 0;
            } else {
                energy = energy - abs(diff);
            }
        } else {
            energy = energy + diff;
        }
    }


    cout << dollar;
}







signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int TC = 1;
    // cin > TC;
    while (TC--) solve();

    return 0;
}

