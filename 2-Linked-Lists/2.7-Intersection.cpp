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

Node* solve(Node *head1, Node *head2) {
    if (!head1 || !head2) return nullptr;
    Node *temp1 = head1;
    Node *temp2 = head2;
    int len1 = 0, len2 = 0;
    while (temp1 || temp2) {
        if (temp1) {
            len1++;
            temp1 = temp1->next;
        }
        if (temp2) {
            len2++;
            temp2 = temp2->next;
        }
    }
    temp1 = head1, temp2 = head2;
    int diff = abs(len1 - len2);
    if (len1 > len2) {
        for (int i = 0; i < diff; i++)
            temp1 = temp1->next;
    } else if (len2 > len1) {
        for (int i = 0; i < diff; i++)
            temp2 = temp2->next;
    }
    while (temp1) {
        if (temp1 == temp2) return temp1;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return nullptr;

    // O(n) time, O(1) space
}

int main() {
    Node *n1 = new Node(1);
    Node *temp = n1;
    temp->next = new Node(2);
    temp = temp->next;
    Node *inter = temp;
    temp->next = new Node(3);
    temp = temp->next;

    Node *n2 = new Node(4);
    temp = n2;
    temp->next = new Node(5);
    temp = temp->next;
    temp->next = inter;

    /*
     * 1 --> 2 --> 3
     *       ^
     * 4 --> 5
     */

    Node *intersection = solve(n1, n2);
    if (intersection) cout << intersection->data << "\n";
    else cout << "Not Intersected\n";
}
