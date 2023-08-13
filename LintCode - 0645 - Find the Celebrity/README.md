<h2><a href="https://www.lintcode.com/problem/645/">645. Find the Celebrity</a></h2><h3>Medium</h3><hr>

<p>Suppose you are at a party with n people (labeled from 0 to n - 1) and among them, there may exist one celebrity.</p>
<p>The definition of a celebrity is that all the other n - 1 people know him/her but he/she does not know any of them.</p>
<p>Now you want to find out who the celebrity is or verify that there is not one.</p>
<p>The only thing you are allowed to do is to ask questions like: "Hi, A. Do you know B?" to get information of whether A knows B. You need to find out the celebrity (or verify there is not one) by asking as few questions as possible (in the asymptotic sense).</p>
<p>You are given a helper function bool knows(a, b) which tells you whether A knows B. Implement a function int findCelebrity(n), your function should minimize the number of calls to knows.</p>

<p>There will be exactly one celebrity if he/she is in the party. Return the celebrity's label if there is a celebrity in the party. If there is no celebrity, return -1.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong>
2 // next n * (n - 1) lines 
0 knows 1
1 does not know 0
<strong>Output:</strong> 1
<strong>Explanation:</strong> Everyone knows 1,and 1 knows no one.
</pre>

<p><strong class="example">Example 2:</strong></p>
<pre>
<strong>Input:</strong>
3 // next n * (n - 1) lines 
0 does not know 1
0 does not know 2
1 knows 0
1 does not know 2
2 knows 0
2 knows 1
<strong>Output:</strong> 0
<strong>Explanation:</strong>
The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
</pre>
