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
    string s1, s2;
    cin >> s1 >> s2;
    if (s1.length() != s2.length()) {
        cout << "NO\n";
        return 0;
    }
    // find the rotation point
    int n = s1.length();
    for (int i = 0; i < n; i++) {
        string x = s1.substr(0, i);
        string y = s1.substr(i, n - i);
        if (y + x == s2) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    
    // O(n^2) time, O(n) space
}