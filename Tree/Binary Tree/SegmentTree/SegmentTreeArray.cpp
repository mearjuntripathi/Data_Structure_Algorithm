#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
    vector<int> tree;
    int n;

    void build(vector<int>& arr, int idx, int left, int right) {
        if (left == right) {
            tree[idx] = arr[left];
            return;
        }
        int mid = (left + right) / 2;
        build(arr, 2*idx, left, mid);
        build(arr, 2*idx+1, mid+1, right);
        tree[idx] = tree[2*idx] + tree[2*idx+1];
    }

    int query(int idx, int left, int right, int ql, int qr) {
        if (ql > right || qr < left)  // no overlap
            return 0;
        if (ql <= left && right <= qr)  // total overlap
            return tree[idx];
        int mid = (left + right) / 2;
        return query(2*idx, left, mid, ql, qr) + query(2*idx+1, mid+1, right, ql, qr);
    }

    void update(int idx, int left, int right, int pos, int val) {
        if (left == right) {
            tree[idx] = val;
            return;
        }
        int mid = (left + right) / 2;
        if (pos <= mid)
            update(2*idx, left, mid, pos, val);
        else
            update(2*idx+1, mid+1, right, pos, val);
        tree[idx] = tree[2*idx] + tree[2*idx+1];
    }

public:
    SegmentTree(vector<int>& arr) {
        n = (int)arr.size();
        tree.resize(4*n, 0);
        build(arr, 1, 0, n-1);
    }

    int query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }

    void update(int pos, int val) {
        update(1, 0, n-1, pos, val);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    SegmentTree s(arr);

    while (q--) {
        int c, l, r;
        cin >> c >> l >> r;
        if (c == 1) {
            // update position l-1 with value r
            s.update(l - 1, r);
        } else {
            // query sum in range [l-1, r-1]
            cout << s.query(l - 1, r - 1) << "\n";
        }
    }
    return 0;
}
