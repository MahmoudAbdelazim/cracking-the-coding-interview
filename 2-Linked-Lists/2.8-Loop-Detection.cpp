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

bool solve(Node *head) {
    if (!head || !head->next) return false;
    Node *slow = head;
    Node *fast = head->next;
    while (fast->next) {
        if (slow == fast) return true;
        slow = slow->next;
        fast = fast->next;
        if (fast->next) fast = fast->next;
    }
    return false;

    // O(n) time, O(1) space
}

int main() {
    Node *n = new Node(0);
    Node *n1 = new Node(1);
    n->next = n1;
    Node *temp = n1;
    temp->next = new Node(2);
    temp = temp->next;
    temp->next = new Node(3);
    temp = temp->next;
    temp->next = n1;

    if (solve(n)) cout << "Loop\n";
    else cout << "No loop\n";
}
