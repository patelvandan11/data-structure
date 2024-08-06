#include <iostream>
#include <vector>

int findSingleDigit(std::vector<int> &arr)
{
    int result = 0;
    for (int num : arr)
    {
        result = result ^ num;
    }
    return result;
}

int main()
{
    std::vector<int> arr = {1, 2, 3, 5, 3, 2, 1};
    int singleDigit = findSingleDigit(arr);
    std::cout << singleDigit << std::endl;
    return 0;
}