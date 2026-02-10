class RideSharingSystem {
    deque<int> rider, driver;
public:
    RideSharingSystem() {}
    
    void addRider(int riderId) {
        rider.push_back(riderId);
    }
    
    void addDriver(int driverId) {
        driver.push_back(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        if(rider.empty() || driver.empty())
            return vector<int>{-1,-1};
        vector<int> ans = {driver.front(),rider.front()};
        driver.pop_front();
        rider.pop_front();
        return ans;
    }
    
    void cancelRider(int riderId) {
        auto it = find(rider.begin(), rider.end(), riderId);
        if (it != rider.end()) 
        {
            rider.erase(it);
        }
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */
