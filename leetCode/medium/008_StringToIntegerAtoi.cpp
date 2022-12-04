class Solution {
public:
    bool checkIsNum(char c){
      return c-'0'>= 0 && c-'0'<=9;
    }
    bool checkIsLetter(char c){
      return c >= 65 && c <= 122;
    }
    int myAtoi(string s) {
        const int bigNum = 1e9;
        int maxDigit = 10;
        int n = s.size();
        string number = "";
        long long int myNum = 0;
        int res = 0; 
        long long int j = 1;
        bool isNeg = false;
        bool isPos = false;
        bool hasPoint = false;
        bool firstTime = true;
        bool isNum = false;
        bool impos = false;
        int hasPointNum = n-1;
        int numOfDigits = 0;
        for(int i = 0; i<n;i++){
          if(checkIsLetter(s[i])) break;
          if(!checkIsNum(s[i]) && isNum) break;
          if(s[i] == '.') break;
          if(s[i] == '-'){
            isNum = true;
            isNeg = true;
            if(i-1 >= 0){
              if(checkIsNum(s[i-1])||checkIsLetter(s[i-1])){
                impos = true;
              }
            }
         }
          if(s[i] == '+'){
            isPos = true;
            isNum = true;
            if(i-1 >= 0){
              if(checkIsNum(s[i-1])||checkIsLetter(s[i-1])){
                impos = true;
              }
            }
          }
          if(checkIsNum(s[i])){
            if(firstTime && s[i] != '0'){
              number += s[i];
              numOfDigits++;
              firstTime = false;
            }
            else if(!firstTime){
              number+=s[i];
              numOfDigits++;
            }
            isNum = true;
          }
        }
        if(impos||(isPos & isNeg)||(number.size() < 1)||( s[0] != ' ' && s[0]!='+' && s[0] != '-' && !checkIsNum(s[0]))){
            return 0;
        }
        cout<<"number: "<<number<<endl;
        bool overflow = false;
        if(numOfDigits > maxDigit) overflow = true;

        int n_number = number.size();
        for(int i = n_number-1; i>=0 && !overflow;i--){
            if(checkIsNum(number[i])){
                if(!isNeg && (((number[i]-'0')*j > INT_MAX-myNum)||(number[i]-'0'>2 && j >= bigNum))){
                    overflow = true;
                    break;
                }
            else if(isNeg && ((((number[i]-'0')*j)*-1 < INT_MIN+myNum)||(number[i]-'0'>2 && j >= bigNum))){
                    overflow = true;
                    break;  
                }
                myNum+=(number[i]-'0')*j;
                j*=10;
            }
        }

        if(overflow){
            if(isNeg) return INT_MIN;
            return INT_MAX;
        }else{
            if(isNeg){
              myNum*=-1;
              res = myNum;
              return res;
            } 
            res = myNum;
            return res;
        }
    }
}; 
