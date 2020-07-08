#include "stdafx.h"
#include "CppUnitTest.h"
#include "C:\Users\��� �������\source\repos\��0\��0\ListSequence.h"
#include "C:\Users\��� �������\source\repos\��0\��0\Sequence.h"
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

			Logger::WriteMessage("1. ������� ������ ������������������");
			Assert::AreEqual(sequence_result->GetIsEmpty(), true);
			Logger::WriteMessage("	��������\n");

			Logger::WriteMessage("2. ���������, ��� ����� = 0");
			Assert::AreEqual(sequence_result->GetLength(), 0);
			Logger::WriteMessage("	��������\n");

			Logger::WriteMessage("3. �������� (Append) ������� �23�");
			sequence_result->Append(23);
			int arr_1[1] = { 23 };
			sequence_expected->Filling_from_array(arr_1, 1);
			Assert::AreEqual(Sequence_Equal(sequence_result, sequence_expected), 0);
			Logger::WriteMessage("	��������\n");

			Logger::WriteMessage("4. ���������, ��� ����� = 1");
			Assert::AreEqual(sequence_result->GetLength(), 1);
			Logger::WriteMessage("	��������\n");

			Logger::WriteMessage("5. ���������, ��� GetFisrt ���������� �23�");
			Assert::AreEqual(sequence_result->GetFirst(), 23);
			Logger::WriteMessage("	��������\n");

			Logger::WriteMessage("6. ���������, ��� GetLast ���������� �23�");
			Assert::AreEqual(sequence_result->GetLast(), 23);
			Logger::WriteMessage(" ��������\n");

			Logger::WriteMessage("7. ���������, ��� Get(0) ���������� �23�, � Get(-1) � Get(1) � ����������� ����������.");
			Assert::AreEqual(sequence_result->Get(0), 23);
			try {
				Node<int> *node = new Node<int>(sequence_result->Get(-1));
			}
			catch (std::exception &e) {
				Logger::WriteMessage("������� ���������� (������ -1)");
			}
			try {
				Node<int> *node = new Node<int>(sequence_result->Get(1));
			}
			catch (std::exception &e) {
				Logger::WriteMessage("������� ���������� (������ 1)");
			}
			Logger::WriteMessage("	��������\n");

			Logger::WriteMessage("8. �������� (Append) ������� �43�");
			sequence_result->Append(43);
			int arr_2[2] = { 23, 43 };
			
			sequence_expected->Filling_from_array(arr_2, 2);
			Assert::AreEqual(Sequence_Equal(sequence_result, sequence_expected), 0);
			Logger::WriteMessage("	��������\n");

			Logger::WriteMessage("9. ���������, ��� ����� = 2");
			Assert::AreEqual(sequence_result->GetLength(), 2);
			Logger::WriteMessage("	��������\n");

			Logger::WriteMessage("10. ���������, ��� GetFisrt ���������� �23�");
			Assert::AreEqual(sequence_result->GetFirst(), 23);
			Logger::WriteMessage("	��������\n");

			Logger::WriteMessage("11. ���������, ��� GetLast ���������� �43�");
			Assert::AreEqual(sequence_result->GetLast(), 43);
			Logger::WriteMessage(" ��������\n");

			Logger::WriteMessage("12. ���������, ��� Get(0) ���������� �23�, Get(1) � �43�, � Get(-1) � Get(2) � ����������� ����������");
			Assert::AreEqual(sequence_result->Get(0), 23);
			Assert::AreEqual(sequence_result->Get(1), 43);
			try {
				Node<int> *node = new Node<int>(sequence_result->Get(-1));
			}
			catch (std::exception &e) {
				Logger::WriteMessage("������� ���������� (������ -1)");
			}
			try {
				Node<int> *node = new Node<int>(sequence_result->Get(2));
			}
			catch (std::exception &e) {
				Logger::WriteMessage("������� ���������� (������ 2)");
			}
			Logger::WriteMessage("	��������\n");

			Logger::WriteMessage("13. �������� (Prepend) ������� �53�");
			sequence_result->Prepend(53);
			int arr_3[3] = { 53, 23, 43 };
			sequence_expected->Filling_from_array(arr_3, 3);
			Assert::AreEqual(Sequence_Equal(sequence_result, sequence_expected), 0);
			Logger::WriteMessage("	��������\n");

			Logger::WriteMessage("14. ���������, ��� ����� = 3");
			Assert::AreEqual(sequence_result->GetLength(), 3);
			Logger::WriteMessage("	��������\n");

			Logger::WriteMessage("15. ���������, ��� GetFisrt ���������� �53�");
			Assert::AreEqual(sequence_result->GetFirst(), 53);
			Logger::WriteMessage("	��������\n");

			Logger::WriteMessage("16. ���������, ��� GetLast ���������� �43�");
			Assert::AreEqual(sequence_result->GetLast(), 43);
			Logger::WriteMessage(" ��������\n");

			Logger::WriteMessage("17. ���������, ��� Get(0) ���������� �53�, Get(1) � �23�, � Get(-1) � Get(3) � ����������� ����������");
			Assert::AreEqual(sequence_result->Get(0), 53);
			Assert::AreEqual(sequence_result->Get(1), 23);
			try {
				Node<int> *node = new Node<int>(sequence_result->Get(-1));
			}
			catch (std::exception &e) {
				Logger::WriteMessage("������� ���������� (������ -1)");
			}
			try {
				Node<int> *node = new Node<int>(sequence_result->Get(3));
			}
			catch (std::exception &e) {
				Logger::WriteMessage("������� ���������� (������ 3)");
			}
			Logger::WriteMessage("	��������\n");
			
			Logger::WriteMessage("18. ���������, ��� GetSubsequence(1, 1) ���������� ������������������");
			ListSequence<int> *listsubsequence_result = new ListSequence<int>();
			Sequence<int> *subsequence_result = listsubsequence_result;
			subsequence_result = sequence_result->GetSubsequence(1, 1);
			int arr_4[1] = { 23 };
			
			sequence_expected->Filling_from_array(arr_4, 1);
			Assert::AreEqual(Sequence_Equal(subsequence_result, sequence_expected), 0);
			Logger::WriteMessage("	��������\n");

			Logger::WriteMessage("\t18.1. ����� ��������������������� = 1");
			Assert::AreEqual(subsequence_result->GetLength(), 1);
			Logger::WriteMessage("	��������\n");

			Logger::WriteMessage("\t18.2. ������ � ��������� ������� - 23");
			Assert::AreEqual(subsequence_result->GetFirst(), 23);
			Assert::AreEqual(subsequence_result->GetLast(), 23);
			Logger::WriteMessage("	��������\n");

			Logger::WriteMessage(" ���� ������� ");
		}

	};
}