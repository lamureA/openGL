//
// Created by alexandre on 09/05/19.
//

#ifndef TP1_MATRIX4_H
#define TP1_MATRIX4_H

#include <GL/gl.h>
#include <ostream>

class Matrix4 {
public:
    float data[4][4];

    Matrix4();

    void operator*=(const Matrix4& rhs);

    static Matrix4 identity();
};

std::ostream& operator<<(std::ostream& out, const Matrix4& mat);

void frustum(Matrix4& mat, const float &left, const float& right,
                           const float& bottom, const float& top,
                           const float& z_near, const float& z_far);


void look_at(Matrix4& mat, const float& eyeX, const float& eyeY, const float& eyeZ,
             const float& centerX, const float& centerY, const float& centerZ,
             const float& upX, const float& upY, const float& upZ);


#endif //TP1_MATRIX4_H
