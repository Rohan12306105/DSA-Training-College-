// personal approach

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> dq;

        for (int i = 0; i < n; i++) {
            if (!dq.empty() && dq.front() <= i - k) 
                dq.pop_front();

            while (!dq.empty() && nums[dq.back()] <= nums[i]) 
                dq.pop_back();

            dq.push_back(i);

            if (i >= k - 1) 
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};


// sir ki approach

#include <vector>
#include <map>

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        int i = 0, j = 0, count = 0;
        int n = nums.size();
        if (n == 1 || k == 1) return nums;
        std::vector<int> ans(n - k + 1);
        std::map<int, int> map;
        while (j < n) {
            map[nums[j]]++;

            if (j - i + 1 > k) {
                map[nums[i]]--;
                if (map[nums[i]] == 0) {
                    map.erase(nums[i]);
                }
                i++;
            }
            if (j - i + 1 == k) {
                ans[count] = map.rbegin()->first;
                count++;
            }
            j++;
        }
        return ans;
    }
};