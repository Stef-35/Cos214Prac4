#include "DepthFirstIterator.h"
#include "Unitgroup.h"

DepthFirstIterator::DepthFirstIterator(Unit *rootUnit) : curr(nullptr), lookup(rootUnit)
{
    if (rootUnit != nullptr)
    {
        stack.push(rootUnit);
    }
}

void DepthFirstIterator::first()
{
    while (!stack.empty())
    {
        stack.pop();
    }

    if (lookup != nullptr)
    {
        stack.push(lookup);
    }
    
    curr = nullptr;
    next();
}

void DepthFirstIterator::next()
{
    if (stack.empty())
    {
        curr = nullptr;
        return;
    }
    
    curr = stack.top();
    stack.pop();
    
    Unitgroup *group = dynamic_cast<Unitgroup*>(curr);
    if (group != nullptr)
    {
        const std::vector<Unit*>& children = group->getChildren();
        
        for (int i = children.size() - 1; i >= 0; i--)
        {
            stack.push(children[i]);
        }
    }
}

bool DepthFirstIterator::isDone()
{
    return curr == nullptr && stack.empty();
}

Unit *DepthFirstIterator::currentItem()
{
    return curr;
}