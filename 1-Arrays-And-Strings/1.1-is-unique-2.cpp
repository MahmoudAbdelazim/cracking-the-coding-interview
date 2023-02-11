#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;

#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
#define LOOP(i, a, b) for(int (i) = a; (i) < (b); i++)
#define INF ((int)1e8 + 7)
#define INFL ((ll)1e18)
#define MOD ((ll)1e9 + 7)
#define sz(v) (int)v.size()
#define ARRAYSIZE(a) ((sizeof(a) / sizeof(a[0])))
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define SQR(x) ((x) * (x))
#define CUBE(x) ((x) * (x) * (x))
# define posmod(v, m) (((v) % (m) + (m)) % (m))

int main() {
    string s;
    cin >> s;
    if (s.size() > 256) {
        cout << "NO\n";
        return 0;
    }
    bool exists[256] {};
    string ans = "YES";
    for (char c: s) {
        if (exists[c]) {
            ans = "NO";
            break;
        }
        exists[c] = true;
    }
    cout << ans << "\n";

    // O(n) time, O(1) space
    // Arguably, O(1) time, as the loop will never go beyond 256 iterations
}