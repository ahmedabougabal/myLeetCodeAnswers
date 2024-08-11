/**
 * @param {Function} fn
 * @param {number} t milliseconds
 * @return {Function}
 */
var debounce = function (fn, t) {
  let timeout;
  return function (...args) {
    if (timeout) {
      clearTimeout(timeout);
    }
    timeout = setTimeout(() => {
      fn(...args)
    }, t);
  }
};

/**
* const log = debounce(console.log, 100);
* log('Hello'); // cancelled
* log('Hello'); // cancelled
* log('Hello'); // Logged at t=100ms
*/



// Suppose you have a search input field on a website. Every time a user types a letter, a function is triggered to fetch search results from a server.

// Without Debounce
// If the user types "hello" quickly, the function might be called five times in rapid succession: once for each letter ("h", "e", "l", "l", "o"). This could result in five separate server requests, which is inefficient.

// With Debounce
// By using a debounce function with a delay of t = 300ms:

// The function will only execute 300 milliseconds after the user stops typing.
// If the user types "hello" quickly, the debounce function will cancel the earlier calls and only execute once, fetching search results for "hello" after the user has finished typing and paused for 300 milliseconds.
// This prevents unnecessary server requests and improves performance.
