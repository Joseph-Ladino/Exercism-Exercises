//
// This is only a SKELETON file for the 'Change' exercise. It's been provided as a
// convenience to get you started writing code faster.
//

export class Change {
    calculate(coins, amount) {
        coins.sort((a, b) => b - a);

        if (amount < 0) throw new Error('Negative totals are not allowed.');

        var temp = amount, modifier = 0, options = [];

        while (coins.length > 0) {
            var out = [];

            for (var i = 0; i < coins.length; i++) {
                var coin = coins[i];
                var step_up = (coins[i + 1]) ? coins[i + 1] * modifier : 0;
                var temp2 = Math.abs(amount - step_up);
                var coin_count = (temp2 - (temp2 % coin)) / coin;

                if (coin_count >= 1 && amount >= coin_count * coin) {
                    for (var j = 0; j < coin_count; j++) {
                        out.push(coin);
                    }
                    amount -= coin * coin_count;
                }
            }

            out.sort((a, b) => a - b);

            if (out.reduce((i, j) => i + j, 0) == temp) options.push(out);
            amount = temp;
            modifier++;
            if (coins[0] * modifier > temp) { coins.shift(); modifier = 0 }
        }

        if (options.length == 0 && amount != 0) throw new Error(`The total ${amount} cannot be represented in the given currency.`);
        else return options.reduce((recurring, current) => (current.length <= recurring.length) ? current : recurring);
    }
}
