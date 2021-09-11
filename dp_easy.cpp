#include <iostream>
#include <vector>
#include <math.h>
#include <array.h>
//cpp progm does not use .h
using namespace std;

class Solution{
public:

int climbStairs(int n){
    if(n<1) return n;
    vector<int>dp;
    dp.push_back(n);
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++){
        dp[i]=dp[1]+dp[2];
    }
    return dp[n];
}

public:
//#Method 1 brute force :
// O(n log n)
vector<int> countBits(int n) {
    vector<int> res;
    //need n+1 to store all bits
    res.push_back(n+1);
    for(int i=0;i<n+1;i++){
    res[i]=countOnes(i);
    printf("%d\n",res[i]);
    }
    return res;
    }
// helper countBits()
    int countOnes(int x) {
        int ones = 0;
        while (x > 0) {
            //bit operation
            x &= (x - 1);
            ones++;
        }
        return ones;
    }

    // #Method2 DP stores previous result
vector<int> countBitsDPHigh(int n) {
    vector<int> res(n+1);
    int highBit=0;//当前最高有效1的位置
                    //联想到奇数，偶数=奇数+1
            for (int i = 1; i <= n; i++) {
            if ((i & (i - 1)) == 0) {
                highBit = i;
                printf("%D",highBit);
            }
            res[i] = res[i - highBit] + 1;
        }
    return res;
}
    int fib(int n) {
        if(n<=1){return n;}
        int a=0;
        int b=0;
        int c=1;
        for(int i=2;i<=n;i++){
            a=b;
            b=c;
            c=a+b;
        }
        return c;
    }

    

};
int main(){
Solution sol1;
int result = sol1.climbStairs(2);

Solution sol2;
vector<int> out=sol2.countBits(5);
out=sol2.countBitsDPHigh(5);
int arr[]={1,2,3};
printf("aaaaaaa");
printArray(arr);

Solution sol3;
printf("\nfib(4) is %d",sol3.fib(4));
}
