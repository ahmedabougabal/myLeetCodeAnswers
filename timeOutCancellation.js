/**
 * @param {Function} fn
 * @param {Array} args
 * @param {number} t
 * @return {Function}
 */
//!we should return cancel function to clear the scheduled timeout 
//! if the function isnot called yet, we should return a cancel function
var cancellable = function (fn, args, t) {
  const timed = setTimeout(() => {
    fn(...args);
  }, t)

  let toCancel = function cancelIt() {
    clearTimeout(timed);
  }
  return toCancel;
};

/**
*  const result = [];
*
*  const fn = (x) => x * 5;
*  const args = [2], t = 20, cancelTimeMs = 50;
*
*  const start = performance.now();
*
*  const log = (...argsArr) => {
*      const diff = Math.floor(performance.now() - start);
*      result.push({"time": diff, "returned": fn(...argsArr)});
*  }
*       
*  const cancel = cancellable(log, args, t);
*
*  const maxT = Math.max(t, cancelTimeMs);
*           
*  setTimeout(cancel, cancelTimeMs);
*
*  setTimeout(() => {
*      console.log(result); // [{"time":20,"returned":10}]
*  }, maxT + 15)
*/