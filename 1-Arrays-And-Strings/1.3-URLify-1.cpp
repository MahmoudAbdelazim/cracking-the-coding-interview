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
    string url;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            if (i != 0) {
                url += "%20";
            } else {
                continue;
            }
        } else {
            url += s[i];
        }
    }
    cout << url << "\n";

    // O(n) time, O(n) space
}