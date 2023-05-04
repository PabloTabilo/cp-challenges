#include<iostream>

using namespace std;

bool debug = true;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


void trav(ListNode * L){
    ListNode * i = L;
    while(i != NULL){
        cout<<i->val<<endl;
        i = i->next;
    }
}

string giveMeNum(ListNode * L){
    string res = "";
    ListNode * i = L;
    while(i != NULL){
        res.insert(0,to_string(i->val));
        i = i->next;
    }
    return res;
}

string sumStrings(string &s1, string &s2){
    int n1 = s1.size();
    int n2 = s2.size();
    int n = n1;
    string res = "";
    int s1_i, s2_i, m_i, r = 0;
    if(n1 > n2){
        n = n1;
        for(int i=0;i<n-n2;i++)
            s2.insert(0,"0");
    }else if(n2 > n1){
        n=n2;
        for(int i=0;i<n-n1;i++)
            s1.insert(0,"0");
    }
    if(debug) cout<<"new s1: "<<s1<<"; new s2: "<<s2<<endl;
    for(int i = n-1; i>=0;i--){
        s1_i = s1[i] - '0'; 
        s2_i = s2[i] - '0';
        m_i = s1_i + s2_i + r;
        if(m_i < 10)
            r = 0;
        else
            r = 1;
        if(debug) cout<<"s1_i: "<<s1_i<<"; s2_i: "<<s2_i<<"; m_i: "<<m_i<<"; r: "<<r<<endl;
        res.insert(0, to_string(m_i%10));
    }
    if(r==1)
        res.insert(0, "1");
    return res;
}

ListNode * createMe(string s){
    ListNode * last = NULL;
    ListNode * firstTime = NULL;
    int n = s.size();
    if(s == "0")
        return new ListNode(0);
    int i = n-1;
    while(i >= 0){
        ListNode * nt = new ListNode(s[i]-'0');
        if(last != NULL){
            //cout<<"Not FirstTime: "<<nt->val<<endl;
            //cout<<"lastVal: "<<last->val<<endl;
            //cout<<"firstTime: "<<firstTime->val<<endl;
            last->next = nt;
            last = nt;
        }else{
            last = nt;
            firstTime = nt;
            //cout<<"firstTime: "<<firstTime->val<<endl;
        }
        i--;
    }
    //cout<<"-----------"<<endl;
    return firstTime;
}


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string s1 = giveMeNum(l1);
        string s2 = giveMeNum(l2);
        if(debug) cout<<"s1: "<<s1<<"; s2: "<<s2<<endl;
        string s3 = sumStrings(s1, s2);
        if(debug) cout<<"s3: "<<s3<<endl;
        ListNode * finalList = createMe(s3);
        if(debug) trav(finalList);
        return finalList;        
    }
};
 /*
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
*/

int main(){
    ListNode * l1 = createMe("9999999");
    ListNode * l2 = createMe("9999");
    Solution sol;
    ListNode * final = sol.addTwoNumbers(l1, l2);
    return 0;
}
