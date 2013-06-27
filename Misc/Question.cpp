#include <iostream>
#include "Question.h"

Questions& GetQuestions() {
	static Questions sQuestions;

	return sQuestions;
}

Questions QuestionRegistry::allQuestions() {
	return GetQuestions();
}

void QuestionRegistry::registerQuestion(Question* q) {
	GetQuestions().push_back(q);
}

void Question::RunTest() const {
	std::string testName (typeid(*this).name());
	std::cout << "***** Start test: " << testName.c_str() << "****" << std::endl;
	this->RunTestImpl();
	std::cout << "***** End test: " << testName.c_str() << "****" << std::endl;
}