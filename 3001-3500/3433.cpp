class Solution {
public:
      vector<int> extractIntegers(string& str) {
        vector<int> result;
        stringstream ss(str);
        string id;
        while (ss >> id) result.push_back(stoi(id.substr(2)));
        return result;
    }

    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        auto comp = [](vector<string>& a, vector<string>& b){
            if(stoi(a[1]) == stoi(b[1])) return a[0][0] > b[0][0];
            return stoi(a[1]) < stoi(b[1]);
        };
        vector<int> ans(numberOfUsers, 0), userStatus(numberOfUsers, 1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        int all = 0;

        sort(events.begin(), events.end(), comp);
        for(int i = 0; i < events.size(); ++i){
            if(events[i][0] == "MESSAGE"){
                while(!pq.empty() && pq.top().first <= stoi(events[i][1])) { userStatus[pq.top().second]++; pq.pop(); }
                if(events[i][2] == "ALL") all++;
                else if(events[i][2] == "HERE"){
                    for(int i = 0; i < userStatus.size(); ++i) ans[i] += (userStatus[i] == 1)?1:0;
                }else{
                    vector<int> t = extractIntegers(events[i][2]);
                    for(int i: t) ans[i] += 1;
                }
            }else{
                pq.push({ stoi(events[i][1]) + 60, stoi(events[i][2])}); 
                userStatus[stoi(events[i][2])]--;
            }
        }
        for(int i = 0; i < userStatus.size(); ++i) ans[i] += all;
        return ans;
    }
};

