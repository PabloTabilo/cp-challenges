#include<iostream>
#include<vector>

using namespace std;

double giveMeMedian(vector<int>v, int l, int r){
    int n = r - l + 1;
    int pm = (l+r)/2;
    double res = v[pm];
    if(n%2==0 && n>=2)
        res = 1.0*(v[pm]+v[pm+1])/2.0;
    return res;
}

class Solution{
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
            int n1 = nums1.size();
            int l1 = 0, r1 = n1-1;
            int n2 = nums2.size();
            int l2 = 0, r2 = n2-1;

            if(n1 == 0 && n2 == 0) return 0.0;
            if(n1 == 0) return giveMeMedian(nums2, l2, r2);
            if(n2 == 0) return giveMeMedian(nums1, l1, r1);

            double m1 = giveMeMedian(nums1, l1, r1);
            double m2 = giveMeMedian(nums2, l2, r2);
            while(m1 != m2){
                if(l1 < r1) l1++;
                if(r2 > l2) r2--;
                m1 = giveMeMedian(nums1, l1, r1);
                m2 = giveMeMedian(nums2, l2, r2);
                if(l1 == r1 && r2 == l2)
                    break;
            }
            cout<<"m1: "<<m1<<"; m2: "<<m2<<endl;
            if(m1 == m2)
                return m1;
            else{
                if(n1 == n2)
                    return (m1+m2)/2;
                else if(n1 > n2)
                    return m1;
                else
                    return m2;
            }
        }
};


int main(){
    Solution sol;
    /*
    vector<int> v1 = {1,1,1,2,2,4};
    vector<int> v2 = {1, 1, 8};
    cout<<"sol: "<<sol.findMedianSortedArrays(v1, v2)<<endl;
    vector<int> v11 = {1,2,3,4};
    vector<int> v12 = {6,7,8,9,22};
    cout<<"sol: "<<sol.findMedianSortedArrays(v11, v12)<<endl;
    vector<int> v13 = {1,3};
    vector<int> v14 = {2};
    cout<<"sol: "<<sol.findMedianSortedArrays(v13, v14)<<endl;
    vector<int> v15 = {1,2};
    vector<int> v16 = {3,4};
    cout<<"sol: "<<sol.findMedianSortedArrays(v15, v16)<<endl;
    vector<int> v17 = {0,0};
    vector<int> v18 = {0,0};
    cout<<"sol: "<<sol.findMedianSortedArrays(v17, v18)<<endl;
    vector<int> v19 = {};
    vector<int> v20 = {};
    cout<<"sol: "<<sol.findMedianSortedArrays(v19, v20)<<endl;
    vector<int> v21 = {2};
    vector<int> v22 = {};
    cout<<"sol: "<<sol.findMedianSortedArrays(v21, v22)<<endl;
    vector<int> v23 = {2, 7, 7, 8, 9, 10, 12, 14, 15, 18, 18, 19, 19, 22, 24, 24, 33, 33, 35, 35, 38, 42, 42, 43, 43, 45, 49, 61, 63, 66, 69, 70, 71, 72, 73, 74, 78, 80, 80, 85, 85, 86, 89, 90, 92, 93, 94, 95, 96, 98};
    vector<int> v24 = {2, 4, 7, 7, 8, 9, 11, 12, 12, 14, 14, 15, 15, 16, 19, 24, 29, 29, 31, 33, 38, 38, 38, 42, 42, 43, 45, 48, 49, 53, 54, 58, 61, 62, 62, 67, 69, 72, 73, 74, 74, 79, 85, 86, 88, 89, 94, 95, 96, 100};
    cout<<"sol: "<<sol.findMedianSortedArrays(v23, v24)<<endl;
    */
    vector<int> v25 = {};
    vector<int> v26 = {2,3};
    cout<<"sol: "<<sol.findMedianSortedArrays(v25, v26)<<endl;
    return 0;
}