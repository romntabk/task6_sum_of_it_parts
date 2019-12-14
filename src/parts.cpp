#include <iostream>
#include "parts.h"

NameContainer partContainer;

void Part::describe(void) const
{
    std::cout << "Part " << name << " subparts are:\n";
    if (subparts.empty())
    {
        std::cout << "  It has no subparts.\n";
    }
    else
    {
        for (const auto& [part, count] : subparts)
            std::cout << "  " << count << ' ' << part->name << '\n';
    }
}

int Part::count_howmany(const Part* p) const
{
    int result = 0;

    if (this == p)
    {
        result = 1;
    }
    else
    {
        for (const auto& [subpart, howmany] : subparts)
        {
            result += howmany * subpart->count_howmany(p);
        }
    }
    return result;
}

void Part::add_subpart(Part* sub, int count)
{
    subparts[sub] += count;
}

NameContainer::~NameContainer()
{
    for (auto& val : name_map)
    {
        Part* part;
        std::tie(std::ignore, part) = val;
        delete part;
    }
}

Part* NameContainer::lookup(const std::string& name)
{
    auto& result = name_map[name];
    if (!result)
        result = new Part(name);
    return result;
}

void add_part(const std::string& part_name, int subpart_count,
              const std::string& subpart_name)
{
    auto part = partContainer.lookup(part_name);
    auto subpart = partContainer.lookup(subpart_name);
    part->add_subpart(subpart, subpart_count);
}
