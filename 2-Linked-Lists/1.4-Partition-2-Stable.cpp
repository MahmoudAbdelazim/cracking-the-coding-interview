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

Node *solve(Node *head, int x) {
    if (!head) return head;
    Node *n1 = head;
    Node *n2 = head;
    Node *prev = nullptr;
    while (n2->next) {
        Node *temp = n2->next;
        if (temp->data < x) {
            if (n1->data < x) {
                n2->next = temp->next;
                temp->next = n1->next;
                n1->next = temp;
                n1 = temp;
            }
            else {
                n2->next = temp->next;
                temp->next = n1;
                head = temp;
                n1 = temp;
            }
        }
        prev = n2;
        n2 = n2->next;
    }
    if (n2->data < x) {
        if (n1->data < x) {
            prev->next = nullptr;
            n2->next = n1->next;
            n1->next = n2;
        }
        else {
            prev->next = nullptr;
            n2->next = n1;
            head = n2;
        }
    }
    return head;

    // O(n) time, O(1) space
}

int main() {
    Node *head = new Node(3);
    Node *temp = head;
    temp->next = new Node(5); temp = temp->next;
    temp->next = new Node(8); temp = temp->next;
    temp->next = new Node(5); temp = temp->next;
    temp->next = new Node(10); temp = temp->next;
    temp->next = new Node(2); temp = temp->next;
    temp->next = new Node(1); temp = temp->next;
    head = solve(head, 5);
    temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}