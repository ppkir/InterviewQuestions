#include "Question2_1.h"
#include "Question2_2.h"


int main(int argc, char** argv)
{
	Questions qs = QuestionRegistry::allQuestions();
	Questions::const_iterator it = qs.begin();
	Questions::const_iterator end = qs.end();

	for (; it != end; ++it) {
		(*it)->RunTest();
	}

	return 0;
}