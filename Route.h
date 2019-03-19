#pragma once
#include<map>
#include<vector>
#include"graph.h"
using namespace std;

class Route {
public:
	vector<char> path = {};
	int distance = 9999;
	int get_shortest_path(char s, char d, Graph g) {
		map<char, int> dis_table;
		vector<vector<char>> pathes(g.vertexNum);
		for (int i = 0; i < g.vertexNum; i++) {
			pathes[i].push_back(s);
		}
		Edge *t_edge = g.V[g.node[s]].headEdge;
		while (t_edge != NULL) {
			dis_table.insert(pair<char, int>(t_edge->endVertex, t_edge->weight));
			pathes[g.node[t_edge->endVertex]].push_back(t_edge->endVertex);
			t_edge = t_edge->nextEdge;
		}
		for (int i = 0; i < g.vertexNum; i++) {
			t_edge = g.V[i].headEdge;
			while (t_edge != NULL) {
				if (dis_table.find(t_edge->startVertex) != dis_table.end()) {
					if (dis_table.find(t_edge->endVertex) != dis_table.end()) {
						if (dis_table[t_edge->startVertex] + t_edge->weight < dis_table[t_edge->endVertex]) {
							dis_table[t_edge->endVertex] = dis_table[t_edge->startVertex] + t_edge->weight;
							int a = g.node[t_edge->startVertex];
							int b = g.node[t_edge->endVertex];
							pathes[b].clear();
							pathes[b].insert(pathes[b].end(), pathes[a].begin(), pathes[a].end());
							pathes[b].push_back(t_edge->endVertex);
						}
					}
					else {
						dis_table[t_edge->endVertex] = dis_table[t_edge->startVertex] + t_edge->weight;
						dis_table.insert(pair<char, int>(t_edge->endVertex, dis_table[t_edge->endVertex]));
						int a = g.node[t_edge->startVertex];
						int b = g.node[t_edge->endVertex];
						pathes[b].clear();
						pathes[b].insert(pathes[b].end(), pathes[a].begin(), pathes[a].end());
						pathes[b].push_back(t_edge->endVertex);
					}
				}
				t_edge = t_edge->nextEdge;
			}
			for (int j = 0; j < i; j++) {
				t_edge = g.V[j].headEdge;
				while (t_edge != NULL) {
					if (dis_table.find(t_edge->startVertex) != dis_table.end()) {
						if (dis_table.find(t_edge->endVertex) != dis_table.end()) {
							if (dis_table[t_edge->startVertex] + t_edge->weight < dis_table[t_edge->endVertex]) {
								dis_table[t_edge->endVertex] = dis_table[t_edge->startVertex] + t_edge->weight;
								int a = g.node[t_edge->startVertex];
								int b = g.node[t_edge->endVertex];
								pathes[b].clear();
								pathes[b].insert(pathes[b].end(), pathes[a].begin(), pathes[a].end());
								pathes[b].push_back(t_edge->endVertex);
							}
						}
						else {
							dis_table[t_edge->endVertex] = dis_table[t_edge->startVertex] + t_edge->weight;
							dis_table.insert(pair<char, int>(t_edge->endVertex, dis_table[t_edge->endVertex]));
							int a = g.node[t_edge->startVertex];
							int b = g.node[t_edge->endVertex];
							pathes[b].clear();
							pathes[b].insert(pathes[b].end(), pathes[a].begin(), pathes[a].end());
							pathes[b].push_back(t_edge->endVertex);
						}
					}
					t_edge = t_edge->nextEdge;
				}
			}
		}
		path.insert(path.end(), pathes[g.node[d]].begin(), pathes[g.node[d]].end());
		distance = dis_table[d];
		return distance;
	}
};