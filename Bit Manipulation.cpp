#include <bits/stdc++.h>
using namespace std;

string toBinary(int n){
  string res = "";
  while(n!=0){
    if(n%2==1){
      res.push_back('1');
    }else{
      res.push_back('0');
    }
    n/=2;
  }
  reverse(res.begin(),res.end());
  return res;
 // Time complexity : log(N) 
 // Space complexity : log(N);
}
int toDecimal(string &s){
  int p1 = 1;
  int num = 0;
  int n = s.length();
  for(int i = s.length()-1 ; i>=0 ;--i){
    if(s[i]=='1'){
      num += p1;
    }
    p1*=2;
  }
  return num;
  // Time complexity is O(Length of the string)
  // Space complexity is O(1) as we are storing in the integer
}

void swapUsingXOR(int a,int b){
  cout<<"Before swapping  a: " << a << " b :"<<b<<endl;
  a = a^b;
  b = a^b;
  a = a^b;
  cout<<"After swapping  a: " << a << " b :"<<b<<endl;
}

void checkSetBitUsingLeftshift(int n, int i){
  if((n & (1<<i))!=0){
    cout<<"Bit is set"<<endl;
  }else{
    cout<<"Bit is not set"<<endl;
  }
}

void checkSetBitUsingRightshift(int n, int i){
  if(((n>>i)&1)!=0){
    cout<<"Bit is set"<<endl;
  }else{
    cout<<"Bit is not set"<<endl;
  }
}
void setTheBit(int n,int i){
  n = (n|(1<<i));
  cout<<n<<endl;
}
void clearIthBit(int n ,int i){
  n = (n &(~(1<<i)));
  cout<<n<<endl;
}

void toggleIthBit(int n,int i){
  n = (n^(1<<i));
  cout<<n<<endl;
}

void removeTheLastSetBit(int n){   // or rightmost set bit
  n = (n & (n-1));
  cout<<n<<endl;  
  // 84 in binary is 1 0 1 0 1 0 0 
  // 83 in binary is 1 0 1 0 0 1 1
  //                &-------------
  //                 1 0 1 0 0 0 0 -> 80 
}

void powerOfTwo(int n){
  if((n & (n-1)) == 0){
    cout<<"The number is power of 2"<<endl;
  }else{
    cout<<"The number is not the power of 2 "<<endl;
  }
}

int countNoOfSetBitsMethod1(int n){
  int count = 0;
  while(n>1){
    count += n&1;
    n/=2;
  }
  if(n==1){
    count++;
  }
  return count;
  // Time Complexity is O(log N base 2)
}

int countNoOfSetBitsMethod2(int n){  // best compared to previous method and is implemented based on removeTheLastSetBit
int count = 0;
  while(n){
    n = (n&(n-1));
    count++;
  }
  return count;
  // Time Complexity of worst case is O(31) or O(no of set bits)
}

// Minimum Bit flips to convert first number to the second number
int MinBitFlipsNeeded(int startingNumber , int requiredNumber){
  int ans = startingNumber^requiredNumber; // it will give the number with bitwise representation of the bits where starting number and ending number are not equal.
  return countNoOfSetBitsMethod1(ans);
}

// Generating Subsets Using Bit Manipulation
vector<vector<int>>Subsets(vector<int>&v){
  vector<vector<int>>ans;
  int subsets = (1<<v.size());
  for(int mask=0;mask<subsets;++mask){
    vector<int>subs;
    for(int i = 0;i<v.size();++i){
      if((mask&(1<<i))!=0){
        subs.push_back(v[i]);
      }
    }
    ans.push_back(subs);
  }
  return ans;
  // Time Complexity O(2^N * N)
  // Space Complexity O(2^N * N)
}

// https://leetcode.com/problems/single-number/description/
// All the numbers are present twice in the array except for one number output the number
int singleNumber(vector<int>&v){
  int XOR = 0;
  for(auto i : v){
    XOR^=i;
  }
  return XOR;
  // Time complexity is O(N);
  // Space Complexity is O(1);
}

// https://leetcode.com/problems/single-number-ii/submissions/
// it has 4 methods
// Method 1 : using unordered map
int singleNumberMethodOne(vector<int>& nums) {
    unordered_map<int,int>mp;
    int ans = -1;
    for(auto i : nums){
        mp[i]++;
    }
    for(auto it : mp){
        if(it.second == 1){
            ans = it.first;
        }
    }
    return ans;
  // Time Complexity is O(N) + O(M) where M = no of distinct elements in the map
  // Space Complexity is O(N)  
}
// Method 2 :
int singleNumberMethodTwo(vector<int>& nums) {
  int ans = 0;
  for (int i = 0; i < 32; ++i) {
    int sum = 0;
    for (const int num : nums)
      sum += num >> i & 1;
      sum %= 3;
      ans |= sum << i;
  }
  return ans;
  // Time Complexity is O(N * 32)
  // space Complexity is O(1)
}
// Method 3 : 
int singleNumberMethodThree(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i += 3) {
            if (nums[i] != nums[i - 1]) {
                return nums[i - 1];
            }
        }
        return nums[nums.size() - 1];
  // Time complexity is O(N*log(N)) for sorting and N/3 for the loop 
  // overall Time complexity is O(N*log(N) + N/3)
  // Space Complexity is O(1)
}
// Method 4 : Most Optimized solution (Not possible to think on own)
int singleNumberMethodFour(vector<int>& nums) {
        int ones = 0, twos = 0;
        for (int i = 0; i < nums.size(); ++i) {
            ones = (ones ^ nums[i] & (~twos));
            twos = (twos ^ nums[i] & (~ones));
        }
        return ones;
  // Time Complexity is O(N)
  // Space Complexity is O(1)
}

