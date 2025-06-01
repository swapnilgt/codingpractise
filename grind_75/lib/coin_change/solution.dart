import 'package:flutter/material.dart';

class Solution {
  int coinChange(List<int> coins, int amount) {
    if (amount == 0) return 0;
    // Initialising the dp with -1. Meaninig un-initialised.
    final List<int> dp = List.filled(amount + 1, -1);
    // Initializing the value for the zeorth as 0.
    dp[0] = 0;

    // Now building the dp.
    for (int i = 1; i <= amount; i++) {
      debugPrint("### Filling for amount: $i");
      // Iterting over each amount.
      for (int j = 0; j < coins.length; j++) {
        int minVal = 10001;
        // Checking if we will be able to use the current coin at the current
        // sum position.
        // if (coins[j] <= i) {
        //   int numCoins = (i / coins[j]).floor();
        //   int remAmount = i % coins[j];
        //   if (dp[i - remAmount * numCoins] + numCoins < minVal) {
        //     minVal = dp[i - remAmount] + numCoins;
        //   }
        // }
        ////////////////
        // Checking if the the current target amount is larger than the current
        // count in consideration.
        if (i - coins[j] >= 0) {
          debugPrint("!!! Running for coin: ${coins[j]}");
          if (dp[i - coins[j]] !=
                  -1 // Solution excluding the current coin value does exist.
              &&
              dp[i - coins[j]] + 1 < minVal) {
            debugPrint(
                "*** Min value updated to: ${dp[i - coins[j]] + 1} against existing value $minVal");
            minVal = dp[i - coins[j]] + 1;
          }
        }
        // If we have found any possible combination.
        if (minVal != 10001) {
          dp[i] = minVal;
        }
      }
    }
    return dp[amount];
  }
}
