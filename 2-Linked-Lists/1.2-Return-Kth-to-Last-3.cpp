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

Node *solve(Node *head, int k) {
    if (!head) return nullptr;
    Node *n1 = head;
    Node *n2 = head;
    int i = 0;
    while (i < k && n2->next) {
        n2 = n2->next;
        i++;
    }
    while (n2) {
        n1 = n1->next;
        n2 = n2->next;
    }
    return n1;

    // O(n) time, O(1) space
}

int main() {
    Node *head = new Node(1);
    Node *temp = head;
    // 1 2 3 4 5 6 7 8 9 10
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