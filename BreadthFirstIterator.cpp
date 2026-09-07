#include "BreadthFirstIterator.h"
#include "Unitgroup.h"

BreadthFirstIterator::BreadthFirstIterator(Unit *rootUnit) : curr(nullptr), lookup(rootUnit)
{
    if (rootUnit != nullptr)
    {
        queue.push(rootUnit);
    }
}

void BreadthFirstIterator::first()
{
    while (!queue.empty())
    {
        queue.pop();
    }
    
    if (lookup != nullptr)
    {
        queue.push(lookup);
    }
    
    curr = nullptr;
    next();
}

void BreadthFirstIterator::next()
{
    if (queue.empty())
    {
        curr = nullptr;
        return;
    }
    
    curr = queue.front();
    queue.pop();
    
    Unitgroup *group = dynamic_cast<Unitgroup*>(curr);
    if (group != nullptr)
    {
        const std::vector<Unit*>& children = group->getChildren();
        
        for (Unit* child : children)
        {
            queue.push(child);
        }
    }
}

bool BreadthFirstIterator::isDone()
{
    return curr == nullptr && queue.empty();
}

Unit *BreadthFirstIterator::currentItem()
{
    return curr;
}