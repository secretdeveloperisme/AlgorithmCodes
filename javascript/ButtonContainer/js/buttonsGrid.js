let btns = document.querySelectorAll("#btns *")
console.log(btns);

let arr = [1,2,3,6,9,8,7,4]

btns[4].addEventListener("click",function(event){
  arr.unshift(arr.pop())
  btns[0].innerHTML = arr[0]
  btns[1].innerHTML = arr[1]
  btns[2].innerHTML = arr[2]
  btns[5].innerHTML = arr[3]
  btns[8].innerHTML = arr[4]
  btns[7].innerHTML = arr[5]
  btns[6].innerHTML = arr[6]
  btns[3].innerHTML = arr[7]
})
