#include "Vec3D.hpp"
#include <math.h>

void Vec3D::show(st::string label)
{
    st::cout << label << ": (" << x << ", " << y << ", " << z << ")" << st::endl;
}

void Vec3D::show(st::string label, float scalar)
{
    st::cout << label << ": " << scalar << st::endl;
}

void Vec3D::show()
{
    st::cout << '\n';
}

Vec3D Vec3D::minus()
{
    return Vec3D(-x, -y, -z);
}

Vec3D Vec3D::add(Vec3D const &other) const
{
    return Vec3D((x + other.x), (y + other.y), (z + other.z));
}

Vec3D Vec3D::sub(Vec3D const &other) const
{
    return Vec3D((x - other.x), (y - other.y), (z - other.z));
}

Vec3D Vec3D::mul(float scalar) const
{
    return Vec3D(x * scalar, y * scalar, z * scalar);
}

Vec3D Vec3D::div(float scalar)
{
    if (scalar == 0.0) {
        throw st::invalid_argument("Division by zero is not allowed.");
    }
    return Vec3D(x / scalar, y / scalar, z / scalar);
}

float Vec3D::norm() const
{
    return st::sqrt(x * x + y * y + z * z);
}

Vec3D Vec3D::unit() const
{
    float length = norm();    
    if(length > 0){
        float invLength = 1.0 / length;        //inverse the magnitude 
        return mul(invLength);
    }
    return *this;
}


float Vec3D::dot(Vec3D const &other) const
{
    return (x * other.x) + (y * other.y) + (z * other.z);
}

Vec3D Vec3D::cross(Vec3D const &other) const
{
    return Vec3D(
        (y * other.z) - (z * other.y),      // x
        -((x * other.z) - (z * other.x)),   // y
        (x * other.y) - (y * other.x)       // z
    );
}

/*
To test the functionality of the functions I copied and modified the main from the previous task.
*/

// int main()
// {
//     Vec3D selfVectorPos(1.0f, 2.0f, 3.0f);
//     Vec3D newVec (2.0f, 3.0f, 4.0f);

//     selfVectorPos.show("MyVector");
//     selfVectorPos.show("MyScalar", 3.0);

//     Vec3D selfVectorNeg = selfVectorPos.minus();
//     selfVectorNeg.show("MyVector minus");

//     Vec3D subVector = selfVectorPos.sub(selfVectorPos.minus());
//     subVector.show("Sum Sub Vector");

//     Vec3D mulVector = selfVectorPos.mul(2.0f);
//     mulVector.show("Product of Self and Scalar");

//     Vec3D quotient = mulVector.div(2.0f);
//     quotient.show("Quotient of Self and Scalar");

//     float lengthVector = selfVectorPos.norm();
//     selfVectorPos.show("Length of Vector", lengthVector); 

//     Vec3D unitVector = selfVectorPos.unit();
//     unitVector.show("Unit of Vector");

//     float dotProduct = newVec.dot(Vec3D(5.0f, 6.0f, 7.0f));
//     newVec.show("Dot Product", dotProduct);

//     Vec3D crossVector = newVec.cross(Vec3D(5.0f, 6.0f, 7.0f));
//     crossVector.show("Cross Vector");

//     return 1;
// }
