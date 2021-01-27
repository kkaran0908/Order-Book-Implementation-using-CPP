# Order-Book-Implementation-using-CPP

Limitations:
1. Not taking time into the consideration while placing the order(Need to dig a bit deeper to resolve this issue).
2. Space and Run time complexity of the code can be optimized.
3. We can reduce number of lines.
4. As of now not reading the input from the file, instead we are reading it from the console. But this feature can be implemented with some very minor modifications.
5. It is a single threaded code, it will not work while multiple users are trying to execute the order into the market. We need to add process synchronization techniques to address this issue and scaling up the entire system.
Time Complexity Analysis:
 1.  Deletion: O(n)
 2. Modification: O(n)
 3. Adding New Order: O(log(n))
 n: Total Number of Orders already working into the market 
