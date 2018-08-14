#pragma once

#include "Compound.h"
#include "ShadeRec.h"
#include "Mesh.h"



class Grid : public Compound
{
public:
	Grid();
	Grid(Mesh* _meshPtr);
	virtual Grid* Clone() const;
	Grid(const Grid& right);
	Grid operator=(const Grid& right);
	virtual ~Grid();
	virtual BBox GetBoundingBox();
	
	void ReadFlatTriangles(char* file_name);
	void ReadSmoothTriangles(char* file_name);
	void TessellateFlatSphere(const int horizontal_steps, const int vertical_steps);
	void TessellateSmoothSphere(const int horizontal_steps, const int vertical_steps);

	virtual bool Hit(const Ray& ray, double& tmin, ShadeRec& sr);
	void SetupCells();
	void ReverseMeshNormals();
	void StoreMaterial(Material* _materialPtr, const int index);




private:
	std::vector<GeometricObject*> cells;
	int nx, nt, nz;
	BBox bbox;
	Mesh* meshPtr;
	bool reverseNormal;

	Vect3 findMinBounds();
	Vect3 findMaxBounds();
	void readPlyFile(char* filename, const int triangleType);
	void computeMeshNormals();


};







