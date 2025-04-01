class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int activeCount = count(s.begin(), s.end(), '1');
    
        vector<pair<int, int>> segments;
        for (int i = 0, start = 0; i < n; i++) {
            if (i == n - 1 || s[i] != s[i + 1]) {
                segments.push_back({start, i - start + 1});
                start = i + 1;
            }
        }
        int segmentCount = segments.size();

        int maxPower = 20, INF = 1e9;
        vector<vector<int>> rmq(maxPower, vector<int>(segmentCount, -INF));
    
        for (int i = 0; i < segmentCount; i++) {
            if (s[segments[i].first] == '0' && i + 2 < segmentCount) {
                rmq[0][i] = segments[i].second + segments[i + 2].second;
            }
        }
        
        for (int power = 1, rangeLen = 2; power < maxPower; power++, rangeLen *= 2) 
            for (int i = 0, j = rangeLen - 1; j < segmentCount; i++, j++) 
                rmq[power][i] = max(rmq[power - 1][i], rmq[power - 1][i + rangeLen / 2]);
    
        auto getMaxInRange = [&](int left, int right) {
            if (left > right) return -INF;
            int power = __lg(right - left + 1);
            return max(rmq[power][left], rmq[power][right - (1 << power) + 1]);
        };
    
        vector<int> result;
        for (auto &query : queries) {
            int left = query[0], right = query[1];
            int leftIndex = upper_bound(segments.begin(), segments.end(), pair<int, int>(left, INF)) - segments.begin() - 1;
            int rightIndex = upper_bound(segments.begin(), segments.end(), pair<int, int>(right, INF)) - segments.begin() - 1;
    
            if (rightIndex - leftIndex + 1 <= 2) { 
                result.push_back(activeCount);
                continue; 
            }
    
            auto getSegmentSize = [&](int i) {
                if (i == leftIndex) return segments[leftIndex].second - (left - segments[leftIndex].first);
                if (i == rightIndex) return right - segments[rightIndex].first + 1;
                return segments[i].second;
            };
    
            auto calculateNewSections = [&](int i) {
                if (s[segments[i].first] == '1') return -INF;
                return getSegmentSize(i) + getSegmentSize(i + 2);
            };
    
            int bestIncrease = max(getMaxInRange(leftIndex + 1, rightIndex - 3), 0);
            bestIncrease = max(bestIncrease, calculateNewSections(leftIndex));
            bestIncrease = max(bestIncrease, calculateNewSections(rightIndex - 2));
    
            result.push_back(activeCount + bestIncrease);
        }
        return result;
    }
};
