#include <iostream>
#include <vector>
#include <numeric> // Thư viện cho hàm accumulate

int findPartitionIndex(const std::vector<int>& nums) {
    int totalSum = std::accumulate(nums.begin(), nums.end(), 0);
    int leftSum = 0;

    for (size_t i = 0; i < nums.size(); ++i) {
        totalSum -= nums[i];
        if (leftSum == totalSum) {
            return i;
        }
        leftSum += nums[i];
    }

    return -1;
}

int main() {
    std::vector<int> nums = {6, -4, -3, 2, 3};
    int index = findPartitionIndex(nums);

    if (index != -1) {
        std::cout << "Chỉ số phân chia là: " << index << std::endl;
    } else {
        std::cout << "Không tìm thấy chỉ số phân chia phù hợp." << std::endl;
    }

    return 0;
}
