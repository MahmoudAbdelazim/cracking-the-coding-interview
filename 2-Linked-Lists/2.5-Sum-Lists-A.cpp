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

Node *solve(Node *n1, Node *n2) {
    if (!n1) return n2;
    if (!n2) return n1;
    Node *sum = nullptr;
    Node *temp;
    int c = 0;
    while (n1 || n2 || c) {
        int s = c;
        if (n1) s += n1->data;
        if (n2) s += n2->data;
        if (s >= 10) {
            c = 1;
            s = s % 10;
        } else {
            c = 0;
        }
        if (sum == nullptr) {
            sum = new Node(s);
            temp = sum;
        } else {
            temp->next = new Node(s);
            temp = temp->next;
        }
        if (n1) n1 = n1->next;
        if (n2) n2 = n2->next;
    }
    return sum;

    // O(n) time, O(n) space (for sum linked list)
}

int main() {
    Node *n1 = new Node(7);
    Node *temp = n1;
    temp->next = new Node(1); temp = temp->next;
    temp->next = new Node(6); temp = temp->next;
    Node *n2 = new Node(5);
    temp = n2;
    temp->next = new Node(9); temp = temp->next;
    temp->next = new Node(2); temp = temp->next;
    Node *sum = solve(n1, n2);
    temp = sum;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}