#include "pch.h"
#include "CppUnitTest.h"
#include "../pds_10/pds_10.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestReadGraphAndPrintWeightMatrix)
        {
            std::ofstream testInput("testInput.txt");
            testInput << "4 4\n"; 
            testInput << "1 2 3\n";
            testInput << "1 3 2\n";
            testInput << "2 4 5\n";
            testInput << "3 4 4\n";
            testInput.close();
            int n, m;
            int** weightMatrix = nullptr;
            readGraph("testInput.txt", n, m, weightMatrix);
            Assert::AreEqual(4, n);
            Assert::AreEqual(4, m);
            Assert::AreEqual(INF, weightMatrix[0][0]);
            Assert::AreEqual(3, weightMatrix[0][1]);
            Assert::AreEqual(2, weightMatrix[0][2]);
            Assert::AreEqual(INF, weightMatrix[0][3]);

            Assert::AreEqual(INF, weightMatrix[1][0]);
            Assert::AreEqual(INF, weightMatrix[1][1]);
            Assert::AreEqual(INF, weightMatrix[1][2]);
            Assert::AreEqual(5, weightMatrix[1][3]);

            Assert::AreEqual(INF, weightMatrix[2][0]);
            Assert::AreEqual(INF, weightMatrix[2][1]);
            Assert::AreEqual(INF, weightMatrix[2][2]);
            Assert::AreEqual(4, weightMatrix[2][3]);

            Assert::AreEqual(INF, weightMatrix[3][0]);
            Assert::AreEqual(INF, weightMatrix[3][1]);
            Assert::AreEqual(INF, weightMatrix[3][2]);
            Assert::AreEqual(INF, weightMatrix[3][3]);
            printWeightMatrix(weightMatrix, n, "testOutput.txt");
            std::ifstream testOutput("testOutput.txt");
            std::string line;
            std::string expectedOutput[] = {
                "INF 3 2 INF ",
                "INF INF INF 5 ",
                "INF INF INF 4 ",
                "INF INF INF INF "
            };
            for (int i = 0; i < 4; ++i) {
                std::getline(testOutput, line);
                Assert::AreEqual(expectedOutput[i], line);
            }
            testOutput.close();
            deleteMatrix(weightMatrix, n);
            std::remove("testInput.txt");
            std::remove("testOutput.txt");
        }
	};
}
