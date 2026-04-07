#include <bits/stdc++.h>
#include <iostream>
using namespace std;

namespace DoubleLinkList {

struct NODE {
    int data;
    NODE *next;
    NODE *pre;
    NODE() : data(0), next(nullptr), pre(nullptr) {}
    NODE(int val) : data(val), next(nullptr), pre(nullptr) {}
};

NODE *head = nullptr, *tail = nullptr;
int len = 0;

void Pre() {
    head = new NODE();
    tail = new NODE();
    head->pre = NULL;
    tail->next = NULL;
    head->next = tail;
    tail->pre = head;
    len = 0;
}

// Move to the node at position i (0-based). If i == len, returns tail sentinel.
NODE *move(int i) {
    NODE *cur = head;
    for (int j = 0; j <= i; j++) {
        cur = cur->next;
    }
    return cur;
}

void insert(int i, int x) {
    // insert before the node currently at position i (or before tail if i == len)
    NODE *pos = move(i);
    NODE *node = new NODE(x);
    NODE *p = pos->pre;
    p->next = node;
    node->pre = p;
    node->next = pos;
    pos->pre = node;
    ++len;
}

void remove(int i) {
    // remove the node at position i (assumed valid)
    NODE *pos = move(i);
    NODE *p = pos->pre;
    NODE *n = pos->next;
    p->next = n;
    n->pre = p;
    delete pos;
    --len;
}

int Get_length() { return len; }

int Query(int i) {
    if (i < 0 || i >= len) return -1;
    NODE *pos = move(i);
    return pos->data;
}

void Print() {
    if (len == 0) {
        cout << -1 << '\n';
        return;
    }
    NODE *cur = head->next;
    for (int idx = 0; idx < len; ++idx) {
        if (idx) cout << ' ';
        cout << cur->data;
        cur = cur->next;
    }
    cout << '\n';
}

void Clear() {
    // delete all data nodes
    NODE *cur = head->next;
    while (cur != tail) {
        NODE *nxt = cur->next;
        delete cur;
        cur = nxt;
    }
    delete head;
    delete tail;
    head = tail = nullptr;
    len = 0;
}

} // namespace DoubleLinkList

int n;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    if (!(cin >> n)) return 0;
    int op, x, p, ans;
    DoubleLinkList::Pre();
    for (int _ = 0; _ < n; ++_) {
        cin >> op;
        switch (op) {
        case 0:
            ans = DoubleLinkList::Get_length();
            cout << ans << '\n';
            break;
        case 1:
            cin >> p >> x;
            DoubleLinkList::insert(p, x);
            break;
        case 2:
            cin >> p;
            ans = DoubleLinkList::Query(p);
            cout << ans << '\n';
            break;
        case 3:
            cin >> p;
            DoubleLinkList::remove(p);
            break;
        case 4:
            DoubleLinkList::Print();
            break;
        }
    }
    DoubleLinkList::Clear();
    return 0;
}

