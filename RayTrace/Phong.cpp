#include "Phong.h"
#include "ShadeRec.h"
#include "World.h"
#include "Light.h"

Phong::Phong()
	:
	Material(),
	ambientBRDF(new Lambertian),
	diffuseBRDF(new Lambertian),
	specularBRDF(new GlossySpecular)
{
}

Phong::Phong(const Phong & right)
	:
	Material(right)
{
	if (right.ambientBRDF)
	{
		ambientBRDF = right.ambientBRDF->Clone();
	}
	else
	{
		ambientBRDF = nullptr;
	}

	if (right.diffuseBRDF)
	{
		diffuseBRDF = right.diffuseBRDF->Clone();
	}
	else
	{
		diffuseBRDF = nullptr;
	}

	if (right.specularBRDF)
	{
		specularBRDF = right.specularBRDF->Clone();
	}
	else
	{
		specularBRDF = nullptr;
	}
}

Material * Phong::Clone() const
{
	return new Phong(*this);
}

Phong & Phong::operator=(const Phong & right)
{
	if (this == &right)
	{
		return *this;
	}

	Material::operator=(right);

	if (ambientBRDF)
	{
		delete ambientBRDF;
		ambientBRDF = nullptr;
	}

	if (right.ambientBRDF)
	{
		ambientBRDF = right.ambientBRDF->Clone();
	}

	if (diffuseBRDF)
	{
		delete diffuseBRDF;
		diffuseBRDF = nullptr;
	}

	if (right.diffuseBRDF)
	{
		diffuseBRDF = right.diffuseBRDF->Clone();
	}

	if (specularBRDF)
	{
		delete specularBRDF;
		specularBRDF = nullptr;
	}

	if (right.specularBRDF)
	{
		specularBRDF = right.specularBRDF->Clone();
	}

	return *this;
}

Vect3 Phong::Shade(ShadeRec & sr)
{
	Vect3 wo = -sr.ray.direction;
	Vect3 L = ambientBRDF->rho(sr, wo) * sr.world->ambientPtr->L(sr);
	int num_lights = sr.world->GetLights().size();

	for (int j = 0; j < num_lights; j++)
	{
		Vect3 wi = sr.world->lights[j]->GetDirection(sr);
		float ndotwi = sr.hitNormal.Dot(-wi);

		if (ndotwi > 0.0)
		{
			bool isShadow = false;

			if (sr.world->lights[j]->GetShadow())
			{
				Ray shadowRay(sr.hitPosition, -wi);
				isShadow = sr.world->lights[j]->InShadow(shadowRay, sr);
			}

			if (!isShadow)
			{
				L += (diffuseBRDF->f(sr, wo, wi) + specularBRDF->f(sr, wo, wi)) * sr.world->lights[j]->L(sr) * ndotwi;
			}
		}
	}

	return L;
}

Phong::~Phong()
{
	if (ambientBRDF)
	{
		delete ambientBRDF;
		ambientBRDF = nullptr;
	}

	if (diffuseBRDF)
	{
		delete diffuseBRDF;
		diffuseBRDF = nullptr;
	}

	if (specularBRDF)
	{
		delete specularBRDF;
		specularBRDF = nullptr;
	}
}
