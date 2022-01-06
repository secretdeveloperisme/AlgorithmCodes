function convertToRoman(num) {
  let numbers = [1000,900,500,400,100,90,50,40,10,9,5,4,1]
  let numberRomans = ["M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"]
  let result = ""
  for(let i = 0; i < numbers.length ; i++){
    while(num>=numbers[i]){
      num -= numbers[i]
      result += numberRomans[i]
    }
  }
 return result;
}

let result = convertToRoman(36);
console.log(result)
