class Node {
    public: 
        char left, right;
        int len;

        Node (): left(0), right(0), len(0) {}
        Node (char left, char right, int len): left(left), right(right), len(len) {}
};

class SegmentTree {
    private:
        vector<Node> segTree;
        string s;

    public:
        SegmentTree (string _s) {
            s = _s;
            int n = s.size();
            segTree.resize(4 * n);
        }

        void buildSegTree (int i, int l, int r) {
            if (l == r) {
                segTree[i] = Node(s[l], s[l], 1);
                return;
            }

            int mid = (l + r) / 2;
            buildSegTree(2 * i + 1, l, mid);
            buildSegTree(2 * i + 2, mid + 1, r);

            segTree[i] = merge(segTree[2 * i + 1], segTree[2 * i + 2]);
        }

        Node merge (Node l, Node r) {
            if (l.len == 0) return r;
            if (r.len == 0) return l;

            int totalLen = l.len + r.len;
            if (l.right == r.left) totalLen -= 1;
            return Node(l.left, r.right, totalLen);
        }

        void updateSegTree (int idx, int i, int l, int r) {
            if (l == r) {
                char ch = s[idx];
                s[idx] = (ch == 'A' ? 'B' : 'A'); 
                segTree[i] = Node(s[idx], s[idx], 1);
                return;
            }

            int mid = (l + r) / 2;
            if (idx <= mid) {
                updateSegTree(idx, 2 * i + 1, l, mid);
            } else {
                updateSegTree(idx, 2 * i + 2, mid + 1, r);
            }

            segTree[i] = merge(segTree[2 * i + 1], segTree[2 * i + 2]);
        }

        Node Query (int i, int start, int end, int l, int r) {
            if (l > end || r < start) {
                return Node();
            }

            if (l >= start && r <= end) {
                return segTree[i];
            }

            int mid = (l + r) / 2;
            return merge(Query(2 * i + 1, start, end, l, mid), 
                        Query(2 * i + 2, start, end, mid + 1, r));
        }
};


class Solution {
public:
    vector<int> minDeletions(string s, vector<vector<int>>& queries) {
        int n = s.size();
        
        SegmentTree seg(s);
        seg.buildSegTree(0, 0, n - 1);

        vector<int> ans;
        for (vector<int>& query: queries) {
            int type = query[0];

            if (type == 1) {
                // point update
                int idx = query[1];
                seg.updateSegTree(idx, 0, 0, n - 1);
            } else { 
                // range query
                int start = query[1], end = query[2];
                Node curr = seg.Query(0, start, end, 0, n - 1);
                int ops = (end - start + 1) - curr.len;
                ans.push_back(ops);
            }
        }

        return ans;
    }
};
