class Solution {
    public int maxProfit(int[] prices) {
        int profit=0;
        int c=0;
        for(int i=0;i<prices.length-1;i++){
            c=c+prices[i+1]-prices[i];
            if(c<0)
                c=0;
            if(c>=0&&c>=profit)
                profit=c;
        }
        return profit;
    }
}