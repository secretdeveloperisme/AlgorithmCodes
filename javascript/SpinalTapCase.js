function spinalCase(str) {
  let words = splitWords(str)
  console.log(words)
  str = words.join("-").toLowerCase()
  return str;
}
function splitWords(str){
  let newStringArr= [] 
  for(let i= 0 ; i < str.length - 1; i++ ){
    // console.log(getCaseOfCharacter(str[i]), getCaseOfCharacter(str[i+1]))
    newStringArr.push(str[i])
    if(getCaseOfCharacter(str[i]) == "LowerCase"
    && getCaseOfCharacter(str[i+1]) == "UpperCase")
     newStringArr.push(" ")
    
  }
  newStringArr.push(str[str.length - 1])
  str = newStringArr.join("")
  return str.split(/[\s\._]/);
}
function getCaseOfCharacter(c){
  if( c.charCodeAt(0) >= 65 &&c.charCodeAt(0) <= 90)
    return "UpperCase"
  else if(c.charCodeAt(0) >= 97 && c.charCodeAt(0) <= 122)
    return "LowerCase"
  else 
    return "symbols"
}
let r = spinalCase('AllThe-small Things');
console.log(r)

function spinalCaseWithRegex(str){
  return str.split(/\s|_|(?=[A-Z])/).join("-").toLowerCase();
}
let result = spinalCaseWithRegex("AllThe-small Things")
console.log(result);