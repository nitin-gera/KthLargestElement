#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int KthLargest1(vector<int> &nums, size_t k)
{
    size_t n = nums.size();
    sort(nums.begin(), nums.end());

    return nums[n - k];
}

int KthLargest2(vector<int> &nums, size_t k)
{
    priority_queue<int, vector<int>, greater<int> > pq;

    for(int i : nums)
    {
        if(pq.size() < k)
            pq.push(i);
        else
        {
            if(pq.top() < i)
            {
                pq.pop();
                pq.push(i);
            }
        }
    }

    return pq.top();
}

int main()
{
    vector<int> nums;

    size_t k = 2;

    for(int i(0); i < 10; i++)
        nums.push_back(rand() % 100);

    cout << "Array:";
    for(int i : nums)
        cout << i << "\n";

    cout << k << " Largest1:" << KthLargest1(nums, k) << endl;

    cout << k << " Largest2:" << KthLargest2(nums, k) << endl;
}
