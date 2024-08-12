/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = function (functions) {
  return new Promise((resolved, rejected) => {
    const arr = [];
    let counter = 0;
    for (let i = 0; i < functions.length; ++i) {
      functions[i]().then((res) => {
        arr[i] = res;
        counter++;
        if (counter === functions.length) {
          resolved(arr);
        }
      }
      ).catch(rejected)
    }
  })
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */

// my explanation to the logic i implemented :D
// the logic implemented above is the implementation of the Promise.all 
// built in method, where you have an array of functions that each of them
//  returns a promise and you need to return the resolved results of each 
//  promise so you store the resolved result of each promise in an array , 
//  so you need to initialize an empty array to store these resolved values while
//  you loop at every function to call it "functions[i]()", 
//  and for every promise resolved you add +1 to the counter variable, and 
//  then an if condition to check that if the counter is equal to the 
//  functions count, if yes , return the array , if no catch the rejected
//   and don't return anything.