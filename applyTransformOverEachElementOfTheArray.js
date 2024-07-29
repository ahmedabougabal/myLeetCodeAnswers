/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function (arr, fn) {
  var result = [];
  arr.forEach((item, index) => {
    result.push(fn(arr[index], item));
  });
  return result;
}