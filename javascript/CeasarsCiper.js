function rot13(str) {
  let result = ""
  for(let c of str){
    let charCode = c.charCodeAt(0)
    if(charCode>=65 && charCode <=90){
      let deCharCode = charCode + 13
      if(deCharCode > 90){
        deCharCode = deCharCode - 90 + 64
      }
      result += String.fromCharCode(deCharCode)
    }
    else{
       result += c
    }
  }
  return result 
}

let r = rot13("SERR CVMMN!");
console.log(r)