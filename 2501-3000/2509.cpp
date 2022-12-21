class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> answer;
        for ( auto& q : queries ) {
            int u = q[0], v = q[1];
            
            // Find the Depth of u and v
            int du = log2(u), dv = log2(v);
            int len = 0;
            
            // Deeper node climbing up
            if ( du != dv ) {
                if ( du > dv ) {
                    swap(du, dv);
                    swap(u, v);
                }
                len += dv-du;
                for ( int i=0; i<dv-du; ++i ) {
                    v >>= 1;
                }
            }
            
            // Both nodes climbing up until equal
            while ( u != v ) {
                u >>= 1;
                v >>= 1;
                len += 2;
            }
            
            // + 1 for the added edge forming a cycle
            answer.emplace_back(len + 1);
        }
        return answer;
    }
};
