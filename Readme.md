**Accessing the source code**
- Unzip the provided archive file to a desired location on your computer.
- Or via GitHub repository https://github.com/anhbipro144/NMLT-Final-Project

**Presentation video**
- https://drive.google.com/file/d/1AZ1lByvIRaEkXXOdyRJpJuMtndnqVupW/view?usp=sharing

**Requirements**
- CMake 3.14+.
- C++23 compiler:
  - Linux: GCC 13+ or Clang 16+.
  - macOS: Xcode 15+ (Apple Clang 15+).
  - Windows: MSVC 19.36+ (VS 2022) or MinGW-w64 with GCC 13+.
- Git and internet access (to fetch dependencies).

**Build**
- Linux/macOS:
  - mkdir -p build
  - cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
  - cmake --build build -j
- Windows (PowerShell, MSVC generator):
  - mkdir build
  - cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
  - cmake --build build --config Release

**Run**
- Linux/macOS:
  - From the build directory: ./final_project
- Windows:
  - From the build directory:
    - Release\final_project.exe (if multi-config)
    - or .\final_project.exe (single-config generators)

