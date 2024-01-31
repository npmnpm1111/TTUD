#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    // Khởi tạo mảng với hoán vị hiện tại
    std::vector<int> arr = {4, 3, 8, 2, 7, 6, 5, 1};

    // In hoán vị hiện tại
    std::cout << "Hoán vị hiện tại: ";
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Tìm hoán vị tiếp theo
    bool found = std::next_permutation(arr.begin(), arr.end());

    // Kiểm tra xem có hoán vị tiếp theo không
    if (found)
    {
        // In hoán vị tiếp theo
        std::cout << "Hoán vị tiếp theo: ";
        for (int num : arr)
        {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "Đây là hoán vị cuối cùng. Không có hoán vị tiếp theo." << std::endl;
    }

    return 0;
}
