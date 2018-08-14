#pragma once

#include <vector>
#include "GeometricObject.h"


class Compound : public GeometricObject
{
public:
	Compound();
	Compound(const Compound& right);
	virtual ~Compound();
	Compound& operator=(const Compound& right);
	
	virtual void AddObject(GeometricObject* _objectPtr);
	int GetObjectsCount();
	virtual Compound* Clone() const;
	virtual bool Hit(const Ray& ray, double& tmin, ShadeRec& sr) const;

	virtual inline void SetMaterial(Material* _mat) { material = _mat; }
	virtual inline Material* GetMaterial() { return material; }

private:
	static double kHugeValue;

protected:
	std::vector<GeometricObject*> objects;

private:
	void deleteObjects();
	void copyObjects(const std::vector<GeometricObject*>& rightObjects);

};











