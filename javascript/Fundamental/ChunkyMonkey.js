/*
  Write a function that splits an array (first argument) into groups the length of size
  (second argument) and returns them as a two-dimensional array.
*/
function chunkArrayInGroups(arr, size) {
  let result = [];
  let indexArr = 0;
  let sizeOfDimension1 = 0;
  sizeOfDimension1 = Number.parseInt(arr.length / size);
  for(let i = 0; i < sizeOfDimension1; i++){
    let sizeArr = [];
    for(let j = 0; j< size; j++){
      sizeArr.push(arr[indexArr]);
      indexArr++;
    }
    result.push(sizeArr);
  }
  console.log(sizeOfDimension1)
  if(arr.length % size !=0){
    let remainingArr = [];
    let remaining = arr.length%size;
    for(let i = 0; i<remaining ;i++){
      remainingArr.push(indexArr);
      indexArr++;
    }
    result.push(remainingArr);
  }
     
  return result;
}
function chunkArrayInGroupsWithSplice(arr,size){
  let result = [];
  while(arr.length > 0){
    result.push(arr.splice(0,size));
  }
  return result;
}
chunkArrayInGroupsWithSplice(["a", "b", "c", "d"], 2)
// let r = chunkArrayInGroups([0, 1, 2, 3, 4, 5, 6], 3);
// console.log(r)