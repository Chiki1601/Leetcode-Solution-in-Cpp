#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> pbds;

class Router {
private:
    int mx; // limit of router
    queue<tuple<int,int,int>> q; // source, dest, timestamp
    map<tuple<int,int,int>,int> mp1; // keeping track of current packets
    map<int, pbds> mp2; // maintains sorted timestamps for any particular destination
public:
    Router(int memoryLimit) {
        mx = memoryLimit;
        // empty everything
        while(!q.empty()) q.pop();
        mp1.clear(); mp2.clear();
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        if (mp1[{source, destination, timestamp}]) return false;

        if (q.size() == mx){ // router is it its maximum limit
            
            // erase the oldest packet from both maps
            mp1[q.front()]--;
            int s = get<0>(q.front()), d = get<1>(q.front()), t = get<2>(q.front());
            mp2[d].erase({t, s});
            q.pop();
        }

        // Now push the new packet
        q.push({source, destination, timestamp});
        mp1[{source, destination, timestamp}]++;
        mp2[destination].insert({timestamp, source});
        return true;
    }
    
    vector<int> forwardPacket() {
        if (q.empty()) return {};

        // answer vector
        vector<int> v = {get<0>(q.front()), get<1>(q.front()), get<2>(q.front())};

        // Remove it from both maps
        mp1[{get<0>(q.front()), get<1>(q.front()), get<2>(q.front())}]--;
        mp2[get<1>(q.front())].erase({get<2>(q.front()), get<0>(q.front())});
        q.pop();
        return v;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        int i = mp2[destination].order_of_key({startTime, 0}), j = mp2[destination].order_of_key({endTime + 1, 0});
        // order_of_key is a function in pbds
        // i gives count of numbers smaller than startTime
        // j gives count of numbers smaller than endTime + 1
        return j - i;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
