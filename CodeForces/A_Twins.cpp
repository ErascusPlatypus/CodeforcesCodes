#include <bits/stdc++.h>
using namespace std ;

int main() {
    int n ;
    cin >> n ;

    vector<int> nums(n) ;
    for(int i = 0 ; i < n ; i++) cin >> nums[i] ;

    sort(nums.begin() , nums.end() , greater<int>()) ;
    int sum = accumulate(nums.begin() , nums.end() , 0) ;
    int sum2 = 0 , i = 0  ; 

    for(i = 0 ; i < n ; i++) {
        sum2 += nums[i] ;
        sum -= nums[i] ;

        if(sum2 > sum) {
            break ;
        }
    }

    cout << i+1 << endl ;
}