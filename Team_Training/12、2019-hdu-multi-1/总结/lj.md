这场我们很快发现几何题，而且肯定可以稳过的经典题，但是太靠后写了，有点吃亏。

有道简单的数学题，本来是一眼题，但是我没搞清楚题意，我觉得没讲清楚，就放一边了，在等着发clarification，但是没等到；之后先想了别的题目，等这个题目有不少人过了，我回头看了看，也理解了，感觉是题意描述数学公式使用混乱，表达不明。然后我们很快就推导了，在排队等机时。不久滨滨上去先敲了这题。

有道字符串题，在开场没多久我们就开始搞了，这个题目前半段分析是贪心，然后滨滨很快就和我们交流了贪心的思路，得到字符串应该支持的操作，但是交流过程遇到问题，导致没搞清楚到底要干什么(在这过程中，他们可能讨论了个什么hash做法，好像上去敲了)。在我得到的题意里，我先想了一个扩展kmp，然后还以为就结束了；然后和yy交流，发现末端点要移动，扩展kmp就做不了了，但是我感觉是后缀数组做，因为后缀数组是专门搞这种散点维护，动态查询问题的，有大量的支持应用，就是数据结构维护比较复杂一些；然后我和yy交流了一下，我不知道她听没听懂，总之她又想了个后缀自动机的做法，然后就跟我讲了，确实是对的，也比较好写，只要在自动机上沿着后缀运行该字符串就好了，然后她就上去写了。搞了一会，好像发现题意又搞错了，所以白搞了。这个题目三个人都有参与，投入了很多时间，结果全部都付之东流了。最后发现好像贪心也有点问题，具体不清楚怎么回事。

后面有道中档数学题，虽然对我们来说也很基础，但是不幸的是：我在推导一个核心细节的时候，统计多少个数，三次根号下取整等于$k$，且这个数要是某个$d$的倍数，我就直接给出了个数的公式，沿着$k$的范围，结果忘记了当$k$取最大值的时候，这个上界要和$n$取min，然后再计数。导致了样例不对，滨滨下机。然后我们耗费了好久去check推导过程，最后也没发现大问题(发现个下标忘记-1)，然后还是无意之中发现忘记取min的。改过来，就过样例了。我以为就可以过了，结果T了，然后我们顶着大复杂度的压力去搞常数优化去了。主要这题本来推导好了之后，因为在敲别的题，所以在排队，开始并不知道这个公式有点问题。敲了之后才发现，因为样例比较大，也不大好手算去check，要是一不小心手算搞错了，就还是要检查推导过程，浪费时间。然后我们就开始卡常数，搞很久过不掉。最后逼不得已，还是回去优化复杂度，优化到了线性，这回总能过了吧，结果又T了，然后我们又常数优化了。我发现了个整除的性质，可以不用int128这种东西了，快了不少。这题搞太久了。

后面还有两道数学题，一道是连分数+莫比乌斯反演的，根本没去想，可能是可以去做的；还有一道是生成函数难题，太难了，应该是水平不够的。

有两道dp，有一道题意都没搞清楚，还有一道，我有去想，大概想了二十几分钟，没想法，状态表示技巧性比较强，没有想到，滨滨有想了个十分钟；最后我们这题没突破。

但是本场的最大问题，还是在那个线性基上，直接导致我们题数少了一题，因为这是个前不久我们遇到过的，但是没去补人家标准的做法，属于不会这种套路，但是我们弄了个大复杂度的线段树，开始常数优化，加玄学优化，怎么也搞不过去，搞太久了。这说明，该学的东西还是要去学，不能偷懒，你现在不去搞，等下考场里面考到了，搞也不好，不搞也不好，怎么你都是亏本的。



1.大复杂度，不能随便常数优化乱搞；

2.公式推导的过程中，要格外小心，主要是一些特殊情况，找个好一点的草稿纸，字写清楚一点，这样check也容易；

3.公式能推导到什么复杂度，就尽可能优化，不要等到超时了，再回头重新搞

4.数学题可以优先抢占机时，因为题目理论耗时大，占用机时代价小，一些结论，公式，未必是完全正确的，可能要进一步加工修正或者优化，需要check

5.本场字符串题，太冒失了，不够冷静

6.int128很慢，要比mod慢很多

7.搞太久的题目，尤其是没有完善做法的，应该要放掉，想别的题目

8.多人合作搞一道题，前后交接一定要反复check题意

9.平时偶然拾到的东西是一种缘分，要珍惜缘分；本来那道线性基是我们都没做过的，本来就没太大希望，但是我之前刷知乎偶然发现了，并且提出来了，结果我们还是没人去搞，有缘无分，这就叫遗憾



