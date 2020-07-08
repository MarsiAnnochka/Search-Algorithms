#include "stdafx.h"
#include "CppUnitTest.h"
#include "C:\Users\��� �������\source\repos\��0\��0\SortedSequence.h"
#include "C:\Users\��� �������\source\repos\��0\��0\BinarySearch.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BinarySearching
{		
	TEST_CLASS(UnitTest1)
	{

	public:
		
		TEST_METHOD(Binary_search)
		{
			Sequence_tree<HumanParameters> *seq = new Sequence_tree<HumanParameters>();
			seq->Generate(2000);
			HumanParameters *searching = new HumanParameters(1000, 1000, 1000);
			seq->Append(searching);
			for (int i = 1; i < 5; i++) {
				
				BinarySearch<int, HumanParameters> *binary = new BinarySearch<int, HumanParameters>(seq, 1000, i, i%3 + 1);
				switch (i) {
				case 1: {
					Assert::IsTrue(binary->result->Equal(searching));
					Logger::WriteMessage("�������� �������� ���������� �������: �������\n");
					break;
				}
				case 2: {
					Assert::IsTrue(binary->result->Equal(searching));
					Logger::WriteMessage("�������� �������� ���������� ������� ��������: �������\n");
					break;
				}
				case 3: {
					Assert::IsTrue(binary->result->Equal(searching));
					Logger::WriteMessage("�������� �������� ���������� ����� �������: �������\n");
					break;
				}
				case 4: {
					Assert::IsTrue(binary->result->Equal(searching));
					Logger::WriteMessage("�������� �������� ���������� ������� ���������: �������\n");
					break;
				}
				}
			}
		}

	};
}