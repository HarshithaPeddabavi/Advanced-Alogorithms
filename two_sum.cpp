#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Function for determining the indices of two numbers that add up to the target.

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numMap; // Hash map for storing numbers and their indexes

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i]; // Find the complement of the current number
        if (numMap.find(complement) != numMap.end()) {
            // Return the indices if the complement exists in the map
            return {numMap[complement], i};
        }
        // Record the current number and its index in the map
        numMap[nums[i]] = i;
    }
    
    return {}; // if no solution exists, return an empty vector
}

int main() {
    vector<int> nums = {3,2,4}; // input
    int target = 6; // target
    
    // Retrieve the indices from the twoSum function
    vector<int> result = twoSum(nums, target);
    
    // Print the indices
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    
    return 0;
}
