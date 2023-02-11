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
    getline(cin, s);
    while (s.back() == ' ') s.pop_back();
    int spaces = 0;
    for (char c: s) {
        if (c == ' ') spaces++;
    }
    int oldSize = s.size();
    int newSize = s.size() + 2 * spaces;
    s.resize(newSize);
    int idx = newSize - 1;
    for (int i = oldSize - 1; i >= 0; i--) {
        if (s[i] != ' ') {
            s[idx--] = s[i];
        } else {
            s[idx--] = '0';
            s[idx--] = '2';
            s[idx--] = '%';
        }
    }
    cout << s << "\n";

    // O(n) time, O(1) space
}