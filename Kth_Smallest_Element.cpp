#include <iostream>
#include <vector>
#include <queue> // For priority_queue
using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        // Min-heap to store the k largest elements
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int num : nums)
        {
            minHeap.push(num);
            // If the heap size exceeds k, remove the smallest element
            if (minHeap.size() > k)
            {
                minHeap.pop();
            }
        }

        // The root of the min-heap will be the kth largest element
        return minHeap.top();
    }
};

// Example usage
int main()
{
    Solution solution;
    vector<int> nums1 = {3, 2, 1, 5, 6, 4};
    cout << "The 2nd largest element is: " << solution.findKthLargest(nums1, 2) << endl;

    vector<int> nums2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    cout << "The 4th largest element is: " << solution.findKthLargest(nums2, 4) << endl;

    return 0;
}
