class Solution {
public:
    int sumOfA(vector<int>& weights)
    {
        int sum=0;
        int n=weights.size();
        for(int i=0; i<n; i++){
            sum+=weights[i];
        }
        return sum;
    }
    int daysReq(vector<int>& weights, int cap)
    {
        int dayCnt=1, load=0;
        int n=weights.size();
        for(int i=0; i<n; i++)
        {
            if(load+weights[i] > cap)
            {
                dayCnt++;
                load=weights[i];
            }
            else{
                load+=weights[i];
            }            
        }
        return dayCnt;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(), weights.end());
        int high=sumOfA(weights);
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(daysReq(weights, mid)<=days){
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
};