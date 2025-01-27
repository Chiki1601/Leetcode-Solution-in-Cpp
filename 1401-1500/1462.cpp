class Solution {
public:
    std::vector<bool> checkIfPrerequisite(int numCourses, std::vector<std::vector<int>>& prerequisites, std::vector<std::vector<int>>& queries) {
        std::vector<std::vector<bool>> relation(numCourses, std::vector<bool>(numCourses, false));
        std::vector<bool> ans;

        for (const auto& d : prerequisites) {
            relation[d[0]][d[1]] = true;
        }

        for (int i = 0; i < numCourses; i++) {
            for (int src = 0; src < numCourses; src++) {
                for (int target = 0; target < numCourses; target++) {
                    relation[src][target] = relation[src][target] || (relation[src][i] && relation[i][target]);
                }
            }
        }

        for (const auto& d : queries) {
            ans.push_back(relation[d[0]][d[1]]);
        }

        return ans;
    }
};
