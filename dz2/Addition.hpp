#ifndef ADDITION_H
#define ADDITION_H

#pragma once
#include "ICalculatable.hpp"
#include "memory"
#include "ICalculatableBinary.hpp"
using uptr_icalc = std::unique_ptr<ICalculatable>;
class Addition : protected ICalculatableBinary
{
public:
    using ICalculatableBinary::ICalculatableBinary;
    ~Addition() = default;
    double Calculate() override;
};

#endif