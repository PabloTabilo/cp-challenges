#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<iterator>
#include<stack>
#include<set>
#include<unordered_map>
#include<map>
#include<math.h>
#include<limits>
#include<iomanip>
#include<sstream>
#include<tuple>
#include<chrono>

using namespace std;
using namespace chrono;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MEM(a, b) memset(a, (b), sizeof(a))
#define _USE_MATH_DEFINES
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second

typedef long int int32;
typedef unsigned long int uint32;
typedef long long ll;
typedef unsigned long long int ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next){}
};

class Solution{
    public:
        int sizeList(ListNode * head){
            int size = 0;
            ListNode * trav = head;
            while(trav!=nullptr){ 
                size++;
                trav = trav->next;
            }
            return size;
        }
        ListNode * removeNthFromEnd(ListNode * head, int n){
            ListNode * trav = head;
            ListNode * dropMe = head->next;
            int mySize = sizeList(head);
            int pos = mySize - n + 1;
            debug(mySize);
            debug(pos);
            if(dropMe == nullptr){
                return nullptr;
            }
            if(pos == 1){
                head=head->next;
                return head;
            }
            cout<<"can we traverse!"<<endl;
            int i = 1;
            while(i < pos-1){
                trav = trav->next;
                dropMe = dropMe->next;
                i++;
            }
            trav->next = dropMe->next;
            dropMe = nullptr;
           return head;
        }
};

void loopList(ListNode * p){
    while(p != nullptr){
        cout<<p->val<<" ";
        p = p->next;
    }
    cout<<endl;
}

void solve(){
    int n, s;
    cout<<"Give me size of the list: ";
    cin>>s;
    cout<<endl;
    ListNode myList = ListNode(1);
    ListNode * pointer = &myList;
    for(int i = 2; i <= s; i++){
        ListNode * myNode = new ListNode(i);
        pointer->next = myNode;
        pointer = pointer->next;
    }
    cout<<"Pre: "<<endl;
    loopList(&myList);
    cout<<"Dame la nth position from bottom of the list that you want eliminate: ";
    cin>>n;
    cout<<endl;
    Solution sol = Solution();
    ListNode * h = sol.removeNthFromEnd(&myList, n);
    cout<<"Post: "<<endl;
    loopList(h);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    fastio();
    auto start1 = high_resolution_clock::now();
    // read & write file
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cout<<"Number of repetitions: ";
    cin>>t;
    //t = 1;
    while(t--){
        solve();
    }
	auto stop1 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop1 - start1);
#ifdef ONLINE_JUDGE
	cerr << "Time: " << duration . count() / 1000 << endl;
#endif
    return 0;
}

