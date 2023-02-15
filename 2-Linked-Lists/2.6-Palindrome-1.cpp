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

Node *duplicate(Node *head) {
    Node *newHead = new Node(head->data);
    Node *temp1 = head;
    Node *temp2 = newHead;
    while (temp1->next) {
        temp2->next = new Node(temp1->next->data);
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return newHead;
}

Node *reverse(Node *head) {
    Node *temp = nullptr;
    Node *prev = nullptr;
    Node *cur = head;
    while (cur) {
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    head = prev;
    return head;
}

bool solve(Node *head) {
    if (!head) return true;
    Node *n = duplicate(head);
    n = reverse(n);
    while (head) {
        if (head->data != n->data) return false;
        head = head->next;
        n = n->next;
    }
    return true;

    // O(n) time, O(n) space
}

int main() {
    Node *n1 = new Node(1);
    Node *temp = n1;
    temp->next = new Node(2); temp = temp->next;
    temp->next = new Node(3); temp = temp->next;
    temp->next = new Node(2); temp = temp->next;
    temp->next = new Node(1); temp = temp->next;
    bool palindrome = solve(n1);
    if (palindrome) cout << "Palindrome\n";
    else cout << "Not Palindrome\n";
}