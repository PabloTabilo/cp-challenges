function solution(input, markers) {
  let arr = input.split("\n");
  let res="";
  for(let i=0;i<arr.length;i++){
        let temp=""
        for(let j=0;j<arr[i].length;j++){
            v = arr[i][j];
            if(markers.find(e=>e==v))
                break;
            else
                temp+=v;
        }
        if(temp[temp.length-1]==" ")
            temp = temp.slice(0,temp.length-1);
        if(i<arr.length-1)
            temp+="\n";
      res+=temp;
  }
  console.log(res);
};

var result = solution("apples, pears # and bananas\ngrapes\nbananas !apples", ["#", "!"])
// result should == "apples, pears\ngrapes\nbananas"