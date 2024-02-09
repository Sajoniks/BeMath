#pragma once

namespace BeMath
{
	/**
	 * Three dimensional float vector
	 */
	struct Vector3f
	{
		Vector3f() = default;

		Vector3f(float x, float y, float z)
			: x(x)
			, y(y)
			, z(z)
		{}
		
		explicit Vector3f(float x)
			: x(x)
			, y(x)
			, z(x)
		{}

		Vector3f& operator=(const Vector3f& b) = default;
		Vector3f& operator=(Vector3f&& b) = default;

		Vector3f(const Vector3f&) = default;
		Vector3f(Vector3f&&) = default;
		
		float x { 0.f };
		float y { 0.f };
		float z { 0.f };

		float size() const;
		float sizeSquared() const;

		~Vector3f() = default;
	};


	Vector3f operator*(const Vector3f& a, float b);
	Vector3f operator*(float a, const Vector3f& b);
	Vector3f operator+(const Vector3f& a, const Vector3f& b);
	Vector3f operator-(const Vector3f& a, const Vector3f& b);

	/** @returns Dot product of two given vectors */
	extern float Dot(const Vector3f& a, const Vector3f& b);

	/** @returns Normalized vector of size 1 */
	extern Vector3f Normalize(const Vector3f& a);
	
	/** @returns Cross product of two given vectors */
	extern Vector3f Cross(const Vector3f& a, const Vector3f& b);
}
