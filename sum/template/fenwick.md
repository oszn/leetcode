# 树状数组

*此方法只供个人记录*

1. 单点修改，区间查询
2. 区间修改，单点修改
3. 区间修改，区间查询

from  [link](https://oi-wiki.org/ds/fenwick/)

树状数组给我的感觉像一个层级管理，也就是树管理，完全二叉树。也对完全二叉树确实可以换成数组来处理。

单点管理可以理解为只管理自己一个人，然后别的可能管理很多的数字。



管理过程关键函数

```c++
//lowbit
int lowbit(int x) {
  // x 的二进制表示中，最低位的 1 的位置。
  // lowbit(0b10110000) == 0b00010000
  //          ~~~^~~~~
  // lowbit(0b11100100) == 0b00000100
  //          ~~~~~^~~
  return x & -x;
}
```

可以知道自己需要管理多少个元素。该结构的设计也是为了区间处理，但功能确实不如线段树强大。区间查询功能相当于，做2次前缀和。理论上可以单点查询，例如查询a[3]就是先查询c[3]发现管理4个数字，然后减去前3个管理的数字，就是单点查询了。

单点修改是一个往上的过程,对于lowbit来说相当于在找他第一个补码，加上idx的lowbit相当于找到下一个高级管理区间，而减去idx的lowbit相当于，找前面存在的一个区间。

```c++
void add(vector<int>&arr,int idx,int k){
    while(idx<arr.size()){
        arr[idx]+=k;
        idx=idx+lowbit(idx);
    }
}
```

而对于单点查询来说,相当于在做2个前缀和相减。

```c++
void query(vector<int>&arr,int idx){
    int ans=0;
    while(idx){a
    	ans+=arr[idx];
        idx=idx-lowbit(idx);
    }
    return ans;
}
```

