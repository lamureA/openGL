//
// Created by alexandre on 09/05/19.
//

#include "Matrix4.h"
#include "Vector3.h"

void Matrix4::operator*=(const Matrix4 &rhs) {
    float res[4][4];
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            float sum = 0;
            for (int k = 0; k < 4; ++k) {
                sum += data[i][k] * rhs.data[k][j];
            }
            res[i][j] = sum;
        }
    }
}

Matrix4 Matrix4::identity() {
    auto mat = Matrix4();
    mat.data[0][0] = 1;
    mat.data[1][1] = 1;
    mat.data[2][2] = 1;
    mat.data[3][3] = 1;
    return mat;
}

Matrix4::Matrix4() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            data[i][j] = 0;
        }
    }
}

std::ostream& operator<<(std::ostream& out, const Matrix4& mat) {
    for (int i = 0; i < 4; ++i) {
        out << mat.data[i][0];
        for (int j = 1; j < 4; ++j) {
            out << " " << mat.data[i][j];
        }
        out << "\n";
    }
    return out;
}


void frustum(Matrix4& mat, const float &left, const float& right,
             const float& bottom, const float& top,
             const float& z_near, const float& z_far) {
    auto projection = Matrix4();
    projection.data[0][0] = 2 * z_near / (right - left);
    projection.data[1][1] = 2 * z_near / (top - bottom);

    projection.data[0][2] = (right + left) / (right - left);
    projection.data[1][2] = (top + bottom) / (top - bottom);
    projection.data[2][2] = - (z_far + z_near) / (z_far - z_near);
    projection.data[2][3] = - 2 * z_far * z_near / (z_far - z_near);
    projection.data[3][2] = -1;

    mat *= projection;
}


void look_at(Matrix4& mat, const float& eyeX, const float& eyeY, const float& eyeZ,
             const float& centerX, const float& centerY, const float& centerZ,
             const float& upX, const float& upY, const float& upZ) {
    auto f = Vector3(centerX - eyeX, centerY - eyeY, centerZ - eyeZ);
    f.normalize();
    auto up = Vector3(upX, upY, upZ);
    up.normalize();
    Vector3 s = f * up;
    Vector3 u = s.normalize() * f;

    auto M = Matrix4();
    M.data[0][0] = s.x;
    M.data[0][1] = s.y;
    M.data[0][2] = s.z;

    M.data[1][0] = u.x;
    M.data[1][1] = u.y;
    M.data[1][2] = u.z;

    M.data[2][0] = -f.x;
    M.data[2][0] = -f.y;
    M.data[2][0] = -f.z;

    M.data[3][3] = 1;

    mat *= M;


    auto translate = Matrix4::identity();
    translate.data[3][0] = -eyeX;
    translate.data[3][1] = -eyeY;
    translate.data[3][2] = -eyeZ;

    mat *= translate;
}