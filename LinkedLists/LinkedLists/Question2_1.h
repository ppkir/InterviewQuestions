#ifndef __Question2_1__
#define __Question2_1__

#include "Misc/Question.h"
#include "Node.h"

class Question2_1 : public Question
{
public:
	typedef Node<int> IntNode;
	static void removeDuplicates(IntNode* head);

	virtual void RunTestImpl() const;
};

#endif

