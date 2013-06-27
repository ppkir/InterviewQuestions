#include "Question2_2.h"
#include "Node.h"
#include "Misc/Helpers.h"
#include "Misc/Asserts.h"

namespace {
	static AutoRegister<Question2_2> q;
}

void Question2_2::RunTestImpl() const {
	typedef Node<int> IntNode;

	int testData[] = { 0, 1, 2, 3, 4, 5 };
	size_t len = ARRAY_SIZE(testData);
	IntNode* head = CreateList(testData, len);

	printList(head);
	std::cout << std::endl;

	IntNode* elem6 = nthToTheLast(head, 6);
	Asserts::AreEqual(head, elem6);

	IntNode* elem7 = nthToTheLast(head, 7);
	Asserts::AreEqual((IntNode*)0, elem7);

	IntNode* elem1 = nthToTheLast(head, 1);
	Asserts::AreEqual(testData[len - 1], elem1->data);
}