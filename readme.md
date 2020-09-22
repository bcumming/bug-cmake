# Reproducer for CMake bug

This issue occurs only with the CMake version available via module, i.e. `CMake/3.14.5` via `/apps/daint/UES/jenkins/7.0.UP02/gpu/easybuild/modules/all`.
If I use the system-wide version `/usr/bin/cmake` there is no problem.

To reproduce the issue with this repo, clone and compile with the following commands on Piz Daint:

```bash
# load modules
module load daint-gpu CMake cray-python

# get the reproducer
git clone https://github.com/bcumming/bug-cmake.git --recursive

cd bug-cmake
mkdir build
cd build
cmake ..
```

This produces a CMake warning:
```
CMake Warning (dev) at pybind11/tools/pybind11Tools.cmake:147 (add_library):
  ADD_LIBRARY called with MODULE option but the target platform does not
  support dynamic linking.  Building a STATIC library instead.  This may lead
  to problems.
Call Stack (most recent call first):
  CMakeLists.txt:14 (pybind11_add_module)
```

There is an error when trying to use the generated module:
```
python -c 'import tmod; print(tmod.add(20,22))'
Traceback (most recent call last):
  File "<string>", line 1, in <module>
ImportError: /users/bcumming/pytest/build/tmod.cpython-38-x86_64-linux-gnu.so: invalid ELF header
```

*Note* the error occurs on the `import` statement, not the `print`.

I need a higher version of cmake for my project, which also breaks with the same warning.

