
#pragma once

#include <godot_cpp/classes/ref.hpp>

#include "Types.hpp"

namespace SWBF2
{
    template <typename K, typename T>
    class Pools {

        godot::Ref<T> m_empty;

    public:
        std::unordered_map<K, godot::Ref<T>> m_pool;

        inline virtual bool contains(const K &key)
        {
            return m_pool.contains(key);
        }

        inline virtual godot::Ref<T> &getItem(const K &key)
        {
            return m_pool.contains(key) ? m_pool.at(key) : m_empty;
        }
    };
}
