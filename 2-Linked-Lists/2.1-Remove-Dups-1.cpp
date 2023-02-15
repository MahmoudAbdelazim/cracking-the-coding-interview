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

void solve(Node *head) {
    unordered_set<int> set;
    set.insert(head->data);
    Node *prev = head;
    Node *temp = prev->next;
    while (temp != nullptr) {
        if (!set.count(temp->data)) {
            set.insert(temp->data);
            prev->next = temp;
            prev = temp;
        }
        temp = temp->next;
    }
    prev->next = nullptr;

    // O(n) time, O(n) space
}

int main() {
    Node *head = new Node(1);
    Node *temp = head;
    for (int i = 2; i <= 10; i++) {
        temp->next = new Node(i);
        temp = temp->next;
        temp->next = new Node(i);
        temp = temp->next;
    }
    solve(head);
    temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}