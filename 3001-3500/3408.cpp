#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class TaskManager {
private:
    struct Task {
        int userId, taskId, priority;

        // Default constructor
        Task() : userId(0), taskId(0), priority(0) {}

        // Parameterized constructor
        Task(int userId, int taskId, int priority)
            : userId(userId), taskId(taskId), priority(priority) {}

        // Define the comparison operator to maintain the correct order in the sorted container
        bool operator<(const Task& other) const {
            if (priority != other.priority) {
                return priority > other.priority; // Higher priority comes first
            }
            return taskId > other.taskId; // If priority is the same, higher taskId comes first
        }

        // Define the copy constructor
        Task(const Task& other) = default;
        // Define the move constructor
        Task(Task&& other) noexcept = default;

        // Define the copy assignment operator
        Task& operator=(const Task& other) = default;

        // Define the move assignment operator
        Task& operator=(Task&& other) noexcept = default;
    };

    map<Task, int> sortedTasks;
    unordered_map<int, Task> taskMap;

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto& task : tasks) {
            int userId = task[0], taskId = task[1], priority = task[2];
            add(userId, taskId, priority);
        }
    }

    void add(int userId, int taskId, int priority) {
        Task task(userId, taskId, priority);
        sortedTasks[task] = userId;
        taskMap[taskId] = task;
    }

    void edit(int taskId, int newPriority) {
        auto taskIt = taskMap.find(taskId);
        if (taskIt != taskMap.end()) {
            Task task = taskIt->second;
            sortedTasks.erase(task);
            task.priority = newPriority;
            sortedTasks[task] = task.userId;
            taskMap[taskId] = task;
        }
    }

    void rmv(int taskId) {
        auto taskIt = taskMap.find(taskId);
        if (taskIt != taskMap.end()) {
            Task task = taskIt->second;
            sortedTasks.erase(task);
            taskMap.erase(taskId);
        }
    }

    int execTop() {
        if (sortedTasks.empty()) {
            return -1;
        }
        auto topTask = sortedTasks.begin();
        Task top = topTask->first;
        sortedTasks.erase(topTask);
        taskMap.erase(top.taskId);
        return top.userId;
    }
};
