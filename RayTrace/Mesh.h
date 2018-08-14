#pragma once
#include "Vect3.h"
#include <vector>



class Mesh
{
public:
	std::vector<Vect3> vertices;
	std::vector<Vect3> normals;
	std::vector<float> u;
	std::vector<float> v;
	std::vector<std::vector<int>> vertexFaces;
	int verticesCount;
	int trianglesCount;

public:
	Mesh();
	Mesh(const Mesh& right);
	~Mesh();

	Mesh operator=(const Mesh& right);

};

