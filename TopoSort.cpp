#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int v, vector<bool>& visited, vector<int>& order, const vector<vector<int>>& graph) {
	visited[v] = true;
	for (int u : graph[v]) {
		if (!visited[u]) {
			dfs(u, visited, order, graph);
		}
	}
	order.push_back(v); // Добавляем вершину при выходе из DFS
}

vector<int> topological_sort(const vector<vector<int>>& graph) {
	int n = graph.size();
	vector<bool> visited(n, false);
	vector<int> order;

	for (int v = 0; v < n; ++v) {
		if (!visited[v]) {
			dfs(v, visited, order, graph);
		}
	}

	reverse(order.begin(), order.end()); // Разворачиваем порядок
	return order;
}

int main() {
	// Пример графа из презентации (вершины пронумерованы)
	// 0: носки, 1: обувь, 2: штаны, 3: рубашка, 
	// 4: пиджак, 5: верхняя одежда, 6: очки
	vector<vector<int>> graph = {
		{1},        // 0 → 1
		{},         // 1
		{1, 4},     // 2 → 1, 4
		{4},        // 3 → 4
		{5},        // 4 → 5
		{},         // 5
		{}          // 6
	};

	vector<int> order = topological_sort(graph);

	cout << "Топологический порядок:\n";
	for (int v : order) {
		cout << v << " ";
	}

	return 0;
}
