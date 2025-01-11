class Solution {
public:
    typedef pair<int, int> p;

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<p> car;
        int n = position.size();

        for (int i = 0; i < n; i++) {
            car.push_back({position[i], speed[i]});
        }
        sort(car.begin(), car.end(),
             [](const p& a, const p& b) { return a.first > b.first; });

       
        stack<double> s;

        for (auto ele : car) {
            double time = (double)(target - ele.first) / ele.second;

            if (s.empty() == false && s.top() >= time) {
                continue;
            }
            s.push(time);
        }
        return s.size();
    }
};