#include "Question2_1.h"
#include "Misc/Helpers.h"
#include "Misc/Asserts.h"

namespace {
	static AutoRegister<Question2_1> q;
}

void removeAllOccurences(Question2_1::IntNode* node, int data, Question2_1::IntNode* parent) {
	if (node == 0 || parent == 0) return; //error
	Question2_1::IntNode* n = node;

	while (n != 0) {
		if (n->data == data) {
			RemoveNode(n, parent);
			n = parent;
		}

		parent = n;
		n = n->next;
	}
}

void Question2_1::removeDuplicates(IntNode* head) {
	if (head == 0) return;
	IntNode* n = head;

	while (n != 0) {
		removeAllOccurences(n->next, n->data, n);
		n = n->next;
	}
}

void Question2_1::RunTestImpl() const {
	int testData[] = { 0, 0, 1, 2, 3, 2, 2, 0, 3, 4, 4, 5, 5 };
	IntNode* head = CreateList(testData, ARRAY_SIZE(testData));

	printList(head);
	std::cout << std::endl;

	removeDuplicates(head);
	printList(head);
	std::cout << std::endl;

	int expectedData[] = { 0, 1, 2, 3, 4, 5 };
	
	std::vector<int> actual = ToVector(head);
	Asserts::AreEqual(expectedData, ARRAY_SIZE(expectedData), actual);
}
