#pragma once

#include "Resource.hpp"

class ResourceManager
{
public:
    ResourceManager(){
        Resource newRes{};
        myResource = newRes;
    }

    ResourceManager(const ResourceManager& other){
        myResource = other.myResource;
    }

    ~ResourceManager(){}

    ResourceManager& operator=(const ResourceManager& other){
        if (this == &other){return *this;}
        myResource = other.myResource;
        return *this;
    }

    double get(){ return myResource.get();}

    Resource myResource;

private:
};
