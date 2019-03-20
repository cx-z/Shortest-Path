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
	G0.addEdges('a', { { 'b',7 },{'c',14 },{'d',9} });
	G0.addEdges('b', { {'a',7},{'d',10},{'e',15} });
	G0.addEdges('c', { {'a',14},{'d',2},{'f',9} });
	G0.addEdges('d', { {'a',9},{'b',10},{'c',2},{'e',11} });
	G0.addEdges('e', { {'b',15},{'d',11},{'f',6} });
	G0.addEdges('f', { {'c',9},{'e',6} });
	//G0.addSingleEdge('a', 'b', 7);单独添加每一条边
	//G0.addSingleEdge('b', 'a', 7);
	G0.showGraph();
	Route R;
	R.get_shortest_path('c', 'a', G0);
	cout << "从c到a的最短路为：";
	vector<char>::iterator iter = R.path.begin();
	for (; iter < R.path.end()-1; iter++) {
		cout << *iter << "->";
	}
	cout << *iter << endl;
	cout << "路径总长为" << R.distance << endl;
	return 0;
}
