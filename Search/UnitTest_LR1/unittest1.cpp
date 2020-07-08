#include "stdafx.h"
#include "CppUnitTest.h"
#include "C:\Users\Аня Егорова\source\repos\ЛР0\ЛР0\ArraySequence.h"
#include "C:\Users\Аня Егорова\source\repos\ЛР0\ЛР0\BubbleSort.h"
#include "C:\Users\Аня Егорова\source\repos\ЛР0\ЛР0\MergeSort.h"
#include "C:\Users\Аня Егорова\source\repos\ЛР0\ЛР0\SelectionSort.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest_LR1
{		
	TEST_CLASS(UnitTest1)
	{
	private:
		template<typename TElement>
		int CorrectSort(Sequence<TElement> *sequence_result) {
			for (int i = 0; i < sequence_result->GetLength()-1; i++) {
				Assert::IsTrue(sequence_result->Get(i) <= sequence_result->Get(i+1));
			}
			return 0;
		}
	public:
		
		TEST_METHOD(Bubble_sort)
		{
			Sequence<int> *seq = new ArraySequence<int>(100000);
			Logger::WriteMessage("Проверка пузырьковой сортировки:");
			BubbleSort<int> *result = new BubbleSort<int>(seq);
			Assert::AreEqual(CorrectSort(result->Sort()), 0);
			Logger::WriteMessage("	Пройдено\n");
		}

		TEST_METHOD(Merge_sort)
		{
			ArraySequence<int> *seq = new ArraySequence<int>(100000);
			Logger::WriteMessage("Проверка пузырьковой сортировки:");
			MergeSort<int> *result = new MergeSort<int>(seq);
			Assert::AreEqual(CorrectSort(result->Sort()), 0);
			Logger::WriteMessage("	Пройдено\n");
		}

		TEST_METHOD(Selection_sort)
		{
			ArraySequence<int> *seq = new ArraySequence<int>(100000);
			Logger::WriteMessage("Проверка пузырьковой сортировки:");
			SelectionSort<int> *result = new SelectionSort<int>(seq);
			Assert::AreEqual(CorrectSort(result->Sort()), 0);
			Logger::WriteMessage("	Пройдено\n");
		}

	};
}