#include <iostream>
#include "Unitgroup.h"
#include "Item.h"
#include "DepthFirstIterator.h"
#include "BreadthFirstIterator.h"

void IteratorsTesting() {
    Container* root = new Container(100, "root");
    
    Item* item1 = new Item(10, "item1");
    Item* item2 = new Item(20, "item2");
    
    Palette* subGroup1 = new Palette(50, "subgroup1");
    Item* item3 = new Item(30, "item3");
    Item* item4 = new Item(40, "item4");
    
    Container* subGroup2 = new Container(60, "subgroup2");
    Item* item5 = new Item(50, "item5");
    Item* item6 = new Item(60, "item6");
    
    subGroup2->add(item5);
    subGroup2->add(item6);
    
    subGroup1->add(item3);
    subGroup1->add(item4);
    
    root->add(item1);
    root->add(subGroup1);
    root->add(subGroup2);
    root->add(item2);
    
    std::cout << "=== Depth-First Traversal ===\n";
    UnitIterator* dfIt = root->createDepthFirstIterator();
    for (dfIt->first(); !dfIt->isDone(); dfIt->next()) {
        Unit* u = dfIt->currentItem();
        std::cout << u->getId() << "\n";
    }
    delete dfIt;
    
    std::cout << "\n=== Breadth-First Traversal ===\n";
    UnitIterator* bfIt = root->createBreadthFirstIterator();
    for (bfIt->first(); !bfIt->isDone(); bfIt->next()) {
        Unit* u = bfIt->currentItem();
        std::cout << u->getId() << "\n";
    }
    delete bfIt;
    
    delete root;
}