#include "bemath/classes.h"
#include "bemath/math.h"

namespace BeMath
{
	float Vector3f::size() const
	{
		return Sqrt(sizeSquared());
	}

	float Vector3f::sizeSquared() const
	{
		return Sqr(x) + Sqr(y) + Sqr(z);
	}

	Vector3f operator*(const Vector3f& a, float b)
	{
		Vector3f r;
		r.x = a.x * b;
		r.y = a.y * b;
		r.z = a.z * b;
		return r;
	}

	Vector3f operator*(float a, const Vector3f& b)
	{
		Vector3f r;
		r.x = b.x * a;
		r.y = b.y * a;
		r.z = b.z * a;
		return r;
	}

	Vector3f operator+(const Vector3f& a, const Vector3f& b)
	{
		Vector3f r;
		r.x = a.x + b.x;
		r.y = a.y + b.y;
		r.z = a.z + b.z;
		return r;
	}

	Vector3f operator-(const Vector3f& a, const Vector3f& b)
	{
		Vector3f r;
		r.x = a.x - b.x;
		r.y = a.y - b.y;
		r.z = a.z - b.z;
		return r;
	}

	float Dot(const Vector3f& a, const Vector3f& b)
	{
		return a.x * b.x + a.y * b.y + a.z * b.z;
	}

	Vector3f Normalize(const Vector3f& a)
	{
		const float size = a.size();
		return Vector3f{ a.x / size, a.y / size, a.z / size };
	}

	Vector3f Cross(const Vector3f& a, const Vector3f& b)
	{
		//
		// | i  j  k  |
		// | ax ay az |
		// | bx by bz |
		//
		// => i(ay * bz - az * by) - j(ax * bz - az * bx) + k(ax * by - ay * bx)
		// => [ay * bx - az * by, az * bx - ax * bz, ax * by - ay * bx] 
		
		Vector3f r;
		r.x = a.y * b.z - a.z * b.y;
		r.y = a.z * b.x - a.x * b.z;
		r.z = a.x * b.y - a.y * b.x;
		return r;
	}
}
