#include "Deque.h"
#include <stdio.h>

int main(void)
{
	Deque* TestDeque = NULL;

	DequeNode Node1 = { 'A' };
	DequeNode Node2 = { 'B' };
	DequeNode Node3 = { 'C' };
	DequeNode Node4 = { 'D' };
	DequeNode Node5 = { 'E' };
	DequeNode Node6 = { 'F' };
	DequeNode Node7 = { 'G' };
	DequeNode Node8 = { 'H' };
	DequeNode Node9 = { 'I' };
	DequeNode Node10 = { 'J' };

	TestDeque = CreateDeque();	

	InsertFrontDeque(TestDeque, &Node1);		// Check InsertFront when Deque is empty
	ViewDeque(TestDeque);

	ExtractFrontDeque(TestDeque);			// Check ExtractFront when Deque has only one element
	ViewDeque(TestDeque);

	InsertFrontDeque(TestDeque, &Node2);
	ViewDeque(TestDeque);

	ExtractRearDeque(TestDeque);			// Check ExtractRear when Deque has only one element
	ViewDeque(TestDeque);

	ExtractFrontDeque(TestDeque);			// Check underflow in ExtractFront
	ExtractRearDeque(TestDeque);			// Check underflow in ExtractFront

	InsertRearDeque(TestDeque, &Node3);		// Check InsertRear when Deque is empty
	InsertFrontDeque(TestDeque, &Node4);		// Check Insert when Deque has several elements
	InsertRearDeque(TestDeque, &Node5);
	InsertFrontDeque(TestDeque, &Node6);
	InsertRearDeque(TestDeque, &Node7);
	ViewDeque(TestDeque);


	DeleteDeque(TestDeque);
	return 0;
}

