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

int invertKthBit(int x, int k) {
    return x ^ (1 << (k - 1));
}

int main() {
    string s;
    getline(cin, s);
    int bits = 0;
    for (char c: s) {
        if (c == ' ') continue;
        bits = invertKthBit(bits, tolower(c) - 'a' + 4);
    }
    int odd = 0;
    for (int i = 0; i < 31; i++) {
        if (bits & (1 << i)) odd++;
    }
    if (odd <= 1) cout << "YES\n";
    else cout << "NO\n";

    // O(n) time, O(1) space
}