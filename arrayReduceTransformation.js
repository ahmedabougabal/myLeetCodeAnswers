/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function (nums, fn, init) {
  let sum = init;
  if (nums.length === 0) {
    return init;
  } else {
    for (i = 0; i < nums.length; ++i) {
      sum = fn(sum, nums[i]);
    }
  }
  return sum;
};
