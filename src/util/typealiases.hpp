#pragma once

#include <vector>
// #include <cmp/entity.hpp>

namespace ECS {

// using Vec_t<Entity_t> = std::vector<Entity_t>;

template <typename T>
using Vec_t = std::vector<T>;

using EntityID_t = std::size_t;
using ComponentID_t = std::size_t;

}  // namespace ECS
