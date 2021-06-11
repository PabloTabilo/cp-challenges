function zero(v) {
    if (v === undefined || v==null) return 0;
    else return operation(v,0);
}
function one(v) {
    if (v === undefined || v==null) return 1;
    else return operation(v,1);
}
function two(v) {
    if (v === undefined || v==null) return 2;
    else return operation(v,2);
}
function three(v) {
    if (v === undefined || v==null) return 3;
    else return operation(v,3);
}
function four(v) {
    if (v === undefined || v==null) return 4;
    else return operation(v,4);
}
function five(v) {
    if (v === undefined || v==null) return 5;
    else return operation(v,5);
}
function six(v) {
    if (v === undefined || v==null) return 6;
    else return operation(v,6);
}
function seven(v) {
    if (v === undefined || v==null) return 7;
    else return operation(v,7);
}
function eight(v) {
    if (v === undefined || v==null) return 8;
    else return operation(v,8);
}
function nine(v) {
    if (v === undefined || v==null) return 9;
    else return operation(v,9);
}

function operation(v, n1){
    let res=0;
    switch(v.name){
        case "plus":
            res = n1+v.v;
            break;
        case "minus":
            res = n1-v.v;
            break;
        case "times":
            res = n1*v.v;
            break;
        case "dividedBy":
            res =Math.floor(n1/v.v);
            break;
    }
    return res;
}

function plus(v) {return{name:"plus", v};}
function minus(v) {return{name:"minus", v};}
function times(v) {return{name:"times", v};}
function dividedBy(v) {return{name:"dividedBy", v};}

console.log(seven(times(five())));
console.log(four(plus(nine())));
console.log(eight(minus(three())));
console.log(six(dividedBy(two())));
console.log(eight(dividedBy(three())));

/*
Test.assertEquals(seven(times(five())), 35);
Test.assertEquals(four(plus(nine())), 13);
Test.assertEquals(eight(minus(three())), 5);
Test.assertEquals(six(dividedBy(two())), 3);
*/