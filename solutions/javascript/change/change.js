export class Change {
    calculate(coins, amount) {

        // sorts the coin values from least to greatest
        coins.sort((a, b) => b - a);

        if (amount < 0) throw new Error('Negative totals are not allowed.');

        var temp_amount = amount, multiplier = 0, patterns = [];


        // a messy little loop for finding just about all the patterns of coins that make up a given amount of money
        while (coins.length > 0) {
            var pattern = [];

            // a messy little loop for finding a patter n
            for (var i = 0; i < coins.length; i++) {
                var coin = coins[i];

                // this is used to allow a minimum for the next coin
                var next = (coins[i + 1]) ? coins[i + 1] * multiplier : 0;
                var max_amount = Math.abs(temp_amount - next);

                // how many of this coin there is in the pattern
                var coin_count = (max_amount - (max_amount % coin)) / coin;

                // if the coin fits, add it to the array
                if (coin_count >= 1 && temp_amount >= coin_count * coin) {
                    pattern = pattern.concat(new Array(coin_count).fill(coin));
                    temp_amount -= coin * coin_count;
                }
            }

            // sorts the array of coins from least to greatest
            pattern.sort((a, b) => a - b);

            // this pattern is only valid if the coins add up to the correct amount
            if (pattern.reduce((i, j) => i + j, 0) == amount) patterns.push(pattern);

            temp_amount = amount;
            multiplier++;

            // if the smallest coin times the multiplier is greater than the amount, reset the multiplier and yeet the smallest coin
            if (coins[0] * multiplier > amount) {
                coins.shift();
                multiplier = 0;
            }
        }

        // throw errors if necessary
        if (patterns.length == 0 && temp_amount != 0) throw new Error(`The total ${amount} cannot be represented in the given currency.`);

        // return pattern with the least amount of coins
        else return patterns.reduce((recurring, current) => (current.length <= recurring.length) ? current : recurring);
    }
}
