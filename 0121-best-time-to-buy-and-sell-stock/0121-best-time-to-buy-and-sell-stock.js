/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    var temp=0;
    var n=prices.length
    var min_till_now=1e9;
    for(var i=0;i<n;i++)
    {
        temp=Math.max(temp,prices[i]-min_till_now);
        min_till_now=Math.min(min_till_now,prices[i]);
    }

    return temp
};