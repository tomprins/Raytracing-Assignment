#include <iostream>
#include "Object.h"

// Object class is an Abstract-parant class, implemented by the Sphere and Floor class.

// Constructor for Object, that implements a x, y and z length.
Object::Object(float x, float y, float z) : x(x), y(y), z(z){};
