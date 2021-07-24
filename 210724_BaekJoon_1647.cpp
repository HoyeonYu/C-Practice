﻿#include <iostream>
#include <vector>
#include <algorithm>
#define pp pair<int, pair<int, int>>
#define MAX_VTX 100000 + 1
using namespace std;

vector<pp> vec;
int parentArr[MAX_VTX];

int findParent(int x);
void makeUnion(int x, int y);
bool isUnion(int x, int y);

int main() {
	int vtxNum, edgeNum;
	cin >> vtxNum >> edgeNum;

	for (int i = 1; i <= vtxNum; i++) {
		parentArr[i] = i;
	}

	for (int i = 0; i < edgeNum; i++) {
		int vtx1, vtx2, weight;
		cin >> vtx1 >> vtx2 >> weight;
		vec.push_back({ weight, {vtx1, vtx2} });
	}

	sort(vec.begin(), vec.end());
	int minWeightSum = 0;
	int maxWeight = 0;

	for (int i = 0; i < edgeNum; i++) {
		if (!isUnion(vec[i].second.first, vec[i].second.second)) {
			makeUnion(vec[i].second.first, vec[i].second.second);
			minWeightSum += vec[i].first;
			maxWeight = vec[i].first;
		}
	}

	minWeightSum -= maxWeight;
	cout << minWeightSum;

	return 0;
}

int findParent(int x) {
	if (parentArr[x] == x) {
		return x;
	}

	return parentArr[x] = findParent(parentArr[x]);
}

void makeUnion(int x, int y) {
	x = findParent(x);
	y = findParent(y);

	if (x != y) {
		parentArr[y] = x;
	}
}

bool isUnion(int x, int y) {
	x = findParent(x);
	y = findParent(y);

	return x == y;
}