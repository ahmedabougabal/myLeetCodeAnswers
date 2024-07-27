/**30 days of js  */
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


/** ways on how to solve this question
 * 
 * How to create an Object
method 1

let object = {
    method1: function(arg1) {
        // some code
    },
    method2: function(arg2) {
        // some code
    }
};
return object

-------------method 2

let object = new Object();
object.method1 = function(arg) {
      // some code
}
object.method2 = function(arg) {
      // some code
}
return object
--------------------------------
How to create a function
method 1

functionNameOne: function(arg) => {
    // do something.. return something..
}
    -----------------------------------
method 2

functionNameOne(arg) {
    // do something.. return something..
}
------------------------------------
method 3

functionNameOne: (arg) => returnValue
How to throw an error
throw new Error("message");
 * 
 * 
 */