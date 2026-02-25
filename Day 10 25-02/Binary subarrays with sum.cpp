class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> count;
        count[0] = 1;
        int curr_sum = 0;
        int total_subarrays = 0;

        for (int num : nums) {
            curr_sum += num;
            if (count.find(curr_sum - goal) != count.end()) {
                total_subarrays += count[curr_sum - goal];
            }
            count[curr_sum]++;
        }

        return total_subarrays;
    }
};




// sliding window approach


class Solution {
    public int numSubarraysWithSum(int[] nums, int goal) {
        
        int n = nums.length ; 
        int count = 0 ;
        int i = 0 , j = 0 , curr_Sum = 0 , Zero_Count = 0 ;
        while(j < n)
        {
            curr_Sum = curr_Sum + nums[j] ;
            while(i < j && (curr_Sum > goal || nums[i] == 0))
            {
                if(nums[i] == 1)
                {
                    Zero_Count = 0  ;
                }
                else
                {
                    Zero_Count++ ;
                }
                curr_Sum -= nums[i] ;
                i++ ;
            }

            if(curr_Sum == goal)
            {
                count = count + 1 + Zero_Count ;
            }
            j++ ;
        }
        return count ;
    }
}