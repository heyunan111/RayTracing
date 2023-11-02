#pragma once

#include <cmath>
#include <fstream>
#include <iostream>
#include <ostream>

namespace hyn {

// 向量类
class vec3 {
public:
  double e[3];
  vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

  double x() const { return e[0]; }
  double y() const { return e[1]; }
  double z() const { return e[2]; }

  vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
  double operator[](int index) const { return e[index]; }
  double &operator[](int index) { return e[index]; }

  vec3 &operator+=(const vec3 &rhs) {
    e[0] += rhs.e[0];
    e[1] += rhs.e[1];
    e[2] += rhs.e[2];
    return *this;
  }

  vec3 &operator*=(const vec3 &rhs) {
    e[0] *= rhs.e[0];
    e[1] *= rhs.e[1];
    e[2] *= rhs.e[2];
    return *this;
  }

  vec3 &operator/=(const vec3 &rhs) {
    e[0] /= rhs.e[0];
    e[1] /= rhs.e[1];
    e[2] /= rhs.e[2];
    return *this;
  }

  double length_squared() { return (e[0] * e[0] + e[1] * e[1] + e[2] * e[2]); }

  double length() { // 欧几里得距离
    return sqrt(length_squared());
  }
};

inline std::ostream &operator<<(std::ostream &out, const vec3 &v) {
  return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline vec3 operator+(const vec3 &lhs, const vec3 &rhs) {
  return vec3(lhs.e[0] + rhs.e[0], lhs.e[1] + rhs.e[1], lhs.e[2] + rhs.e[2]);
}

inline vec3 operator-(const vec3 &lhs, const vec3 &rhs) {
  return vec3(lhs.e[0] - rhs.e[0], lhs.e[1] - rhs.e[1], lhs.e[2] - rhs.e[2]);
}

inline vec3 operator*(const vec3 &lhs, const vec3 &rhs) {
  return vec3(lhs.e[0] * rhs.e[0], lhs.e[1] * rhs.e[1], lhs.e[2] * rhs.e[2]);
}

inline vec3 operator*(const vec3 &v, double t) {
  return vec3(v.e[0] * t, v.e[1] * t, v.e[2] * t);
}

inline vec3 operator*(double t, const vec3 &v) { return v * t; }

inline vec3 operator/(const vec3 &v, double t) { return (1 / t) * v; }

// 点积
inline double dot(const vec3 &l, const vec3 &r) {
  return l.e[0] * r.e[0] + l.e[1] * r.e[1] + l.e[2] * r.e[2];
}

// 叉积
inline vec3 cross(const vec3 &l, const vec3 &r) {
  return vec3(l.e[1] * r.e[2] - l.e[2] * r.e[1],
              l.e[2] * r.e[0] - l.e[0] * r.e[2],
              l.e[0] * r.e[1] - l.e[1] * r.e[0]);
}

// 单位向量
inline vec3 unit_vector(vec3 v) { return v / v.length(); }

} // namespace hyn

using point3 = hyn::vec3;