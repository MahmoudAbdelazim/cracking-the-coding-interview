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
    if (!head || !head->next) return true;
    stack<int> stack;
    Node *slow = head;
    Node *fast = head->next;
    stack.push(slow->data);
    bool even = false;
    while (fast->next) {
        slow = slow->next;
        stack.push(slow->data);
        fast = fast->next;
        even = false;
        if (fast->next) {
            fast = fast->next;
            even = true;
        }
    }
    slow = slow->next;
    int i = -1;
    while (slow) {
        i++;
        if (stack.top() == slow->data) {
            stack.pop();
            slow = slow->next;
        } else {
            if (i == 0 && !even) {
                stack.pop();
            } else {
                return false;
            }
        }
    }
    return true;

    // O(n) time, O(n) space
}

int main() {
    Node *n1 = new Node(1);
    Node *temp = n1;
    temp->next = new Node(2); temp = temp->next;
    temp->next = new Node(3); temp = temp->next;
    temp->next = new Node(3); temp = temp->next;
    temp->next = new Node(2); temp = temp->next;
    temp->next = new Node(1); temp = temp->next;
    bool palindrome = solve(n1);
    if (palindrome) cout << "Palindrome\n";
    else cout << "Not Palindrome\n";
}