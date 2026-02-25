#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int binarySearch(vector<int>& nums, int target, bool findFirst) {
        int low = 0, high = nums.size() - 1;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                ans = mid;
                if (findFirst)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = binarySearch(nums, target, true);
        int last  = binarySearch(nums, target, false);
        return {first, last};
    }
};

int main() {
    Solution obj;
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;

    vector<int> result = obj.searchRange(nums, target);

    cout << "[" << result[0] << ", " << result[1] << "]";

    return 0;
}