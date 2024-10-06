class Solution {
public:
    bool sumOfDivisor(vector<int>& nums, int d, int threshold )
    {
        int sum=0;
        int n=nums.size();
        for(int i=0; i<n; i++)
        {
            sum+=ceil( (double)(nums[i]) / d );
        }
        if(sum<=threshold) return true;
        else return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=*max_element(nums.begin(), nums.end());

        while(low<=high){
            int mid=low +(high-low)/2;
            if(sumOfDivisor(nums, mid,threshold)){
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
};