# K1617_11614427_B42_OSCA3
```
Consider a scenario of demand paged memory. Page table is held in registers. It takes
8 milliseconds to service a page fault if an empty page is available or the replaced page is not
modified and 20 milliseconds if the replaced page is modified. Memory access time is 100
nanoseconds. Assume that the page to be replaced is modified 70 percent of the time. Generate a
solution to find maximum acceptable page-fault rate for access time that is not more than 200
nanoseconds.
```
# Solution
```
We know how to find an effective access time (EAT) for a given page-fault rate (p). 
Here, we have to find 'p' for given 'EAT' so we set up the following equation and solve for 'p':
(Note: 1 millisecond = 1,000,000 nanoseconds = 1e6 nanoseconds)
Time taken to service page Fault for empty page or unmodified page = 8ms.
Time taken to service page Fault for modified page = 20ms
Memory access time = 100ns
Effective Access time = 200ns
      EAT = (1-p)*(100) + (p)*(100 + (1-.7)*(8msec) + (.7)*(20msec))   
	  = 100 - 100p + 100p + (2.4e6)*p + (14e6)*p
	  = 100 + (16.4e6)*p
      200 = 100 + (16.4e6)*p
      p = 100/16.4e6 = 6.0975609756097560975609756097561e-6 ~ 6.01e-6
      p-->page Fault Rate
 ```
