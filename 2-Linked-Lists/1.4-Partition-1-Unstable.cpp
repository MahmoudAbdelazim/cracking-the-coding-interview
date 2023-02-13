#include bitsstdc++.h

using namespace std;

typedef pairint, int ii;
typedef vectorint vi;
typedef vectorii vii;
typedef long long ll;
typedef pairll, ll pll;
typedef vectorll vll;
typedef vectorpll vpll;

#define INF ((int)1e8 + 7)
#define INFL ((ll)1e18)
#define MOD ((ll)1e9 + 7)
#define sz(v) (int)v.size()
#define ARRAYSIZE(a) ((sizeof(a)  sizeof(a[0])))
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

class Node {
public
    Node next = nullptr;
    int data;

    explicit Node(int d) { data = d; }
};

Node solve(Node head, int x) {
    if (!head) return head;
    Node node = head;
    Node tail = head;
    while (node) {
        Node next = node-next;
        if (node-data  x) {
            node-next = head;
            head = node;
        } else {
            tail-next = node;
            tail = node;
        }
        node = next;
    }
    tail-next = nullptr;
    return head;

     O(n) time, O(1) space
}

int main() {
    Node head = new Node(3);
    Node temp = head;
    temp-next = new Node(5); temp = temp-next;
    temp-next = new Node(8); temp = temp-next;
    temp-next = new Node(5); temp = temp-next;
    temp-next = new Node(10); temp = temp-next;
    temp-next = new Node(2); temp = temp-next;
    temp-next = new Node(1); temp = temp-next;
    head = solve(head, 5);
    temp = head;
    while (temp != nullptr) {
        cout  temp-data   ;
        temp = temp-next;
    }
}