#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;

#define INF ((int)1e8 + 7)
#define INFL ((ll)1e18)
#define MOD ((ll)1e9 + 7)
#define sz(v) (int)v.size()
#define ARRAYSIZE(a) ((sizeof(a) / sizeof(a[0])))
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

class Node {
public:
    Node *next = nullptr;
    int data;

    explicit Node(int d) { data = d; }
};

pair<int, Node *> sol(Node *node, int k) {
    if (node->next == nullptr) {
        if (k == 1) return make_pair(-1, node);
        return make_pair(1, nullptr);
    }
    auto next = sol(node->next, k);
    if (next.first == -1) return next;
    if (next.first + 1 == k) return make_pair(-1, node);
    return make_pair(next.first + 1, nullptr);
    
    // O(n) time, O(n) space (for recursive calls)
}

Node *solve(Node *head, int k) {
    return sol(head, k).second;
}

int main() {
    Node *head = new Node(1);
    Node *temp = head;
    for (int i = 2; i <= 10; i++) {
        temp->next = new Node(i);
        temp = temp->next;
    }
    cout << solve(head, 7)->data << "\n";
//    temp = head;
//    while (temp != nullptr) {
//        cout << temp->data << " ";
//        temp = temp->next;
//    }
}