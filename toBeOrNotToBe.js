/**
 * @param {string} val
 * @return {Object}
 */
var expect = function (val) {
  let object = {
    toBe: function (arg1) {
      if (val === arg1) {
        return true;
      } else {
        throw new Error("Not Equal");
      }
    },
    notToBe: function (arg2) {
      if (val === arg2) {
        throw new Error("Equal");
      } else {
        return true;
      }
    }
  };
  return object

};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */