#include <glm/gtc/matrix_transform.hpp>
#include "graphics/transform.hpp"

// -----------------------------------
//  Transform class implementation
// -----------------------------------

namespace ad::graphics
{
    Mat4f Transform::toMatrix() const
    {
        Mat4f matrix(1.0f);
        // Moving the matrix by position
        matrix = glm::translate(matrix, position);
        // Rotating the matrix by rotation
        matrix = glm::rotate(matrix, rotation.x, { 1, 0, 0 });
        matrix = glm::rotate(matrix, rotation.y, { 0, 1, 0 });
        matrix = glm::rotate(matrix, rotation.z, { 0, 0, 1 });
        // Scaling the matrix by scale
        matrix = glm::scale(matrix, scale);

        return matrix;
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    bool operator==(const Transform& left, const Transform& right)
    {
        return left.position == right.position &&
               left.rotation == right.rotation &&
               left.scale    == right.scale;
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    bool operator!=(const Transform left, const Transform& right)
    {
        return !(left == right);
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    Transform operator+(const Transform& left, const Transform& right)
    {
        return Transform { left.position + right.position,
                           left.rotation + right.rotation,
                           left.scale    + right.scale };
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    Transform operator-(const Transform& left, const Transform& right)
    {
        return Transform { left.position - right.position,
                           left.rotation - right.rotation,
                           left.scale    - right.scale };
    }
    
    /////////////////////////////////////////////////////////////////////////////////////////////////////
    
    Transform operator*(const Transform& left, const Transform& right)
    {
        return Transform { left.position * right.position,
                           left.rotation * right.rotation,
                           left.scale    * right.scale };
    }
    
    /////////////////////////////////////////////////////////////////////////////////////////////////////
    
    Transform operator/(const Transform& left, const Transform& right)
    {
        return Transform { left.position - right.position,
                           left.rotation - right.rotation,
                           left.scale    - right.scale };        
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    Transform& Transform::operator+=(const Transform& right)
    {
        this->position += right.position;
        this->rotation += right.rotation;
        this->scale    += right.scale;
        return *this;
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    Transform& Transform::operator-=(const Transform& right)
    {
        this->position -= right.position;
        this->rotation -= right.rotation;
        this->scale    -= right.scale;
        return *this;
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////

    Transform& Transform::operator*=(const Transform& right)
    {
        this->position *= right.position;
        this->rotation *= right.rotation;
        this->scale    *= right.scale;
        return *this;
    }
    
    /////////////////////////////////////////////////////////////////////////////////////////////////////
    
    Transform& Transform::operator/=(const Transform& right)
    {
        this->position /= right.position;
        this->rotation /= right.rotation;
        this->scale    /= right.scale;
        return *this;
    }
}
