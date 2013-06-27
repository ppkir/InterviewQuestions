#ifndef __Question__
#define __Question__

#include <vector>
#include "Helpers.h"
#include "Asserts.h"

class Question;

typedef std::vector<Question*> Questions;

class Question {
public:
	void RunTest() const;
private:
	virtual void RunTestImpl() const = 0;
};

class QuestionRegistry {
public:
	static Questions allQuestions();
	static void registerQuestion(Question* q);
};

template <class T>
class AutoRegister {
public:
	AutoRegister() {
		QuestionRegistry::registerQuestion(new T());
	}
};

#endif