// https://leetcode.com/problems/single-number-iii/description/
// Method 1 : Using Unordered map 
vector<int> singleNumber3MethodOne(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(auto it : nums){
            mp[it]++;
        }
        for(auto it : mp){
            if(it.second == 1){
                ans.push_back(it.first);
            }
        }
        return ans;
  // Time Complexity is O(N + M) where M = no of distinct elements in map
  // space Complexity is O(M)      
}
// Method 2 : 
vector<int> singleNumber3MethodTwo(vector<int>& nums) {
        int n = nums.size();                        
        long long int XoRR = 0;
        for(int i=0;i<n;++i){
            XoRR = XoRR^nums[i];
        }
        long long int rightMost = (XoRR & (XoRR-1))^XoRR;
        int b1=0,b2=0;
        for(int i=0;i<n;++i){
            if(nums[i] & rightMost){
                b1^=nums[i];
            }else{
                b2^=nums[i];
            }
        }
        return {b1,b2};
  // Time Complexity is O(2N)
  // Space Complexity is O(1)      
}

// XOR of numbers in the range of 1 to N 
// Method 1 : Brute Force
int findXOR(int n){
  int ans = 0;
  for(int i=1;i<=n;++i){
    ans^=i;
  }
  return ans;
  // Time Complexity is O(N)
  // Space Complexity is O(1)
}
// Method 2 : Optimized approach
int findXORMethodTwo(int n){
  if(n % 4 == 1){
    return 1;
  }
  else if(n%4 == 2){
    return n+1;
  }
  else if(n%4 == 3){
    return 0;
  }else{
    return n;
  }
  // Time Complexity is O(1)
  // Space Complexity is O(1)
}

// XOR of numbers in the range L to R
// Method 1 : Brute Force 
int findXorFromLtoR(int l,int r){
  int ans = 0;
  for(int i=l;i<=r;++i){
    ans^=i;
  }
  return ans;
  // Time Complexity is O(R-L+1)
  //Space Complexity is O(1);
}
// Method 2 : Optimized Approach
int findXorFromLtoRMethodTwo(int l,int r){
  return findXORMethodTwo(l-1) ^ findXORMethodTwo(r);
  // Time Complexity is O(1)
  // Space Complexity is O(1)
}

// Divide two integers without using multiplication , division and mod operator
// https://leetcode.com/problems/divide-two-integers/description/
int divide(int dividend,int divisor){
  if(dividend == divisor){
    return 1;
  }
  bool sign = true;
  if(dividend >=0 && divisor < 0){
    sign = false;
  }
  else if(dividend <=0 && divisor>0){
    sign = false;
  }
  long n = abs(dividend);
  long d = abs(divisor);
  divisor = abs(divisor);
  long quotient = 0;
  while(n >= d){
    int count = 0;
    while(n>= (d << (count+1))){
      count++;
    }
    quotient += 1<<count;
    n-= (d<<count);
  }
  if(quotient == (1<<31) && sign){
    return INT_MAX;
  }
  if(quotient == (1<<31) && !sign){
    return INT_MIN;
  }
  return sign ? quotient : -quotient;
}

// check Power of FOUR
// https://leetcode.com/problems/power-of-four/description/
bool isPowerOfFour(int n) {
        // First, check if n is positive
        if (n <= 0) {
            return false;
        }

        // Check if n is a power of two
        if ((n & (n - 1)) != 0) {
            return false;
        }

        // Check if the only set bit is in the correct position for a power of four
        // The bitmask for positions 0, 2, 4, 6, ... is 0x55555555
        return (n & 0x55555555) != 0;
}

int main() {
  // int n = 15 ;
  // string s = toBinary(8);
  // string s1 = toBinary(10);
  // cout<<s1<<endl;
  // cout<<s<<endl;
  // string s = "10001";
  // int number = toDecimal(s);
  // swapUsingXOR(5,10);
  // int ans = MinBitFlipsNeeded(10,8);
  // cout<<ans<<endl;
  // vector<int>v = {1,2,3,4};
  // vector<vector<int>>ans = Subsets(v);
  // for(int i=0;i<ans.size();++i){
  //   for(int j=0;j<ans[i].size();++j){
  //     cout<<ans[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }
  vector<int>v = {1,1,2,2,3,4,3,4,5};
  int ans = singleNumber(v);
  cout<<ans<<endl;
}