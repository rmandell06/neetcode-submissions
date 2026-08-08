class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        left = 0
        right = 1
        length = len(prices)
        max_profit = -1

        while right < length:
            if prices[left] < prices[right]:
                profit = prices[right] - prices[left]
                max_profit = max(max_profit, profit)
            else:
                left = right
            right += 1
        return max_profit if max_profit > 0 else 0