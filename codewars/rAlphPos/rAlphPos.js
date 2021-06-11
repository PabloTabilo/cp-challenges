a = 1
z = 25
function alphabetPosition(text) {
    text = text.toLowerCase().match(/\b\w+\b/g);
    if(text===null){return ""};
    text = text.join("");
    let res="";
    for(let i in text)
      res+=((text[i].charCodeAt(0)-96<0)?"":text[i].charCodeAt(0)-96<0+" ");
    return res.slice(0, -1);
}
let testMe = "The sunset sets at twelve o' clock."
console.log(alphabetPosition(testMe))