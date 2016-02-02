#include <thread>

#include "Problem.h"
#include "OrganismObserver.h"
#include "Algorithm.h"
#include <memory>
#include "MathValue.h"
#include "Mult.h"
#include "MathOperator.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif  // _DEBUG

using namespace std;
int main()
{

	

	//COrganismObserver observer;
	//CProblem p(2);
	//p.vAddCase(CCase({ 2, 2 }, 6.3 - 2 * 0.7));
	//p.vAddCase(CCase({ 1, 2 }, 2.3 - 1 * 0.7));
	//p.vAddCase(CCase({ 3, 1 }, 4.3 - 3 * 0.7));
	//p.vAddCase(CCase({ 1, 1 }, 0.3 - 1 * 0.7));
	//p.vAddCase(CCase({ 10, 10 }, 198.3 - 10 * 0.7));
	//CAlgorithm algorithm(100, 75, p, &observer);
	///*thread alg_thread(&CAlgorithm::vStart, &algorithm);
	//alg_thread.join();*/
	//algorithm.vStart();
	

	std::unique_ptr<CMathOperator> c_mv = std::unique_ptr<CMathOperator>(new CMathOperator(nullptr));
	{
		std::unique_ptr<CNode> dm = c_mv->clone();
	}
	//CMathOperator * c_math_operator = new CMathOperator(nullptr);
	//CMathValue cmv(nullptr, 100);
	//CMathValue * cvnew = cmv.move_clone();
	//CMathValue cvnew(std::move(cmv));

	//double new_d = cvnew->dGetValue();
	//double old_d = cmv.dGetValue();
	//std::string one = "LOL";
	//std::string two = std::move(one);
	
	_CrtDumpMemoryLeaks();
	return 0;
}