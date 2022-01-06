/*
  Pig Latin is a way of altering English Words. The rules are as follows:

- If a word begins with a consonant, take the first consonant or consonant cluster, move it to the end of the word, and add ay to it.

- If a word begins with a vowel, just add way at the end.
*/
function translatePigLatin(str) {
  if(str.match(/^[^ueoai]+/)!=null)
  {
     let cluster = str.match(/^[^ueoai]+/)[0]
     str = str.replace(cluster,"")
     str = str+ cluster + "ay"
  }
  else{
    str = str+"way"
  }
  return str
}

let r = translatePigLatin("algorithm");
console.log(r)