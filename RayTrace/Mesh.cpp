#include "Mesh.h"

Mesh::Mesh()
{
}

Mesh::Mesh(const Mesh & right)
	:
	vertices(right.vertices),
	normals(right.normals),
	u(right.u),
	v(right.v),
	verticesCount(right.verticesCount),
	trianglesCount(right.trianglesCount)
{
}

Mesh::~Mesh()
{
}

Mesh Mesh::operator=(const Mesh & right)
{
	if (this == &right)
		return (*this);

	vertices = right.vertices;
	normals = right.normals;
	u = right.u;
	v = right.v;
	verticesCount = right.verticesCount;
	trianglesCount = right.trianglesCount;

	return (*this);
}
