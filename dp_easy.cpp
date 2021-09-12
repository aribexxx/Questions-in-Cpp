#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include "array.h"
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

//DP find longestPalindron

    string longestPalindrome(string s){
        int n=s.size();
        if(n<2){
            return s;
        }
        int maxLen=1;//two variable maxLen,begin to keep track of result
        int begin=0;
        vector< vector<int> > dp( n , vector<int> (n));
        for(int i=0;i<n;i++){
            dp[i][i]=true; //initialize all substring with len 1 are palindrom.
        }

        //start to 穷举 P（i,j）之间的substring
        //induction step
        for(int L=2;L<=n;L++){//子串长度的穷举，长度为2以上
            for (int i=0;i<n;i++){
                int j=L+i-1;
                if(j>=n){//右边超界限
                    break;
                }
                if(s[i]!=s[j]){
                    dp[i][j]=false;
                }
                else{
                    if(j-i<3){
                    dp[i][j]=true;
                    }
                    else{
                        dp[i][j]=dp[i+1][j-1];}
                }
                     //输出当前最长子串的结果s[i][j] 
            if(dp[i][j]&&j-i+1>maxLen){
                maxLen=j-i+1;
                begin =i;
            }
            }
        }
     return s.substr(begin,maxLen);
    }
   
    pair<int,int> expandAroundCenter(const string &s,int left,int right){
        while(left>=0&&right<s.size()&&s[left]==s[right]){
            --left;
            ++right;
        }
        return std::make_pair(left + 1, right - 1);
    } 
    string longestPalindromExpand(string s){
        int start=0,end=0;//to keep track of maxlen substring 's start and end.
        for(int i=0;i<s.size();i++){
            //this follows c++17 syntax
           auto [left1, right1]=expandAroundCenter(s,i,i);
           auto [left2, right2]=expandAroundCenter(s,i,i+1);
           if(right1-left1>end-start){
               start=left1;
               end=right2;
           }
           if(right2-left2>end-start){
               start=left2;
               end=right2;
           }

        }
        return s.substr(start,end-start);
    }   
    
};
int main(){
Solution sol1;
int result = sol1.climbStairs(2);

Solution sol2;
vector<int> out=sol2.countBits(5);
out=sol2.countBitsDPHigh(5);
int nCount[5] = {0, 1, 2, 3, 4};
int arr[] = {'d'};
//printArray(arr);
//When a symbol has internal linkage, it will only be visible within the current translation unit. Do not confuse the term visible here with access rights like private. Visibility here means that the linker will only be able to use this symbol when processing the translation unit in which the symbol was declared, and not later (as with symbols with external linkage). In practice, this means that when you declare a symbol to have internal linkage in a header file, 
//each translation unit you include this file in will get its own unique copy of that symbol.
Solution sol3;
//so printArray(arr); in array.cpp will not be visible in dp_easy.cpp
string in="babad";
string in2="aba";
//std::cout << sol3.longestPalindrome(in) << std::endl;
std::cout << "ooout"<<sol3.longestPalindromExpand(in2) << std::endl;

//this hello() is visible becuz its implementation is declared in the imported header file
hello();
Solution sol4;
printf("\nfib(4) is %d",sol4.fib(4));
}
