#pragma once

class CVector
{
public:
    float x, y, z;

    CVector() : x(0.0f), y(0.0f), z(0.0f) {}
    CVector(float X, float Y, float Z)
    {
	    this->x = X;
	    this->y = Y;
	    this->z = Z;
	}
	
	inline CVector(CVector const& src)
	{
        x = src.x; y = src.y; z = src.z;
    }

    inline void Set(float X, float Y, float Z)
    {
        x = X; y = Y; z = Z;
    }
    
    inline CVector operator-(const CVector& vecOne, const CVector& vecTwo)
    {
        return CVector(vecOne.x - vecTwo.x, vecOne.y - vecTwo.y, vecOne.z - vecTwo.z);
    }
    
    inline CVector operator+(const CVector& vecOne, const CVector& vecTwo)
    {
        return CVector(vecOne.x + vecTwo.x, vecOne.y + vecTwo.y, vecOne.z + vecTwo.z);
    }
    
    inline CVector operator*(const CVector& vec, float multiplier)
    {
        return CVector(vec.x * multiplier, vec.y * multiplier, vec.z * multiplier);
    }
    
    inline CVector operator*(float multiplier, const CVector& vec)
    {
        return CVector(vec.x * multiplier, vec.y * multiplier, vec.z * multiplier);
    }
    
    inline float DistanceBetweenPoints(const CVector &pointOne, const CVector &pointTwo)
    {
        CVector diff = pointTwo - pointOne;
        return diff.Magnitude();
    }
};
