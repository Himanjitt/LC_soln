class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        // BFS queue to store {current value, steps}
        queue<pair<int, int>> q;
        unordered_set<int> visited;

        q.push({start, 0});
        visited.insert(start);

        while (!q.empty()) {
            auto [x, steps] = q.front();
            q.pop();

            // If we reach the goal, return the number of steps
            if (x == goal) {
                return steps;
            }

            // Perform all possible operations
            for (int num : nums) {
                vector<int> nextStates = {x + num, x - num, x ^ num};

                for (int next : nextStates) {
                    // If next is valid and not visited
                    if (next == goal) {
                        return steps + 1;
                    }
                    if (next >= 0 && next <= 1000 && visited.count(next) == 0) {
                        q.push({next, steps + 1});
                        visited.insert(next);
                    }
                }
            }
        }

        // If we can't reach the goal, return -1
        return -1;
    }
};