#include "pch.h"
#include "CppUnitTest.h"
#include "../lab7.3 rec/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int t;
			int rowCount=100;
			int colCount=100;

			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];

			t = NumbRowZeros(a, rowCount, colCount, 0, 0);
			Assert::AreEqual(t, 0);
		}
	};
}
