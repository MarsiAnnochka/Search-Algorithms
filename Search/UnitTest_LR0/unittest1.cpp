#include "stdafx.h"
#include "CppUnitTest.h"
#include "C:\Users\Аня Егорова\source\repos\ЛР0\ЛР0\ListSequence.h"
#include "C:\Users\Аня Егорова\source\repos\ЛР0\ЛР0\Sequence.h"
#include <sstream>
#include <cstdio>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest_LR0
{		
	TEST_CLASS(UnitTest1)
	{
	private:
		template<typename TElement>
		int Sequence_Equal(Sequence<TElement> *sequence_result, Sequence<TElement> *sequence_expected) {
			Assert::IsTrue(sequence_result->GetLength() == sequence_expected->GetLength());
			for (int i = 0; i < sequence_expected->GetLength(); i++) {
				Assert::AreEqual(sequence_result->Get(i), sequence_expected->Get(i));
				
			}
			return 0;
		}
	public:
		
		TEST_METHOD(Creating_empty_sequence)
		{
			ListSequence<int> *listsequence_result = new ListSequence<int>();
			ListSequence<int> *listsequence_expected = new ListSequence<int>();
			Sequence<int> *sequence_result = listsequence_result;
			Sequence<int> *sequence_expected = listsequence_expected;

			Logger::WriteMessage("1. Создать пустую последовательность");
			Assert::AreEqual(sequence_result->GetIsEmpty(), true);
			Logger::WriteMessage("	Пройдено\n");

			Logger::WriteMessage("2. Проверить, что длина = 0");
			Assert::AreEqual(sequence_result->GetLength(), 0);
			Logger::WriteMessage("	Пройдено\n");

			Logger::WriteMessage("3. Добавить (Append) элемент «23»");
			sequence_result->Append(23);
			int arr_1[1] = { 23 };
			sequence_expected->Filling_from_array(arr_1, 1);
			Assert::AreEqual(Sequence_Equal(sequence_result, sequence_expected), 0);
			Logger::WriteMessage("	Пройдено\n");

			Logger::WriteMessage("4. Проверить, что длина = 1");
			Assert::AreEqual(sequence_result->GetLength(), 1);
			Logger::WriteMessage("	Пройдено\n");

			Logger::WriteMessage("5. Проверить, что GetFisrt возвращает «23»");
			Assert::AreEqual(sequence_result->GetFirst(), 23);
			Logger::WriteMessage("	Пройдено\n");

			Logger::WriteMessage("6. Проверить, что GetLast возвращает «23»");
			Assert::AreEqual(sequence_result->GetLast(), 23);
			Logger::WriteMessage(" Пройдено\n");

			Logger::WriteMessage("7. Проверить, что Get(0) возвращает «23», а Get(-1) и Get(1) – выбрасывают исключение.");
			Assert::AreEqual(sequence_result->Get(0), 23);
			try {
				Node<int> *node = new Node<int>(sequence_result->Get(-1));
			}
			catch (std::exception &e) {
				Logger::WriteMessage("Поймано исключение (индекс -1)");
			}
			try {
				Node<int> *node = new Node<int>(sequence_result->Get(1));
			}
			catch (std::exception &e) {
				Logger::WriteMessage("Поймано исключение (индекс 1)");
			}
			Logger::WriteMessage("	Пройдено\n");

			Logger::WriteMessage("8. Добавить (Append) элемент «43»");
			sequence_result->Append(43);
			int arr_2[2] = { 23, 43 };
			
			sequence_expected->Filling_from_array(arr_2, 2);
			Assert::AreEqual(Sequence_Equal(sequence_result, sequence_expected), 0);
			Logger::WriteMessage("	Пройдено\n");

			Logger::WriteMessage("9. Проверить, что длина = 2");
			Assert::AreEqual(sequence_result->GetLength(), 2);
			Logger::WriteMessage("	Пройдено\n");

			Logger::WriteMessage("10. Проверить, что GetFisrt возвращает «23»");
			Assert::AreEqual(sequence_result->GetFirst(), 23);
			Logger::WriteMessage("	Пройдено\n");

			Logger::WriteMessage("11. Проверить, что GetLast возвращает «43»");
			Assert::AreEqual(sequence_result->GetLast(), 43);
			Logger::WriteMessage(" Пройдено\n");

			Logger::WriteMessage("12. Проверить, что Get(0) возвращает «23», Get(1) – «43», а Get(-1) и Get(2) – выбрасывают исключение");
			Assert::AreEqual(sequence_result->Get(0), 23);
			Assert::AreEqual(sequence_result->Get(1), 43);
			try {
				Node<int> *node = new Node<int>(sequence_result->Get(-1));
			}
			catch (std::exception &e) {
				Logger::WriteMessage("Поймано исключение (индекс -1)");
			}
			try {
				Node<int> *node = new Node<int>(sequence_result->Get(2));
			}
			catch (std::exception &e) {
				Logger::WriteMessage("Поймано исключение (индекс 2)");
			}
			Logger::WriteMessage("	Пройдено\n");

			Logger::WriteMessage("13. Добавить (Prepend) элемент «53»");
			sequence_result->Prepend(53);
			int arr_3[3] = { 53, 23, 43 };
			sequence_expected->Filling_from_array(arr_3, 3);
			Assert::AreEqual(Sequence_Equal(sequence_result, sequence_expected), 0);
			Logger::WriteMessage("	Пройдено\n");

			Logger::WriteMessage("14. Проверить, что длина = 3");
			Assert::AreEqual(sequence_result->GetLength(), 3);
			Logger::WriteMessage("	Пройдено\n");

			Logger::WriteMessage("15. Проверить, что GetFisrt возвращает «53»");
			Assert::AreEqual(sequence_result->GetFirst(), 53);
			Logger::WriteMessage("	Пройдено\n");

			Logger::WriteMessage("16. Проверить, что GetLast возвращает «43»");
			Assert::AreEqual(sequence_result->GetLast(), 43);
			Logger::WriteMessage(" Пройдено\n");

			Logger::WriteMessage("17. Проверить, что Get(0) возвращает «53», Get(1) – «23», а Get(-1) и Get(3) – выбрасывают исключение");
			Assert::AreEqual(sequence_result->Get(0), 53);
			Assert::AreEqual(sequence_result->Get(1), 23);
			try {
				Node<int> *node = new Node<int>(sequence_result->Get(-1));
			}
			catch (std::exception &e) {
				Logger::WriteMessage("Поймано исключение (индекс -1)");
			}
			try {
				Node<int> *node = new Node<int>(sequence_result->Get(3));
			}
			catch (std::exception &e) {
				Logger::WriteMessage("Поймано исключение (индекс 3)");
			}
			Logger::WriteMessage("	Пройдено\n");
			
			Logger::WriteMessage("18. Проверить, что GetSubsequence(1, 1) возвращает последовательность");
			ListSequence<int> *listsubsequence_result = new ListSequence<int>();
			Sequence<int> *subsequence_result = listsubsequence_result;
			subsequence_result = sequence_result->GetSubsequence(1, 1);
			int arr_4[1] = { 23 };
			
			sequence_expected->Filling_from_array(arr_4, 1);
			Assert::AreEqual(Sequence_Equal(subsequence_result, sequence_expected), 0);
			Logger::WriteMessage("	Пройдено\n");

			Logger::WriteMessage("\t18.1. Длина подпоследовательности = 1");
			Assert::AreEqual(subsequence_result->GetLength(), 1);
			Logger::WriteMessage("	Пройдено\n");

			Logger::WriteMessage("\t18.2. Первый и последний элемент - 23");
			Assert::AreEqual(subsequence_result->GetFirst(), 23);
			Assert::AreEqual(subsequence_result->GetLast(), 23);
			Logger::WriteMessage("	Пройдено\n");

			Logger::WriteMessage(" ТЕСТ ПРОЙДЕН ");
		}

	};
}