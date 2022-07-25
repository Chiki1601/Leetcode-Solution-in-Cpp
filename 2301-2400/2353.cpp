class FoodRatings {
public:
    struct comp{
          bool operator ()(const pair<int, string>& l, const pair<int, string>& r) const
          {
            if(l.first != r.first){
                return l.first > r.first;
            }
            else {
                return l.second < r.second;
            }
          }
    };
    
    unordered_map< string, set<pair<int, string>, comp>  > cuisinToFood;
    
    unordered_map<string, int> rate;
    unordered_map<string, string> foodToCuisin;
    
    FoodRatings(vector<string>& f, vector<string>& c, vector<int>& r) {
        for(int i=0; i<f.size(); i++){
            cuisinToFood[c[i]].insert({r[i], f[i]});
            foodToCuisin.insert({f[i], c[i]});
            rate.insert({f[i], r[i]});
        }
    }
    
    void changeRating(string f, int nr) {
        string c = foodToCuisin[f];
        int r = rate[f];
        rate[f] = nr;
        cuisinToFood[c].erase({r, f});
        cuisinToFood[c].insert({nr, f});
    }
    
    string highestRated(string c) {
        
        pair<int, string> p = *(cuisinToFood[c].begin());
        return p.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
