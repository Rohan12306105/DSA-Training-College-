class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int res = 0;
		
		//First k elements in our window
        for(int i=0;i<k;i++){
            res+=cardPoints[i];
        }
        int curr=res;
        for(int i=k-1;i>=0;i--) {
			//We remove the last visited element and add the non-visited element from the last
            curr-=cardPoints[i]; // this drops the left hand card/element
            curr+=cardPoints[cardPoints.size()-k+i];// this picks up the right most card / element 
			
            //We check the maximum value any possible combination can give
			res = max(res, curr); // then we find the max 
        }
        
        return res;
    }
};