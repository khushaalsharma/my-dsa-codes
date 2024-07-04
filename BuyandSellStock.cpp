// ALL QUESTIONS RELATED TO BUY AND SELL STOCK FROM LEETCODE

//1.) Buy and Sell Stock II
/*
use a parameter buy to tell if we are allowed to buy the stock or not as we can buy multiple but hold only one stock
buy = 1 -> we can buy stock 
  option 1: buy it, then net profit = profit - price of stock
  option 2: skip
buy = 0 -> we can sell the stock
  option 1: sell now then net profit = profit + price of stock
  option 2: skip
*/

class Solution {
public:
    int solve(vector<int>& prices, int index, int buy, vector<vector<int>> &dp){
        if(index >= prices.size()){
            return 0;
        }

        if(dp[index][buy] != -1){
            return dp[index][buy];
        }

        int profit = 0;
        if(buy){//we are allowed to buy
            //if we buy a stock its price will be added to net profit as negative value
            int bought = solve(prices, index+1, 0, dp) - prices[index];
            int notBought = solve(prices, index+1, 1, dp);

            profit = max(bought, notBought);
        }
        else{
            //if buy == 0 then we can either sell it or skip
            int sold = prices[index] + solve(prices, index+1, 1, dp);
            int notSold = solve(prices, index+1, 0, dp);

            profit = max(sold, notSold);
        }

        return dp[index][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int buy = 1; //buy will tell if we are allowed to buy a stock or not buy = 1 -> allowed
        int n = prices.size()+1;

        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        return solve(prices, 0, buy, dp);
    }
};


//2.) Buy and Sell Stock III

/*
Similar to previous here we can just make utmost 2 transactions, thus we monitor it using buyCount variable
We use a 3D memoization array as three parameters change -> index, buyCount and buy
*/
class Solution {
public:
    int solve(vector<int>&prices, int index, int buy, int buyCount, vector<vector<vector<int>>>& dp){
        if(index >= prices.size()){
            return 0;
        }

        if(dp[index][buyCount][buy] != -1){
            return dp[index][buyCount][buy];
        }

        int profit = 0;

        if(buyCount < 2 && buy){
            int bought = solve(prices, index+1, 0, buyCount+1, dp) - prices[index];
            int notBought = solve(prices, index+1, 1, buyCount, dp);

            profit = max(bought, notBought);
        }
        else if(!buy){
            int sold = prices[index] + solve(prices, index+1, 1, buyCount, dp);
            int notSold = solve(prices, index+1, 0, buyCount, dp);

            profit = max(sold, notSold);
        }

        return dp[index][buyCount][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int buyCount = 0;
        int buy = 1;
        int n = prices.size();

        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(3, vector<int>(2, -1)));
        return solve(prices, 0, buy, buyCount, dp);
    }
};

//3.) Buy and Sell Stock IV
class Solution {
public:
    int solve(vector<int>& prices, int k, int index, int buy, int buyCount, vector<vector<vector<int>>>& dp){
        if(index >= prices.size()){
            return 0;
        }

        if(dp[index][buyCount][buy] != -1){
            return dp[index][buyCount][buy];
        }

        int profit = 0;

        if(buyCount < k && buy){
            int bought = solve(prices, k, index+1, 0, buyCount+1, dp) - prices[index];
            int notBought = solve(prices, k, index+1, 1, buyCount, dp);

            profit = max(bought, notBought);
        }
        else if(!buy){
            int sold = prices[index] + solve(prices, k, index+1, 1, buyCount, dp);
            int notSold = solve(prices, k, index+1, 0, buyCount, dp);

            profit = max(sold, notSold);
        }

        return dp[index][buyCount][buy] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int buy = 1;
        int buyCount = 0;

        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1, vector<int>(2, -1)));

        return solve(prices, k, 0, buy, buyCount, dp);
    }
};

//4.) Buy and Sell Stock V with transaction fee
class Solution {
public:
    int solve(vector<int>& prices, int fee, int index, int buy, vector<vector<int>>& dp){
        if(index >= prices.size()){
            return 0;
        }

        if(dp[index][buy] != -1){
            return dp[index][buy];
        }

        int profit = 0;
        if(buy){
            int bought = solve(prices, fee, index+1, 0, dp) - prices[index] - fee;
            int notBought = solve(prices, fee, index+1, 1, dp);

            profit = max(bought, notBought);
        }
        else{
            int sold = solve(prices, fee, index+1, 1, dp) + prices[index];
            int notSold = solve(prices, fee, index+1, 0, dp);

            profit = max(sold, notSold);
        }

        return dp[index][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int buy = 1;
        int n = prices.size();

        vector<vector<int>> dp(n+1, vector<int>(2, -1));

        return solve(prices, fee, 0, buy, dp);
    }
};
