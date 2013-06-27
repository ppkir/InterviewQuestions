#include "Question2_4.h"
#include "Node.h"

namespace {
	static AutoRegister<Question2_4> q;
}

typedef Node<unsigned int> IntNode;

static IntNode* Sum(IntNode* n1, IntNode* n2) {
	if (n1 == 0 || n2 == 0) return 0;
	IntNode* sum = 0;

	IntNode* n1It = n1;
	IntNode* n2It = n2;

	IntNode* sumIt = 0;
	unsigned int excess = 0;
	while (n1It !=0 || n2It !=0) {
		unsigned int d1 = n1It == 0 ? 0 : n1It->data;
		unsigned int d2 = n2It == 0 ? 0 : n2It->data;

		unsigned int s = d1 + d2 + excess;
		excess = s / 10;
		s = s % 10;
		
		if (sum == 0) {
			sum = CreateNode(s);
			sumIt = sum;
		} else {
			sumIt->next = CreateNode(s);
			sumIt = sumIt->next;
		}

		n1It = n1It == 0 ? n1It : n1It->next;
		n2It = n2It == 0 ? n2It : n2It->next;
	}

	if (excess > 0) {
		sumIt->next = CreateNode(excess);
	}

	return sum;
}

static void SumTest() {
	unsigned int number1[] = { 3, 5, 6 };
	unsigned int number2[] = { 7, 0, 4, 2, 1 };
	IntNode* n1 = CreateList(number1, ARRAY_SIZE(number1));
	IntNode* n2 = CreateList(number2, ARRAY_SIZE(number2));

	IntNode* sum = Sum(n1, n2);
	Asserts::IsTrue(sum != 0);
	
	unsigned int expectedData[] = { 0, 6, 0, 3, 1 };
	std::vector<unsigned int> actual = ToVector(sum);
	Asserts::AreEqual(expectedData, ARRAY_SIZE(expectedData), actual);
}

static void SumSimpleTest() {
	unsigned int number1[] = { 5 };
	unsigned int number2[] = { 7 };

	IntNode* n1 = CreateList(number1, ARRAY_SIZE(number1));
	IntNode* n2 = CreateList(number2, ARRAY_SIZE(number2));

	IntNode* sum = Sum(n1, n2);
	Asserts::IsTrue(sum != 0);
	
	unsigned int expectedData[] = { 2, 1 };
	std::vector<unsigned int> actual = ToVector(sum);
	Asserts::AreEqual(expectedData, ARRAY_SIZE(expectedData), actual);
}

static void SumNullTest() {
	IntNode* sum = Sum(0, 0);
	Asserts::IsTrue(sum == 0);
}

void Question2_4::RunTestImpl() const {
	SumSimpleTest();
	SumTest();
	SumNullTest();
}
