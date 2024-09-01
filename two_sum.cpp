#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Function to find the indices of two numbers that add up to the target

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numMap; // Hash map to store number and its index

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i]; // Find the complement of the current number
        if (numMap.find(complement) != numMap.end()) {
            // Return the indices if the complement is found in the map
            return {numMap[complement], i};
        }
        // Store the current number and its index in the map
        numMap[nums[i]] = i;
    }
    
    return {}; // if no solution exists, return an empty vector
}

int main() {
    vector<int> nums = {2, 7, 11, 15}; // input
    int target = 9; // target
    
    // Get the indices from the twoSum function
    vector<int> result = twoSum(nums, target);
    
    // Print the indices
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    
    return 0;
}
