class Solution {
private:
    int lowerBound(const vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1, ans = nums.size();
        while (l <= h) {
            int mid = (l + h) / 2;
            if (nums[mid] >= target) {
                 ans = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }

    int upperBound(const vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1, ans = nums.size();
        while (l <= h) {
            int mid = (l + h) / 2;
            if (nums[mid] > target) {
                ans = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = lowerBound(nums, target);
        int last = upperBound(nums, target) -1;

        if (first == nums.size() || first > last)
            return {-1, -1};

        return {first, last};
    }
};