function palindrome(str) {
  str = str.replace(/\W|_|\s/g,"").toLowerCase()
  for(let i =0 ; i < str.length/2; i++){
    if(str[i] !== str[str.length-i-1])
      return false
  }
  return true
}

let result = palindrome("eye_");
console.log(result)