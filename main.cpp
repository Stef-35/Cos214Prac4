#include <iostream>
#include <string>
#include <vector>
#include "Unitgroup.h"
#include "Item.h"
#include "DepthFirstIterator.h"
#include "BreadthFirstIterator.h"
#include "Fragile.h"
#include "Hazardous.h"
#include "Faulty.h"
#include "ConcreteState.h"

using namespace std;


void testIterators() {
    std::cout << "====================================\n";
    std::cout << "Iterator TESTING\n";
    std::cout << "====================================\n";
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
    
    cout << "\n--- Structure ---\n";
    cout << "root\n";
    cout << "  ├── item1\n";
    cout << "  ├── subgroup1\n";
    cout << "  │   ├── item3\n";
    cout << "  │   └── item4\n";
    cout << "  ├── subgroup2\n";
    cout << "  │   ├── item5\n";
    cout << "  │   └── item6\n";
    cout << "  └── item2\n";
    
    cout << "\n--- Depth-First Traversal ---\n";
    UnitIterator* dfIt = root->createDepthFirstIterator();
    for (dfIt->first(); !dfIt->isDone(); dfIt->next()) {
        Unit* u = dfIt->currentItem();
        cout << "  " << u->getId() << " (weight: " << u->getWeight() << ")\n";
    }
    delete dfIt;
    
    cout << "\n--- Breadth-First Traversal ---\n";
    UnitIterator* bfIt = root->createBreadthFirstIterator();
    for (bfIt->first(); !bfIt->isDone(); bfIt->next()) {
        Unit* u = bfIt->currentItem();
        cout << "  " << u->getId() << " (weight: " << u->getWeight() << ")\n";
    }
    delete bfIt;
    
    cout << "\n--- Total Weight: " << root->getWeight() << "\n";
    
    delete root;
}

void testDecorators() {
    std::cout << "====================================\n";
    std::cout << "Decorator TESTING\n";
    std::cout << "====================================\n";
    
    Item* baseItem = new Item(10.5, "ITM-001");
    cout << "\nBase Item:\n";
    cout << "  ID: " << baseItem->getId() << "\n";
    cout << "  Weight: " << baseItem->getWeight() << "\n";
    cout << "  Inspect: " << baseItem->inspect() << "\n";
    
    Fragile* fragileItem = new Fragile(baseItem);
    Hazardous* hazardousFragile = new Hazardous(fragileItem);
    Faulty* faultyHazardousFragile = new Faulty(hazardousFragile);
    
    cout << "\nDecorated Item:\n";
    cout << "  ID: " << faultyHazardousFragile->getId() << "\n";
    cout << "  Weight: " << faultyHazardousFragile->getWeight() << "\n";
    cout << "  Inspect: " << faultyHazardousFragile->inspect() << "\n";
    cout << "  Has label 'Faulty': " << (faultyHazardousFragile->hasLabel("Faulty") ? "Yes" : "No") << "\n";
    cout << "  Has label 'Fragile': " << (faultyHazardousFragile->hasLabel("Fragile") ? "Yes" : "No") << "\n";
    
    cout << "\n--- Palette testing ---\n";
    Palette* palette = new Palette(100, "PAL-001");
    
    Item* item1 = new Item(10, "item1");
    Item* item2 = new Item(20, "item2");
    Item* item3 = new Item(30, "item3");
    
    Item* faultyInnerItem = new Item(25, "item4");
    Faulty* faultyItem = new Faulty(faultyInnerItem);
    
    palette->add(item1);
    palette->add(faultyHazardousFragile);  
    palette->add(item2);
    palette->add(faultyItem);
    palette->add(item3);
    
    cout << "\nPalette before inspection:\n";
    cout << "  Weight: " << palette->getWeight() << "\n";
    cout << "  Status: " << palette->getStatus() << "\n";
    cout << "  Children count: " << palette->getChildren().size() << "\n";
    
    palette->inspectChildren();
    
    cout << "\nPalette after inspection:\n";
    cout << "  Weight: " << palette->getWeight() << "\n";
    cout << "  Status: " << palette->getStatus() << "\n";
    cout << "  Children count: " << palette->getChildren().size() << "\n";
    
    delete palette;
} 

void testStates() {
    std::cout << "\n====================================\n";
    std::cout << "State TESTING\n";
    std::cout << "====================================\n";
    
    cout << "\n--- Testing Item State Transitions ---\n";
    
    Item* item = new Item(15, "ITEM-001");
    cout << "\nCreated Item: " << item->getId() << "\n";
    cout << "  Initial Status: " << item->getStatus() << "\n";
    cout << "  Weight: " << item->getWeight() << "\n";
    
    cout << "\n--- Advancing through states ---\n";
    
    cout << "\nStep 1: ";
    item->advance();  // Inspect -> Load
    
    cout << "\nStep 2: ";
    item->advance();  // Load -> Ship
    
    cout << "\nStep 3: ";
    item->advance();  // Ship -> Delivered
    
    cout << "\nFinal Status: " << item->getStatus() << "\n";
    
    delete item;
    
    cout << "\n--- Testing Failed Inspection ---\n";
    Item* item2 = new Item(20, "ITEM-002");
    cout << "\nCreated Item: " << item2->getId() << "\n";
    cout << "  Initial Status: " << item2->getStatus() << "\n";
    
    item2->setState(new Inspect(false));
    cout << "  Status after setState: " << item2->getStatus() << "\n";
    
    item2->advance();  
    cout << "  Status after advance: " << item2->getStatus() << "\n";
    
    item2->advance();  
    cout << "  Status after advance: " << item2->getStatus() << "\n";
    
    delete item2;
}

