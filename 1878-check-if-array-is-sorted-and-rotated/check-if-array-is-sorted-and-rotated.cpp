class Solution {
public:
    bool check(vector<int>& nums) {
    int n = nums.size();
    int count = 0; // This will count the number of places where the order is violated

    // Check for the number of times the array violates the non-decreasing order
    for(int i = 1; i < n; i++) {
        if(nums[i] < nums[i - 1])
            count++; // Increment count when current element is less than previous
    }

    // Check the circular condition: last element should not be greater than the first
    // if rotation happened, nums[n-1] > nums[0] indicates one more violation
    if(nums[n - 1] > nums[0])
        count++;

    // For a rotated sorted array, there can be at most one such violation
    return count > 1 ? false : true;
}
};