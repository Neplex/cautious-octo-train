#include <stdlib.h>

#include "vector.hpp"

#undef NDEBUG
#include <assert.h>

using namespace std;

// Might prove usefull
#define COPY_VECT(v_dest, v_source)                                            \
  {                                                                            \
    (v_dest).size = (v_source).size;                                           \
    element = new float[size];                                                 \
    for (unsigned int i = 0; i < size; i++) {                                  \
      (v_dest).element[i] = (v_source).element[i];                             \
    }                                                                          \
  }

Vector::Vector(const Vector &v) { COPY_VECT(*this, v); }

Vector::~Vector() { delete[] element; }

void Vector::init_alea() {
  for (unsigned int i = 0; i < size; i++) {
    element[i] = drand48();
  }
}

float &Vector::operator[](unsigned int const i) { return element[i]; }

float const &Vector::operator[](unsigned int const i) const {
  return element[i];
}

std::ostream &operator<<(std::ostream &ost, Vector const &v) {
  ost << '(';
  for (unsigned int i = 0; i < v.size; i++) {
    if (i > 0) {
      ost << ',';
    }
    ost << v.element[i];
  }
  ost << ')' << endl;
  return ost;
}

Vector &Vector::operator=(Vector const &v) {
  COPY_VECT(*this, v);
  return *this;
}

Vector Vector::operator+(Vector const &v) const {
  assert(size == v.size);
  Vector n = Vector(size);
  for (unsigned int i = 0; i < size; i++) {
    n.element[i] = element[i] + v.element[i];
  }
  return n;
}

Vector Vector::operator-(Vector const &v) const {
  assert(size == v.size);
  Vector n = Vector(size);
  for (unsigned int i = 0; i < size; i++) {
    n.element[i] = element[i] - v.element[i];
  }
  return n;
}

Vector Vector::operator*(float const a) const {
  Vector n = Vector(size);
  for (unsigned int i = 0; i < size; i++) {
    n.element[i] = element[i] * a;
  }
  return n;
}

float Vector::operator|(Vector const &v) const {
  assert(size == v.size);
  int sum = 0;
  for (unsigned int i = 0; i < size; i++) {
    sum += element[i] * v.element[i];
  }
  return sum;
}

bool Vector::operator==(Vector const &v) const {
  assert(size == v.size);
  bool is_equal = true;
  for (unsigned int i = 0; i < size && is_equal; i++) {
    is_equal = (element[i] == v.element[i]);
  }
  return is_equal;
}

Vector operator*(float const a, Vector const &v) { return v * a; }
