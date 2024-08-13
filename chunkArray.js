/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
var chunk = function (arr, size) {
  let myArr = new Array();
  for (let i = 0; i < arr.length; i += size) {
    myArr.push(arr.slice(i, size + i));
  }
  return myArr;
};
