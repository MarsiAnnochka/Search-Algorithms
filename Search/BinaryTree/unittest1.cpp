#include "stdafx.h"
#include "CppUnitTest.h"
#include "C:\Users\��� �������\source\repos\��0\��0\Sequence_tree.h"
#include "C:\Users\��� �������\source\repos\��0\��0\BinaryTree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BinaryTree_searching
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Binary_tree)
		{
			Sequence_tree<HumanParameters> *seq = new Sequence_tree<HumanParameters>();
			seq->Generate(10000);
			HumanParameters *searching = new HumanParameters(1000, 1000, 1000);
			seq->Append(searching);
			for (int i = 1; i < 4; i++) {
				BinaryTree<int, HumanParameters> *binary = new BinaryTree<int, HumanParameters>(seq, 1000, i);
				switch (i) {
				case 1: {
					Assert::IsTrue(binary->result->Equal(searching));
					Logger::WriteMessage("���������� �������� �� ��������� Age: �������\n");
					break;
				}
				case 2: {
					Assert::IsTrue(binary->result->Equal(searching));
					Logger::WriteMessage("���������� �������� �� ��������� Weight: �������\n");
					break;
				}
				case 3: {
					Assert::IsTrue(binary->result->Equal(searching));
					Logger::WriteMessage("���������� �������� �� ��������� Height: �������\n");
					break;
				}
				}
				binary->Delete_tree();
			}
		}

	};
}