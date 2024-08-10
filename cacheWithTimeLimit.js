var TimeLimitedCache = function () {
  this.cache = new Map();
};

/** 
 * @param {number} key
 * @param {number} value
 * @param {number} duration time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */

TimeLimitedCache.prototype.set = function (key, value, duration) {
  const now = Date.now();
  const existing = this.cache.get(key);
  let existed = false;

  if (existing && existing.expires > now) {
    existed = true;
    clearTimeout(existing.timeOutId);
  };

  const timeOutId = setTimeout(() => {
    this.cache.delete(key);
  }, duration);

  this.cache.set(key, {
    value: value,
    expires: duration + now,
    timeOutId: timeOutId
  })

  return existed;

};

/** 
 * @param {number} key
 * @return {number} value associated with key
 */
TimeLimitedCache.prototype.get = function (key) {
  const now = Date.now();
  const getKey = this.cache.get(key);
  if (getKey && getKey.expires > now) {
    return getKey.value;
  } else {
    return -1;
  }

};

/** 
 * @return {number} count of non-expired keys
 */
TimeLimitedCache.prototype.count = function () {
  let count = 0;
  const now = Date.now();
  for (let keyFound of this.cache.values()) {
    if (keyFound.expires > now) {
      count++;
    }
    return count;
  }
};

/**
 * const timeLimitedCache = new TimeLimitedCache()
 * timeLimitedCache.set(1, 42, 1000); // false
 * timeLimitedCache.get(1) // 42
 * timeLimitedCache.count() // 1
 */