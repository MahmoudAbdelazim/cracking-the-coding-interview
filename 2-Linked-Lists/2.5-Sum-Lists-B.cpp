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

int getSum(Node *n1, Node *n2, Node *&sum) {
    if (!n1 && !n2) {
        return 0;
    }
    int s = 0;
    if (n1) s += n1->data;
    if (n2) s += n2->data;
    sum->next = new Node(0);
    s += getSum((n1 ? n1->next : nullptr), (n2 ? n2->next : nullptr), sum->next);
    sum->next->data = s % 10;
    return (s >= 10 ? 1 : 0);
}

Node *solve(Node *n1, Node *n2) {
    if (!n1) return n2;
    if (!n2) return n1;
    Node *sum = new Node(0);
    int c = getSum(n1, n2, sum);
    if (c) sum->data = c;
    else return sum->next;
    return sum;

    // O(n) time, O(n) space
}

int main() {
    Node *n1 = new Node(6);
    Node *temp = n1;
    temp->next = new Node(1); temp = temp->next;
    temp->next = new Node(7); temp = temp->next;
    Node *n2 = new Node(2);
    temp = n2;
    temp->next = new Node(9); temp = temp->next;
    temp->next = new Node(5); temp = temp->next;
    Node *sum = solve(n1, n2);
    temp = sum;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}