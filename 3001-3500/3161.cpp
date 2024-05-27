class Solution {

    void breakSpaces(int pos){
        // break spaces
        auto it = obstacles.upper_bound(pos);
        int pos_next = *it;
        int pos_prev = *prev(it);
        // remove original space
        int orig_size = pos_next - pos_prev;
        spaces[orig_size].erase(pos_prev);
        if(spaces[orig_size].size() == 0){ spaces.erase(orig_size); }
        // add new space
        spaces[pos - pos_prev].insert(pos_prev);
        spaces[pos_next - pos].insert(pos);
    }
    
    bool findSpace(int maxi_dist, int block_size){
        auto it = spaces.lower_bound(block_size);
        while(it != spaces.end()){
            //for(int start_pos: it->second){
            //    if(start_pos+block_size <= maxi_dist){
            //        return true;
            //    }
            // }
            // The start positions were sorted in order.
            // Thus we only need to check the first one.
            set<int> & start_positions = it->second;
            int first_pos = *start_positions.begin();
            if(first_pos + block_size <= maxi_dist){
                return true;
            }
            advance(it, 1);
        }
        return false;
    }

    vector<bool> ans;
    set<int> obstacles;        // To keep obstacle coordinate in order
    map<int, set<int>> spaces; // keep group empty spaces in order. spaces: space_size -> start index
        
public:
    vector<bool> getResults(const vector<vector<int>>& queries) {
        int const nquery = queries.size();
        ans.reserve(nquery);
        int maxi_dist = min(5*10e4, 3.0*nquery);
        obstacles.insert(0);         // dummy obstacle
        obstacles.insert(maxi_dist); // dummy obstacle
        spaces[maxi_dist].insert(0); // initialize space

        for(auto const & query: queries){
            int op = query[0];
            // op1: set obstacle
            if(op == 1){
                breakSpaces(query[1]);
                obstacles.insert(query[1]);
            }
            // op2: put blocks
            else{
                ans.push_back(findSpace(query[1], query[2]));
            }
        }        
        
        return ans;
    }
};
