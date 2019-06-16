#include "chapter_three.h"

using namespace std;

/* 3.5 Sort Stack
 *  Write a program to sort a stack such that the smallest items are on
 * the top. You can use an additional temporary stack, but you may not
 * copy the elements into any other data structure (such as an array).
 * The stack supports the following operations: push, pop, peek and
 * isEmpty.
 */

/* Explanation:
Taking the following stack [1, 3, 7, 2, 5, 9], where 1 is the top:

Initial state:
S1: [1, 3, 7, 2, 5, 9]
S2: []

State:
Pop 1 from S1 and push to S2
S1: [3, 7, 2, 5, 9]
S2: [1]

State:
Pop 3 from S1 and compare to top of S2
Since 3 is not less than 1, just push to S2
S1: [7, 2, 5, 9]
S2: [3, 1]

The same thing occurs until 2 is at the top of S1

State:
Pop 2 from S1 and compare to top of S2
Since 2 is less than 7, S2 needs to be reordered properly
S1: [5, 9]
S2: [7, 3, 1]

Since 7 > 2, pop 7 from S2 and push back onto S1
Since 3 > 2, pop 3 from S2 and push back onto S1
Since 1 < 2, push 2 onto S2

State:
S1: [3, 7, 5, 9]
S2: [2, 1]

Repeat this process until S2 is ordered from largest to smallest, starting
from the top. Afterwards, push the entirety of S2 back onto S1 to order it
from the smallest to largest.
 */

void ChapterThree::sortStack(stack<int> s1) {

	// Holds a number that is out of order when sorting
	int item = 0;
	int temp = 0;

	// Temp stack
	stack<int> s2;

	// Sort everything from original stack into temp stack until
	// the original stack is empty
	while (!s1.empty()) {
		item = s1.top();
		s1.pop();

		// Only applies when the stack is not empty AND
		// when the top of the temp stack contains a 
		// value that is greater than the next item to
		// be pushed in, which makes it out of place
		while (!s2.empty() && s2.top() > item) {
			
			// Continuously move items from the temp stack
			// back into the original stack until the proper
			// spot for the out of place value is found
			temp = s2.top();
			s2.pop();
			s1.push(temp);
		}

		// Push the item into the temp stack once it's proper
		// location has been resolved
		s2.push(item);
	}

	// Move everything back into original stack to order the values
	// by smallest to largest
	while (!s2.empty()) {
		item = s2.top();
		s2.pop();
		s1.push(item);
	}
}