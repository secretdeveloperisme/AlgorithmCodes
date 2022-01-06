// Flatten a nested array. You must account for varying levels of nesting.
/* 
  steamrollArray([[["a"]], [["b"]]]) should return ["a", "b"].
  steamrollArray([1, [2], [3, [[4]]]]) should return [1, 2, 3, 4].
  steamrollArray([1, [], [3, [[4]]]]) should return [1, 3, 4].
  steamrollArray([1, {}, [3, [[4]]]]) should return [1, {}, 3, 4].
  Your solution should not use the Array.prototype.flat() or Array.prototype.flatMap() methods.
*/

function steamrollArray(arr) {
  let newArr = []
  traversalArray(arr,newArr)
  console.log(newArr)
  return newArr
}
function traversalArray(arr, totalArr){
  if(typeof arr.push  == "function" )
    for(let value of arr){
      traversalArray(value, totalArr)
    }
  else 
    totalArr.push(arr)
    
}

steamrollArray([1, {}, [3, [[4]]]]);