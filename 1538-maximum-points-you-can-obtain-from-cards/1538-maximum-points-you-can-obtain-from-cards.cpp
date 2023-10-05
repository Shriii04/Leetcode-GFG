class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int i=0,j=0;
        int sum=0;
        int total=accumulate(card.begin(),card.end(),0);
        int minsum=INT_MAX;
        for(j=0;j<card.size()-k;j++){
            sum+=card[j];
        }
        while(j<card.size()){
            minsum = min(minsum,sum);
            sum-=card[i++];
            sum+=card[j++];
        }
        minsum = min(minsum,sum);
        return total-minsum;
    }
};