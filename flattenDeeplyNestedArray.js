/**
 * @param {Array} arr
 * @param {number} depth
 * @return {Array}
 */
var flat = function (arr, n) {
  if(n ==0){
    return arr;
  }
  let flattend = []; // an arr to store the flattned arrays altogether
  for(let i =0; i < arr.length; ++i){
    if(Array.isArray(arr[i]) && n >0){
      flattend.push(...flat(arr[i] , n-1)); // spread operator to store as many as 
      // arrays found inside a single array
    }
    else{
      flattend.push(arr[i]);
    }
  }
  return flattend;
};