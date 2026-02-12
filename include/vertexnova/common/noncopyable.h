#pragma once
/* ---------------------------------------------------------------------
 * Copyright (c) 2024 Ajeet Singh Yadav. All rights reserved.
 * Licensed under the Apache License, Version 2.0 (the "License")
 *
 * Author:    Ajeet Singh Yadav
 * Created:   January 2025
 *
 * Autodoc:   yes
 * ----------------------------------------------------------------------
 */

namespace vertexnova {

/**
 * @class NonCopyable
 * @brief Base class that disables copy construction and copy assignment.
 *
 * Inherit privately when a type must not be copied (e.g. mutexes, file handles,
 * unique resources). Move operations are still allowed unless you also inherit
 * NonMovable.
 *
 * @example
 * class MyResource : private NonCopyable { ... };
 */
class NonCopyable {
public:
    NonCopyable() = default;
    ~NonCopyable() = default;

    NonCopyable(const NonCopyable&) = delete;
    NonCopyable& operator=(const NonCopyable&) = delete;

    NonCopyable(NonCopyable&&) = default;
    NonCopyable& operator=(NonCopyable&&) = default;
};

/**
 * @class NonMovable
 * @brief Base class that disables move construction and move assignment.
 *
 * Inherit privately when a type must not be moved (e.g. objects with stable
 * addresses, or types that manage resources by raw pointer). Copy operations
 * are still allowed unless you also inherit NonCopyable.
 *
 * @example
 * class PinnedObject : private NonMovable { ... };
 */
class NonMovable {
public:
    NonMovable() = default;
    ~NonMovable() = default;

    NonMovable(const NonMovable&) = default;
    NonMovable& operator=(const NonMovable&) = default;

    NonMovable(NonMovable&&) = delete;
    NonMovable& operator=(NonMovable&&) = delete;
};

/**
 * @class NonCopyableNonMovable
 * @brief Base class that disables both copy and move operations.
 *
 * Inherit privately for types that are neither copyable nor movable (e.g.
 * singletons, objects with stable identity, or heavy resources that should
 * only be created in place or via a factory).
 *
 * @example
 * class Singleton : private NonCopyableNonMovable { ... };
 */
class NonCopyableNonMovable {
public:
    NonCopyableNonMovable() = default;
    ~NonCopyableNonMovable() = default;

    NonCopyableNonMovable(const NonCopyableNonMovable&) = delete;
    NonCopyableNonMovable& operator=(const NonCopyableNonMovable&) = delete;

    NonCopyableNonMovable(NonCopyableNonMovable&&) = delete;
    NonCopyableNonMovable& operator=(NonCopyableNonMovable&&) = delete;
};

}  // namespace vertexnova
