#include <iostream>
#include <vector>
#include <string>
#include <set>

// Function to find the longest common substrings between two strings
std::set<std::string> getLongestCommonSubstrings(const std::string& str1, const std::string& str2, int& maxLength) {
    int len1 = str1.size();
    int len2 = str2.size();

    // Initialize a 2D dynamic programming table
    std::vector<std::vector<int>> dp(len1 + 1, std::vector<int>(len2 + 1, 0));
    maxLength = 0;  // Reset maxLength to 0
    std::set<std::string> commonSubstrings;  // Set to store the longest common substrings
    
    // Populate the dp table by comparing substrings
    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;

                // If a longer common substring is found, update maxLength and clear the set
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    commonSubstrings.clear();
                    commonSubstrings.insert(str1.substr(i - maxLength, maxLength));
                }
                // If another substring of the same length is found, add it to the set
                else if (dp[i][j] == maxLength) {
                    commonSubstrings.insert(str1.substr(i - maxLength, maxLength));
                }
            }
        }
    }

    // Display the DP table
    std::cout << "\nDP Table:\n";
    for (const auto& row : dp) {
        for (int value : row) {
            std::cout << value << " ";
        }
        std::cout << "\n";
    }

    return commonSubstrings;
}

int main() {
    std::string str1, str2;

    // Get input strings from the user
    std::cout << "Enter the first string: ";
    std::cin >> str1;
    std::cout << "Enter the second string: ";
    std::cin >> str2;

    int maxLength = 0;  // Variable to hold the maximum length of common substrings

    // Find the longest common substrings
    std::set<std::string> result = getLongestCommonSubstrings(str1, str2, maxLength);

    // Display the longest common substrings and their length
    std::cout << "\nLongest Common Substring(s):\n";
    for (const auto& substring : result) {
        std::cout << substring << " (Length: " << maxLength << ")\n";
    }

    return 0;
}
