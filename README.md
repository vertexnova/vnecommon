# VneCommon

Header-only library providing common utilities for VertexNova projects.

## Features

- **Platform Detection** - Macros for Windows, macOS, iOS, visionOS, Android, Linux, Web
- **Compiler Detection** - MSVC, GCC, Clang identification
- **Architecture Detection** - x64, x86, ARM64, ARM
- **Assertions** - Debug-only assertions with messages
- **Utility Macros** - Force inline, branch hints, unused variable marking

## Headers

| Header | Description |
|--------|-------------|
| `vertexnova/common/common.h` | Main include (includes all headers) |
| `vertexnova/common/platform.h` | Platform, compiler, architecture detection |
| `vertexnova/common/macros.h` | Assertions and utility macros |

## Usage

Add as a submodule:

```bash
git submodule add git@github.com:vertexnova/vnecommon.git libs/vnecommon
```

In your CMakeLists.txt:

```cmake
add_subdirectory(libs/vnecommon)
target_link_libraries(your_target PRIVATE vne::common)
```

In your C++ code:

```cpp
#include "vertexnova/common/common.h"

void example() {
    VNE_ASSERT_MSG(ptr != nullptr, "Pointer must not be null");
    VNE_UNUSED(some_variable);
    
#if defined(VNE_PLATFORM_MACOS)
    // macOS-specific code
#endif
}
```

## Requirements

- C++20 or later
- CMake 3.16 or later

## License

Apache License 2.0 - See [LICENSE](LICENSE) for details.
