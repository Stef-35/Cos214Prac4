#include <iostream>
#include "Item.h"
#include "Unitgroup.h"
#include "Fragile.h"
#include "Hazardous.h"
#include "Faulty.h"

int main() {
    std::cout << "=== Decorator Pattern Testing ===\n\n";
    
    // Create a base item
    Item* baseItem = new Item(10.5, "ITM-001");
    
    // Apply decorators
    Fragile* fragileItem = new Fragile(baseItem);
    Hazardous* hazardousFragile = new Hazardous(fragileItem);
    Faulty* faultyHazardousFragile = new Faulty(hazardousFragile);
    
    // Test in Palette (which has faulty detection)
    std::cout << "=== Test in Palette with inspectChildren() ===\n";
    Palette* palette = new Palette(100, "PAL-001");
    
    Item* item1 = new Item(10, "item1");
    Item* item2 = new Item(20, "item2");
    
    // Add items to palette
    palette->add(item1);
    palette->add(faultyHazardousFragile);  // Add faulty decorated item
    palette->add(item2);
    
    std::cout << "Palette before inspection:\n";
    std::cout << "  Weight: " << palette->getWeight() << "\n";
    std::cout << "  Status: " << palette->getStatus() << "\n\n";
    
    // This will detect and remove the faulty item!
    palette->inspectChildren();
    
    std::cout << "\nPalette after inspection:\n";
    std::cout << "  Weight: " << palette->getWeight() << "\n";
    std::cout << "  Status: " << palette->getStatus() << "\n";
    
    // Clean up
    delete palette;
    
    return 0;
}