# leetcode
<font color="red">所有的代码在leetcode文件夹里面，如leetcode 33题，则是namespace lt33命名</font>

## 1631. 最小体力消耗路径
[link](https://leetcode-cn.com/problems/path-with-minimum-effort/)

感觉这个题目我一看到第一反应应该是dp，后来建立不出来dp，就想搜索，搜索一想代价就很大，会走一些没用的路肯定不好过。

**a*算法**

a*的核心思想在于启发式函数h(x)+g(x)的过程。总是朝着当前最优的地方寻址。这个题目就是h(x)=0的情况，所以就是一个最小路径求解算法。

**并查集**
这个题目感觉好难啊，没想到，看了题解之后才能做，其实你看了之后发现这个题目核心2点。

1. 对所有的边进行排序
2. 将边一个一个放进去，找到连通性，我tm直接裂开。

今天学习他代码发现一个好东西，就是多一个size，那样的话，不需要递归回去修改，只需要把一个人的root进行修改即可。

778. 水位上升的泳池中游泳
[link](https://leetcode-cn.com/problems/swim-in-rising-water/)

这个题目和昨天的题目类似，昨天是求差值，而今天得题目就是max就行了。

**并查集**

2个点，之间必须满足最大值才能进行游动，所以保证一个方向下，求最大值才能保持可行，不需要想象他下雨的过程，只需要保证下雨的结果，也就是到达能通行的结果储存进数值进行排序储存，里面必须有2个点以及value。然后通过不断地放value就能得到这个结果。

![](img/1.png)

这个的放的过程就是
1 2 3 4 7 8 9 10 11 12 13 14 15 16.

然后就是检查连通性。

## 839. 相似字符串组
[link](https://leetcode-cn.com/problems/similar-string-groups/)

我开始题目意思理解错了，所以认为直接排序即可。

**并查集**
整体的逻辑就是，如果2个是相似的就union。

而相似的逻辑就是长度首先相同，然后字符只有2个不同或者0个不同。




