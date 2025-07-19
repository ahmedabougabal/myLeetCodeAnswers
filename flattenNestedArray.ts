type MultiDimensionalArray = (number | MultiDimensionalArray)[];

var flat = function (arr: MultiDimensionalArray, n: number): MultiDimensionalArray {
    const result: MultiDimensionalArray = [];
    if (n === 0)
        return arr;

    for (const val of arr) {
        if (Array.isArray(val)) {
            result.push(...flat(val, n - 1)); // using this spread operator here to push the elements in the subarray encountered
            // into the results array as separate values to the preexisting values, not pushing them as nested subarrays to maintain the flat nature 
        } else {
            result.push(val);
        }
    }
    return result;
};

