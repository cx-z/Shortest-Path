// Adjacency List.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<map>
#include"graph.h"

int main()
{
	using namespace std;
	int nums, rows, w;
	char s, e;

	Graph G0(3);
	G0.addSingleEdge('a', 'b', 1);
	G0.addSingleEdge('b', 'a', 1);
	//G0.addSingleEdge('a', 'c', 1);
	//G0.addSingleEdge('c', 'a', 1);
	G0.addSingleEdge('c', 'b', 1);
	G0.addSingleEdge('b', 'c', 1);
	G0.showGraph();
	return 0;
}
