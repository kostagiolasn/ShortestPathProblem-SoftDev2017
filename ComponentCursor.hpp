/* 
 * File:   ComponentCursor.hpp
 * Author: nikos
 *
 * Created on December 8, 2016, 9:19 PM
 */

#ifndef COMPONENTCURSOR_HPP
#define	COMPONENTCURSOR_HPP

#define UINT32_T_MAX (0xffffffff)

#include <iostream>
#include "Index.hpp"
#include "Component.hpp"
#include "scc.hpp"

class ComponentCursor {
    private:
        Component* component_ptr;
        uint32_t total_components;
        uint32_t current_component_index;
    public:
        ComponentCursor(SCC*);
        ~ComponentCursor();
        void setTotalComponents(uint32_t);
        uint32_t getTotalComponents();
        Component getCurrentComponent(int32_t);
};

#endif	/* COMPONENTCURSOR_HPP */

