function checkCashRegister(price, cash, cid) {
  let change = cash - price;
  let totalOfMoney = cid.reduce((total, value)=>{
    return total + value[1]
  },0)
  let status = ""
  if(change > totalOfMoney){
    status = "INSUFFICIENT_FUNDS"
  }
  console.log(`Cash: ${cash},Price : ${price}, Change: ${change}, Total: ${totalOfMoney}`);
  let currencyUnits = {
    "PENNY": 0.01,
    "NICKEL": 0.05,
    "DIME": 0.1,
    "QUARTER": 0.25,
    "ONE": 1,
    "FIVE": 5,
    "TEN": 10,
    "TWENTY":20,
    "ONE HUNDRED": 100
  }
  let currencyUnitAmounts = cid.map(value=>{
    let amount = value[1]
    value[1] = currencyUnits[value[0]]
    value.push(Math.round(amount/value[1]))
    value.push(0)
    return value
  })
  currencyUnitAmounts = currencyUnitAmounts.sort((a,b)=>{
    return b[1] - a[1]
  })
  console.log(currencyUnitAmounts)
  let result = []
  for(let i = 0; i < currencyUnitAmounts.length; i++){
    while(change >= currencyUnitAmounts[i][1] && currencyUnitAmounts[i][2] > 0){
      change = change- currencyUnitAmounts[i][1];
      change = Math.round(change *100) /100
      currencyUnitAmounts[i][2]--;
      currencyUnitAmounts[i][3]++;
      if(!checkDuplicate(currencyUnitAmounts[i], result)){
        result.push(currencyUnitAmounts[i])
      }
    }
  }
  result = result.map(value=>{
    return [value[0],value[1]*value[3]]
  })
  if(status != "INSUFFICIENT_FUNDS"){
    if(currencyUnitAmounts.some(value=>{
      return value[2]>0
    }))
      status = "OPEN"
    else
      status = "CLOSED"
  }
  if(change > 0){
    status = "INSUFFICIENT_FUNDS"
  }
  let finalResult = {"status": status}
  if(status == "INSUFFICIENT_FUNDS"){
    finalResult["change"] = []
  }
  if(status == "OPEN")
    finalResult["change"] = result
  if(status == "CLOSED"){
    console.log(currencyUnitAmounts)
    finalResult["change"] = currencyUnitAmounts
    .sort((a,b)=>{
      return a[1] - b[1]
    })
    .map(value=>{
      return [value[0],value[1]*value[3]]
    })
    
  }
  return finalResult
}
function checkDuplicate(value, arr){
  for(let element of arr){
    if(value[0] == element[0])
      return true
  }
  return false
}
let r = checkCashRegister(19.5, 20, [["PENNY", 1.01], ["NICKEL", 2.05], ["DIME", 3.1], ["QUARTER", 4.25], ["ONE", 90], ["FIVE", 55], ["TEN", 20], ["TWENTY", 60], ["ONE HUNDRED", 100]]) 
console.log(r)
console.log(`should return {status: "OPEN", change: [["QUARTER", 0.5]]}.`);
console.log("===========================================")
let r1 = checkCashRegister(3.26, 100, [["PENNY", 1.01], ["NICKEL", 2.05], ["DIME", 3.1], ["QUARTER", 4.25], ["ONE", 90], ["FIVE", 55], ["TEN", 20], ["TWENTY", 60], ["ONE HUNDRED", 100]]) 
console.log(r1)
console.log(`should return {status: "OPEN", change: [["TWENTY", 60], ["TEN", 20], ["FIVE", 15], ["ONE", 1], ["QUARTER", 0.5], ["DIME", 0.2], ["PENNY", 0.04]]}.`);
console.log("===========================================")
let r2= checkCashRegister(19.5, 20, [["PENNY", 0.01], ["NICKEL", 0], ["DIME", 0], ["QUARTER", 0], ["ONE", 0], ["FIVE", 0], ["TEN", 0], ["TWENTY", 0], ["ONE HUNDRED", 0]]) 
console.log(r2)
console.log(`should return {status: "INSUFFICIENT_FUNDS", change: []}.`);
console.log("===========================================")
let r3 = checkCashRegister(19.5, 20, [["PENNY", 0.01], ["NICKEL", 0], ["DIME", 0], ["QUARTER", 0], ["ONE", 1], ["FIVE", 0], ["TEN", 0], ["TWENTY", 0], ["ONE HUNDRED", 0]]) 
console.log(r3)
console.log(`should return {status: "INSUFFICIENT_FUNDS", change: []}.`);
console.log("===========================================")
let r4 = checkCashRegister(19.5, 20, [["PENNY", 0.5], ["NICKEL", 0], ["DIME", 0], ["QUARTER", 0], ["ONE", 0], ["FIVE", 0], ["TEN", 0], ["TWENTY", 0], ["ONE HUNDRED", 0]])
console.log(r4)
console.log(`should return {status: "CLOSED", change: [["PENNY", 0.5], ["NICKEL", 0], ["DIME", 0], ["QUARTER", 0], ["ONE", 0], ["FIVE", 0], ["TEN", 0], ["TWENTY", 0], ["ONE HUNDRED", 0]]}.`);
console.log("===========================================")
