#include <iostream>
#include <vector>
#include <cstring>

namespace math {

class Vector2 {

public:

	float x;
	float y;

	Vector2(float x, float y) : x(x), y(y) {}

	bool operator == (const Vector2& other) const {
		return (x == other.x && y == other.y);
	}

};

class Graph {

	Vector2 _size;
	std::vector<Vector2> _vertices;
	std::vector<std::vector<char> > _map;

	void updateMap() {
		for (size_t i = 0; i < this->_size.y; i++) {
			memset(&this->_map[i][0], '.', this->_size.x);
		}
		for (size_t i = 0; i < this->_vertices.size(); i++) {
			this->_map.at(this->_vertices[i].y).at(this->_vertices[i].x) = 'X';
		}
	}

public:

	Graph(Vector2 size) : _size(size) {
		this->_map.resize(size.y);
		for (size_t i = 0; i < size.y; i++) {
			this->_map[i].assign(size.x, '.');
		}
	}

	void addVertex(Vector2 vertex) {
		this->_vertices.push_back(vertex);
	}

	void removeVertex(Vector2 vertex) {
		for (size_t i = 0; i < this->_vertices.size(); i++) {
			if (this->_vertices[i] == vertex) {
				this->_vertices.erase(this->_vertices.begin() + i);
				break;
			}
		}
	}

	void print() {
		this->updateMap();
		for (size_t i = 0; i < this->_size.y; i++) {
			for (size_t j = 0; j < this->_size.x; j++) {
				std::cout << this->_map[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}

};

}

int main() {

	try {

		math::Graph graph(math::Vector2(10, 10));

		graph.addVertex(math::Vector2(3, 1));
		graph.addVertex(math::Vector2(2, 5));
		graph.addVertex(math::Vector2(8, 6));
		graph.addVertex(math::Vector2(5, 8));
		graph.addVertex(math::Vector2(1, 9));

		graph.print();

		std::cout << std::endl;

		graph.removeVertex(math::Vector2(8, 6));
		graph.removeVertex(math::Vector2(1, 9));

		graph.print();

	} catch (std::exception& e) {
		std::cout << "Error catch: " << e.what() << std::endl;
	}

	return 0;
}