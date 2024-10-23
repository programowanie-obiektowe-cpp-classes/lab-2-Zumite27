#pragma once

#include "Resource.hpp"

class ResourceManager
{
public:
    ResourceManager() : resource_{new Resource{}} {}

    ResourceManager(const ResourceManager& other): resource_{new Resource{*other.resource_}}{}

    ResourceManager& operator=(const ResourceManager& other) {
        if (this == &other) return *this;
        delete resource_;
        resource_ = new Resource{*other.resource_};
        return *this;
    }

    ~ResourceManager() {
        delete resource_;
    }

    double get() {
        return resource_->get();
    }

private:
    Resource* resource_;

};
