/*
Print all combinations of points that can compose a given number
You can win three kinds of basketball points, 1 point, 2 points, and 3 points. Given a total score n, print out all the combination to compose n.

Examples:
For n = 1, the program should print following:
1

For n = 2, the program should print following:
1 1
2

For n = 3, the program should print following:
1 1 1
1 2
2 1
3

For n = 4, the program should print following:
1 1 1 1
1 1 2
1 2 1
1 3
2 1 1
2 2
3 1

and so on …

Algorithm:
At first position we can have three numbers 1 or 2 or 3.
First put 1 at first position and recursively call for n-1.
Then put 2 at first position and recursively call for n-2.
Then put 3 at first position and recursively call for n-3.
If n becomes 0 then we have formed a combination that compose n, so print the current combination.
*/
