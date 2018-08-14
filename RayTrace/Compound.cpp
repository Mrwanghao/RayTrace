#include "Compound.h"
#include "Material.h"
#include "ShadeRec.h"

double Compound::kHugeValue = 0.01f;

Compound::Compound()
	:
	GeometricObject()
{
}

Compound * Compound::Clone() const
{
	return new Compound(*this);
}

Compound::Compound(const Compound & right)
	:
	GeometricObject(right)
{
	copyObjects(right.objects);
}

Compound::~Compound()
{
}

Compound & Compound::operator=(const Compound & right)
{
	if (this == &right)
		return (*this);

	GeometricObject::operator= (right);

	copyObjects(right.objects);

	return (*this);
}


void Compound::AddObject(GeometricObject * _objectPtr)
{
	objects.push_back(_objectPtr);
}

int Compound::GetObjectsCount()
{
	return objects.size();
}

bool Compound::Hit(const Ray & ray, double & tmin, ShadeRec & sr) const
{
	double		t;
	Vect3		normal;
	Vect3		local_hit_point;
	bool		hit = false;
	tmin = kHugeValue;
	int 		num_objects = objects.size();
	Material* materialPtr = nullptr;

	for (int j = 0; j < num_objects; j++)
		if (objects[j]->Hit(ray, t, sr) && (t < tmin)) {
			hit = true;
			tmin = t;
			materialPtr = objects[j]->GetMaterial();
			normal = sr.hitNormal;
			local_hit_point = sr.hitPosition;
		}

	if (hit) {
		sr.t = tmin;
		sr.hitNormal = normal;
		sr.hitPosition = local_hit_point;
		sr.materialPtr = materialPtr;
	}

	return (hit);
}

void Compound::deleteObjects()
{
	int objectsCount = objects.size();

	for (int j = 0; j < objectsCount; j++) {
		delete objects[j];
		objects[j] = NULL;
	}

	objects.erase(objects.begin(), objects.end());
}

void Compound::copyObjects(const std::vector<GeometricObject*>& rightObjects)
{
	deleteObjects();
	int objectsCount = rightObjects.size();

	for (int j = 0; j < objectsCount; j++)
		objects.push_back(rightObjects[j]->Clone());
}
