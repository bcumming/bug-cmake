#include <pybind11/pybind11.h>

int add(int l, int r) {
    return l+r;
}

PYBIND11_MODULE(tmod, m) {
    m.def("add", &add);
}