void testCombined() {
    std::cout << "====================================\n";
    std::cout << "Decorator && State TESTING\n";
    std::cout << "====================================\n";
    
    Item* baseItem = new Item(10, "COMBO-001");
    Fragile* fragileItem = new Fragile(baseItem);
    Hazardous* hazardousItem = new Hazardous(fragileItem);
    
    cout << "\nCreated Decorated Item: " << hazardousItem->getId() << "\n";
    cout << "  Inspect: " << hazardousItem->inspect() << "\n";
    cout << "  Weight: " << hazardousItem->getWeight() << "\n";
      
    cout << "  Base Item Status: " << baseItem->getStatus() << "\n";
    
    baseItem->advance();
    cout << "  After advance: " << baseItem->getStatus() << "\n";
    cout << "  Inspect: " << hazardousItem->inspect() << "\n";
    cout << "  Weight: " << hazardousItem->getWeight() << "\n";

    delete hazardousItem;  
}

int main() {
    testIterators();
    testDecorators();
    testStates();
    testCombined();

    Container* rootContainer = new Container(50.0, "Root-Container-01");
    Palette* activePalette = nullptr;

    int choice = 0;
    while (choice != 7){
        cout << "\n     TASKFORGE LOGISTICS CLI SYSTEM      \n\n";
        cout << " 1. Create & Attach Palette to Root Container\n";
        cout << " 2. Add Decorated Item to Active Palette\n";
        cout << " 3. Traverse Hierachy (Depth-First Search)\n";
        cout << " 4. Traverse Hierachy (Breadth-First Search)\n";
        cout << " 5. Inspect Active Palette (Filter Faulty)\n";
        cout << " 6. Advance Active Palette State\n";
        cout << " 7. Exit System\n";
        cout << "Select Choice (1-7): ";

        if (!(cin >> choice)){
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        switch (choice){
            case 1: {
                string id;
                double weight;
                cout << "Enter Palette ID: ";
                cin >> id;
                cout << "Enter Base Palette Weight: ";
                cin >> weight;

                activePalette = new Palette(weight, id);
                rootContainer->add(activePalette);
                cout << ">> Palette " << id << " created and added to " << rootContainer->getId() << "!\n";
                break;
            }
            case 2: {
                if (!activePalette){
                    cout << ">> No active palette! Please create one first (Option 1).\n";
                    break;
                }
                 string id;
                double weight;
                cout << "Enter Palette ID: ";
                cin >> id;
                cout << "Enter Base Palette Weight: ";
                cin >> weight;

                Unit* item = new Item(weight, id);
                int decChoice = -1;
                while (decChoice != 0){
                    cout << "Apply Decorator to " << item->getId() << "?\n";
                    cout << "  1. Fragile\n";
                    cout << "  2. Hazardous\n";
                    cout << "  3. Faulty\n";
                    cout << "  0. Done Decorating\n";
                    cout << "  Choice: ";

                    if (!(cin >> decChoice)) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        continue;
                    }

                    if (decChoice == 1) item = new Fragile(item);
                    else if (decChoice == 2) item = new Hazardous(item);
                    else if (decChoice == 3) item = new Faulty(item);
                }
                activePalette->add(item);
                cout << ">> Item " << id << " added to active palette!\n";
                break;
            }
            case 3: {
                cout << "\n     Depth-First Traversal       \n";
                UnitIterator* it = rootContainer->createDepthFirstIterator();
                for (it->first(); !it->isDone(); it->next()) {
                    Unit* u = it->currentItem();
                    if (u) {
                        cout << " [Unit ID: " << u->getId() 
                             << " | Weight: " << u->getWeight() 
                             << " | Inspect: " << u->inspect() << "]\n";
                    }
                }
                delete it;
                break;
            }
            case 4: {
                cout << "\n     Breadth-First Traversal     \n";
                UnitIterator* it = rootContainer->createBreadthFirstIterator();
                for (it->first(); !it->isDone(); it->next()) {
                    Unit* u = it->currentItem();
                    if (u) {
                        cout << " [Unit ID: " << u->getId() 
                             << " | Weight: " << u->getWeight() 
                             << " | Inspect: " << u->inspect() << "]\n";
                    }
                }
                delete it;
                break;
            }
            case 5: {
                if (!activePalette) {
                    cout << ">> No active palette to inspect!\n";
                    break;
                }
                cout << "\n     Inspecting Active Palette       \n";
                cout << "Current State: " << activePalette->getStatus() << "\n";
                activePalette->inspectChildren();
                cout << "Updated State: " << activePalette->getStatus() << "\n";
                break;
            }
            case 6: {
                if (!activePalette) {
                    cout << ">> No active palette selected!\n";
                    break;
                }
                cout << "\n     Advancing Palette State     \n";
                cout << "State before advance: " << activePalette->getStatus() << "\n";
                activePalette->advance();
                cout << "State after advance: " << activePalette->getStatus() << "\n";
                break;
            }
            case 7:
                cout << "Exiting TaskForge system...\n";
                break; 
            default:
                cout << "Invalid choice. Please pick between 1 and 7.\n";
                break;
        }
    }
    delete rootContainer;
    return 0;
}