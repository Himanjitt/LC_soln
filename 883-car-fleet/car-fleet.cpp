class Solution {
public:
    typedef pair<int, int> p;

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<p> car;
        int n = position.size();

        for (int i = 0; i < n; i++) {
            car.push_back({position[i], speed[i]});
        }
        
        sort(car.begin(), car.end(), greater<p>());
       
        vector<double> v;

        for (auto ele : car) {
            double time = (double)(target - ele.first) / ele.second;

            if (v.empty() == false && v.back() >= time) {
                continue;
            }
            v.push_back(time);
        }
        return v.size();
    }
};