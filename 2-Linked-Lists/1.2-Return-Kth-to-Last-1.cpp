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

Node* solve(Node *head, int k) {
    int sz = 0;
    Node* temp = head;
    while (temp != nullptr) {
        sz++;
        temp = temp->next;
    }
    int idx = sz - k;
    temp = head;
    for (int i = 0; i < idx; i++) {
        temp = temp->next;
    }
    return temp;
    
    // O(n) time, O(1) space
}

int main() {
    Node *head = new Node(1);
    Node *temp = head;
    for (int i = 2; i <= 10; i++) {
        temp->next = new Node(i);
        temp = temp->next;
    }
    cout << solve(head, 5)->data << "\n";
//    temp = head;
//    while (temp != nullptr) {
//        cout << temp->data << " ";
//        temp = temp->next;
//    }
}