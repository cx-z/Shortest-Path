#pragma once
#include<iostream>
#include<map>

using namespace std;

struct Edge { //��
	int startVertex;
	int endVertex;
	int weight;
	Edge *nextEdge;
	Edge(int s,int e,int w):startVertex(s),endVertex(e),weight(w),nextEdge(NULL){}
};

struct Vertex { //�ڵ�
	int neighborNum; //�ھӽڵ�ĸ���
	Edge *headEdge;
	Vertex() :neighborNum(0), headEdge(NULL){}
};

class Graph { //ͼ
public:
	int vertexNum;
	Vertex *V;

	map<char, int> node = {};
	map<int, char> rnode = {};
	int v_id = 0;

	Graph() :vertexNum(0), V(NULL){}
	Graph(int n) {
		if (n <= 0) {
			vertexNum = 0;
			V = NULL;
		}
		else {
			vertexNum = n;
			V = new Vertex[vertexNum];
		}
	}
	Graph(const Graph &g) {
		vertexNum = g.vertexNum;
		if (vertexNum > 0) {
			V = new Vertex[vertexNum];
			for (int i = 0; i < vertexNum; i++) {
				V[i].neighborNum = g.V[i].neighborNum;
				Edge *pEg = g.V[i].headEdge;
				if (pEg != NULL) {
					V[i].headEdge = new Edge(pEg->startVertex, pEg->endVertex, pEg->weight);
					pEg = pEg->nextEdge;
				}
				Edge *pE = V[i].headEdge;
				while (pEg != NULL) {
					pE->nextEdge = new Edge(pEg->startVertex, pEg->endVertex, pEg->weight);
					pE = pE->nextEdge;
					pEg = pEg->nextEdge;
				}
			}
		}
		else
			V = NULL;
	}
	~Graph() {
		if (V != NULL) {
			for (int i = 0; i < vertexNum; i++) {
				Edge *pE = V[i].headEdge;
				V[i].headEdge = NULL;
				while (pE != NULL) {
					Edge *pDel = pE;
					pE = pE->nextEdge;
					delete pDel;
				}
			}
			delete[]V;
			V = NULL;
		}
	}
	void addSingleEdge(char s, char e, int w);
	void showGraph();
};

//��ӵ����
void Graph::addSingleEdge(char s, char e, int w) {
	if (node.find(s) == node.end()) { //�ж�s�Ƿ����Ѿ��Ǽǹ��Ľڵ�
		node.insert(pair<char, int>(s, v_id));
		rnode.insert(pair<int, char>(v_id, s));
		v_id++;
	}
	if (node.find(e) == node.end()) { //�ж�e�Ƿ��Ѿ��Ǽǹ�
		node.insert(pair<char, int>(e, v_id));
		rnode.insert(pair<int, char>(v_id, e));
		v_id++;
	}
	
	if (node[s] == node[e] || node[s] >= vertexNum || node[e] >= vertexNum || node[s] < 0 || node[e] < 0) {
		return; //�����߽���ıߣ������Ի��ı�
	}
	Edge *pE = new Edge(node[s], node[e], w);
	if (V[node[s]].headEdge == NULL || V[node[s]].headEdge->endVertex >= node[e]) {
		pE->nextEdge = V[node[s]].headEdge;
		V[node[s]].headEdge = pE;
	}
	else {
		Edge *pH = V[node[s]].headEdge;
		while (pH->nextEdge != NULL && pH->nextEdge->endVertex < node[e]) {
			pH = pH->nextEdge;
		}
		pE->nextEdge = pH->nextEdge;
		pH->nextEdge = pE;
	}
	V[node[s]].neighborNum++;
	return;
}

void Graph::showGraph() {
	using namespace std;
	if (vertexNum > 0) {
		for (map<char, int>::iterator iter = node.begin(); iter != node.end(); iter++) {
			cout << iter->first  << ":";
			if (V[node[iter->first]].headEdge != NULL) {
				Edge *pH = V[node[iter->first]].headEdge;
				while (pH != NULL) {
					cout << "->" << rnode[pH->endVertex] << "(" << pH->weight << ")";
					pH = pH->nextEdge;
				}
			}
			cout << endl;
		}
	}
	else
		cout << "This Graph is empty!" << endl;
	return;
}
