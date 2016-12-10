/* 
 * File:   component.hpp
 * Author: nikos
 *
 * Created on November 28, 2016, 1:29 AM
 */

#ifndef COMPONENT_HPP
#define	COMPONENT_HPP

#define UINT32_T_MAX (0xffffffff)

#include <iostream>
#include "Index.hpp"

class Component {
    
    private:
        uint32_t component_id;
        uint32_t included_nodes_count;
        uint32_t* included_node_ids;
        uint32_t componentSize;
    public:
        Component(uint32_t);
        ~Component();
        void increaseIncludedNodesCount();
        int addIncludedNode(uint32_t);
        uint32_t getComponentId();
        uint32_t getIncludedNodeIdAtPosition(uint32_t);
        uint32_t getComponentSize();
        void setComponentSize(uint32_t);
        void setIncludedNodesCount(uint32_t);
        void doubleComponentSize();
        bool isFullComponent();
        void setComponentId(uint32_t);
};

#endif	/* COMPONENT_HPP */