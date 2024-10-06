typedef long long ll;
class Solution {
public:
    int possible (vector<int>& bloomDay, int day, int m, int k)
    {
        int cnt=0, noOfB=0;
        int n=bloomDay.size();
        for(int i=0; i<n; i++){
            if(bloomDay[i]<=day){
                cnt++;
            }
            else{
                noOfB+=(cnt/k);
                cnt=0;
            }
        }
        noOfB+=(cnt/k);
        return noOfB>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if((ll)m*k > n) return -1;
        int low=*min_element(bloomDay.begin(), bloomDay.end());
        int high=*max_element(bloomDay.begin(), bloomDay.end());
        while(low<=high)
        {
            int mid=low + ((high-low)/2);
            if(possible(bloomDay, mid, m, k)){
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
};