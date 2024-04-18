#include "pch.h"
#include "CppUnitTest.h"
#include "../ap_12.3.it/Source.cpp"
#include <cassert>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* first = NULL;
			Elem* last = NULL;
			for (int i = 1; i <= 5; i++)
				enqueue(first, last, i);

			bool result = sameValue(first);
			assert(result == false);
		}
	};
}
