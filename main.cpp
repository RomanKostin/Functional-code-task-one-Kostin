#include <iostream>
#include <vector>

std::vector<std::vector<size_t>> initialize_graph(size_t nodes);
std::vector<std::vector<size_t>> optimize_path(std::vector<std::vector<size_t>> graph);
int main()
{
	size_t n = 0;
	std::cin >> n;
	std::vector<std::vector<size_t>> graph = initialize_graph(n);
	for (auto i : graph)
	{
		for (auto j : i)
		{
			std::cout << j << ' ';
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::vector<std::vector<size_t>> optimized_graph = optimize_path(graph);
	for (auto i : optimized_graph)
	{
		for (auto j : i)
		{
			std::cout << j << ' ';
		}
		std::cout << std::endl;
	}
	return 0;
}

std::vector<std::vector<size_t>> initialize_graph(size_t nodes)
{
	srand(time(0));
	std::vector<std::vector<size_t>> graph(nodes,std::vector<size_t>(nodes));
	for (size_t i = 0; i < nodes; i++)
	{
		for (size_t j = i + 1; j < nodes; j++)
		{
			size_t path = rand()%11;
			if (path == 0)
			{
				graph[i][j] = 100;//inf
				graph[j][i] = 100;//inf
			}
			else
			{
				graph[i][j] = path;
				graph[j][i] = path;
			}
		}
	}
	return graph;
}

std::vector<std::vector<size_t>> optimize_path(std::vector<std::vector<size_t>> graph)
{
	auto min = [](size_t a, size_t b) {return a < b ? a : b; };
	for (size_t k = 0; k < graph.size(); k++)
	{
		for (size_t i = 0; i < graph.size(); i++)
		{
			for (size_t j = i; j < graph.size(); j++)
			{
				size_t value = min(graph[i][j], graph[i][k] + graph[k][j]);
				graph[i][j] = value;
				graph[j][i] = value;
			}
		}
	}
	return graph;
}