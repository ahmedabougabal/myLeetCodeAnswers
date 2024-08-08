//! first method

/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */
var timeLimit = function (fn, t) {

  return async function (...args) {
    return new Promise((resolve, reject) => {
      const timeOut = setTimeout(() => {
        reject("Time Limit Exceeded");
      }, t);
      fn(...args)
        .then(acc => {
          resolve(acc);
          clearTimeout(timeOut);
        })
        .catch(ref => {
          reject(ref);
          clearTimeout(timeOut);
        })
    });
  };
};

//! second method

/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */
var timeLimit = function (fn, t) {

  return async function (...args) {
    return new Promise((resolve, reject) => {
      const timeOut = setTimeout(() => {
        reject("Time Limit Exceeded");
      }, t);
      fn(...args)
        .then(resolve)
        .catch(reject)
        .finally(() => {
          clearTimeout(timeOut)
        });
    });
  };
};
