#include "ComponentCursor.hpp"

ComponentCursor::ComponentCursor(SCC* sccPointer) {
    this->total_components = sccPointer->getCurrentComponentsCount();
    this->component_ptr = (Component*) malloc(sizeof(Component) * this->total_components);
    
    for(int index = 0; index < sccPointer->getCurrentComponentsCount(); index++) {
        this->component_ptr[index] = sccPointer->getComponentAtIndex(index);
    }
}

void ComponentCursor::setTotalComponents(uint32_t total_components) {
    this->total_components = total_components;
}

uint32_t ComponentCursor::getTotalComponents() {
    return this->total_components;
}

Component ComponentCursor::getCurrentComponent(int32_t index) {
    return this->component_ptr[index];
}

