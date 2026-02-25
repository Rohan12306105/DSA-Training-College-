class Solution {
    public int maxSubarraySum(int[] arr, int k) {
        // Code here
        if(arr.length < k){
            return -1;
        }
        int max_sum = 0;
        for(int i=0;i<k;i++){
            max_sum+=arr[i];
        }
        int win_sum = max_sum;
        for(int i=k;i<arr.length;i++){
            win_sum += arr[i] - arr[i-k];
            max_sum = Math.max(win_sum,max_sum);
        }
        return max_sum;
    }
}