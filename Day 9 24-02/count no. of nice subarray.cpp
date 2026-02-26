// personal approach

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> cnt(n + 1, 0);
        cnt[0] = 1;
        int ans = 0, t = 0;
        for (int v : nums) {
            t += v & 1;
            if (t - k >= 0) {
                ans += cnt[t - k];
            }
            cnt[t]++;
        }
        return ans;
    }
};


// sir ki approach

class Solution {
    public int numberOfSubarrays(int[] nums, int k) {
         int n = nums.length ; 
        int count = 0 ;
        int i = 0 , j = 0 , curr_Sum = 0 , Zero_Count = 0 ;
        while(j < n)
        {
            curr_Sum = curr_Sum + nums[j]%2 ;
            while(i < j && (curr_Sum > k || nums[i]%2 == 0))
            {
                if(nums[i]%2 == 1)
                {
                    Zero_Count = 0  ;
                }
                else
                {
                    Zero_Count++ ;
                }
                curr_Sum -= nums[i]%2 ;
                i++ ;
            }

            if(curr_Sum == k)
            {
                count = count + 1 + Zero_Count ;
            }
            j++ ;
        }
        return count ;
    }
}