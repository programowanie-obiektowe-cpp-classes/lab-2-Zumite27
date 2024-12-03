#pragma once

#include <memory>
#include "Resource.hpp"

class ResourceManager
{
public:
    ResourceManager() : resource_{std::make_unique<Resource>()} {}

    ResourceManager(const ResourceManager& other): resource_{std::make_unique<Resource>(*other.resource_)} {}

    ResourceManager& operator=(const ResourceManager& other) {
        if (this == &other) return *this;
        resource_ = std::make_unique<Resource>(*other.resource_);
        return *this;
    }

    ResourceManager(ResourceManager&& other) noexcept = default;

    ResourceManager& operator=(ResourceManager&& other) noexcept = default;

    ~ResourceManager() = default;

    double get() const {
        return resource_->get();
    }

private:
    std::unique_ptr<Resource> resource_;
};

