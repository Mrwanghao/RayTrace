#include "Grid.h"

Grid::Grid()
{
}

Grid::Grid(Mesh * _meshPtr)
{
}

Grid * Grid::Clone() const
{
	return nullptr;
}

Grid::Grid(const Grid & right)
{
}

Grid  Grid::operator=(const Grid & right)
{
	// TODO: 在此处插入 return 语句
	return Grid();
}

Grid::~Grid()
{
}

BBox Grid::GetBoundingBox()
{
	return BBox();
}

void Grid::ReadFlatTriangles(char * file_name)
{
}

void Grid::ReadSmoothTriangles(char * file_name)
{
}

void Grid::TessellateFlatSphere(const int horizontal_steps, const int vertical_steps)
{
}

void Grid::TessellateSmoothSphere(const int horizontal_steps, const int vertical_steps)
{
}

bool Grid::Hit(const Ray & ray, double & tmin, ShadeRec & sr)
{
	return false;
}

void Grid::SetupCells()
{
}

void Grid::ReverseMeshNormals()
{
}

void Grid::StoreMaterial(Material * _materialPtr, const int index)
{
}

Vect3 Grid::findMinBounds()
{
	return Vect3();
}

Vect3 Grid::findMaxBounds()
{
	return Vect3();
}

void Grid::readPlyFile(char * filename, const int triangleType)
{
}

void Grid::computeMeshNormals()
{
}
