#include <stdio.h>
#include <stdlib.h>

    int maxProfit(int* prices, int pricesSize) {
        int buy_value = prices[0];
        int max_profit = 0;

        if(pricesSize < 2) return 0;

        for(int i = 0;i<pricesSize;i++){

            if(prices[i]< buy_value){
             buy_value = prices[i];
            }

            int profit = prices[i] - buy_value;

            if(profit > max_profit){
                max_profit = profit;
            }
        }
        return max_profit;

    }

int main(){
    int Prices[6] = {7,6,5,3,1,4};
    int Arr_Size = sizeof(Prices)/sizeof(Prices[0]);
    printf("%d",maxProfit(Prices,Arr_Size));


}
