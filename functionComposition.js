/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function (functions) {
  if (functions.length === 0) {
    return 0;
  }
  return function (x) {
    let result = x;
    for (var i = functions.length - 1; i >= 0; i--) {
      result = functions[i](result);
    }
    return result;
  }
};

/**
* const fn = compose([x => x + 1, x => 2 * x])
* fn(4) // 9
*/