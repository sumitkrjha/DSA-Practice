typedef long long ll;
class Solution {
public:
    ll calculateTotalTime (vector<int>& piles, int hourly)
    {
        ll totalH=0;
        int n=piles.size();

        for(int i=0; i<n; i++)
        {
            totalH+=ceil( (double)(piles[i]) / (double)(hourly) );
        }
        return totalH;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
       ll low=1, high=*max_element(piles.begin(), piles.end());
       while(low<=high)
       {
            ll mid= low + (high-low)/2;
            ll totalH=calculateTotalTime(piles, mid);
            if(totalH<=h)
            {
                high=mid-1;
            }
            else{
                low=mid+1;
            }
       }
       return low;
    }
};