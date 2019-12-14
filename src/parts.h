// parts.h

#ifndef _PARTS_H_
#define _PARTS_H_

#include <vector>
#include <map>
#include <string>

//**************** Part ****************
class Part 
{
public:
    Part(const std::string& n) : name(n) {}
    void describe(void) const;
    int count_howmany(const Part *p) const;
    void add_subpart(Part* p, int n);

private:
    std::string name;
    std::map<Part*, int> subparts;
};

//**************** NameContainer ****************
class NameContainer  
{
public:
	NameContainer() = default;
	~NameContainer();
	Part* lookup(const std::string& name);

private:
    std::map<std::string, Part*> name_map;
};

extern void add_part(const std::string& x, int q, const std::string& y);
extern NameContainer partContainer; 

#endif
