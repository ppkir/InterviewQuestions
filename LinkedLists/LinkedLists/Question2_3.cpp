#include "Question2_3.h"
#include "Node.h"

namespace {
	static AutoRegister<Question2_3> q;
}

void Question2_3::RunTestImpl() const {
	typedef Node<int> IntNode;

	int testData[] = { 0, 0, 1, 2, 3, 2, 2, 0, 3, 4, 4, 5, 5 };
	IntNode* head = CreateList(testData, ARRAY_SIZE(testData));

	IntNode* node = FindNode(head, 3);
	Asserts::IsTrue(node != 0);

	RemoveNode(node);
	
	int expectedData[] = { 0, 0, 1, 2, 2, 2, 0, 3, 4, 4, 5, 5 };
	
	std::vector<int> actual = ToVector(head);
	Asserts::AreEqual(expectedData, ARRAY_SIZE(expectedData), actual);

	node = FindNode(head, 5);
	Asserts::IsTrue(node != 0);
	RemoveNode(node);

	node = FindNode(head, 5);
	Asserts::IsTrue(node != 0);
	try {
		RemoveNode(node);
		Asserts::Fail();
	} catch (std::logic_error& ex) {
	}
}
