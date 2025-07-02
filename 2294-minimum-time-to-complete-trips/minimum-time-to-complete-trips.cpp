class Solution {
public:
    bool isValid(vector<int> &time, long long mid, int totalTrips){
        long long currTrips=0;

        for(int i=0;i<time.size();i++){
            currTrips += mid / time[i];
        }

        if(currTrips >= totalTrips){
            return true;
        }

        return false;
        
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long start = 1;
        long long end = *min_element(time.begin(), time.end()) ;
        end = end * totalTrips;

        long long ans = LONG_MAX;;
        while(start <= end){
            long long mid = start + (end - start)/2;

            if(isValid(time, mid, totalTrips) == true){
                ans = mid;
                end = mid -1;
            }
            else{
                start = mid+1;
            }
        }

        return ans;
    }
};