#include "Matte.h"
#include "ShadeRec.h"
#include "Vect3.h"
#include "World.h"
#include "Light.h"

Matte::Matte()
	:
	Material(),
	ambientBRDF(new Lambertian),
	diffuseBRDF(new Lambertian)
{
}

Matte::Matte(const Matte & right)
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
}

Material * Matte::Clone() const
{
	return new Matte(*this);
}

Matte & Matte::operator=(const Matte & right)
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

	return *this;
}

Vect3 Matte::Shade(ShadeRec & sr)
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
			L += diffuseBRDF->f(sr, wo, wi) * sr.world->lights[j]->L(sr) * ndotwi;
		}
	}

	return L;
}

Vect3 Matte::AreaLightShade(ShadeRec & sr)
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
			bool inShadow = false;

			if (sr.world->lights[j]->GetShadow())
			{
				Ray shadowRay(sr.hitPosition, -wi);
				inShadow = sr.world->lights[j]->InShadow(shadowRay, sr);
			}

			if (!inShadow)
			{
				L += diffuseBRDF->f(sr, wo, wi) * sr.world->lights[j]->L(sr) * sr.world->lights[j]->G(sr) * ndotwi / sr.world->lights[j]->pdf(sr);
			}
		}
	}

	return L;
}

Matte::~Matte()
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
}
