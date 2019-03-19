// Adjacency List.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<map>
#include"graph.h"
#include"Route.h"

int main()
{
	using namespace std;

	Graph G0(6);
	G0.addSingleEdge('a', 'b', 7);
	G0.addSingleEdge('b', 'a', 7);
	G0.addSingleEdge('a', 'c', 14);
	G0.addSingleEdge('c', 'a', 14);
	G0.addSingleEdge('a', 'd', 9);
	G0.addSingleEdge('d', 'a', 9);
	G0.addSingleEdge('b', 'd', 10);
	G0.addSingleEdge('d', 'b', 10);
	G0.addSingleEdge('b', 'e', 15);
	G0.addSingleEdge('e', 'b', 15);
	G0.addSingleEdge('c', 'd', 2);
	G0.addSingleEdge('d', 'c', 2);
	G0.addSingleEdge('c', 'f', 9);
	G0.addSingleEdge('f', 'c', 9);
	G0.addSingleEdge('d', 'e', 11);
	G0.addSingleEdge('e', 'd', 11);
	G0.addSingleEdge('e', 'f', 6);
	G0.addSingleEdge('f', 'e', 6);
	G0.showGraph();
	Route R;
	R.get_shortest_path('a', 'f', G0);
	cout << "从a到f的最短路为：";
	vector<char>::iterator iter = R.path.begin();
	for (; iter < R.path.end()-1; iter++) {
		cout << *iter << "->";
	}
	cout << *iter << endl;
	cout << "路径总长为" << R.distance << endl;
	return 0;
}
