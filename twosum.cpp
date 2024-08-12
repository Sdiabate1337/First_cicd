#include <iostream>
#include <vector>
#include <map>

std::vector<int> twoSum(const std::vector<int>& nums, int target) {
    std::map<int, int> numMap; // map to store value and its index
    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        if (numMap.find(complement) != numMap.end()) {
            return std::vector<int>{numMap[complement], i};
        }
        numMap[nums[i]] = i;
    }
    // In case there is no solution, but according to the problem, this should never happen
    return std::vector<int>();
}

int main() {
    std::vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);

    int target = 9;
    std::vector<int> result = twoSum(nums, target);

    if (!result.empty()) {
        std::cout << "Indices: [" << result[0] << ", " << result[1] << "]\n";
    } else {
        std::cout << "No solution found.\n";
    }

    return 0;
}
