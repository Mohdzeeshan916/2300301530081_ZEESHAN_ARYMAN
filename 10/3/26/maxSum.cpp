#include <algorithm>
#include <vector>

class Solution {
  public:
    int maxSubarraySum(std::vector<int> &arr, int k) {
        int n = arr.size();
        
        int windowSum = 0;

        
        
        for(int i = 0; i < k; i++){
            windowSum += arr[i];
        }

        int maxSum = windowSum;

        
        for(int i = k; i < n; i++){
            windowSum += arr[i];      
            windowSum -= arr[i-k];    
            
            maxSum = std::max(maxSum, windowSum);
        }

        return maxSum;
    }
};