/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   hashTable.cpp
 * Author: Panos
 * 
 * Created on November 15, 2016, 5:58 PM
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>  
#include <iostream>
#include <math.h>

#include "hashTable.hpp"


// Constructs the empty Hash Table object.
// Array length is set to 13 by default.
HashTable::HashTable( uint32_t tableLength )
{
    //std::cout << "Creating hash table with length: "<< tableLength << std::endl;
    if (tableLength <= 0) tableLength = 1;
    array = (uint32_t *) malloc(sizeof(uint32_t) * tableLength);
    length = tableLength;
    depth = 0;
}

void HashTable::increment_depth() {
    depth++;
    //std::cout << "Incrementing depth." << std::endl;
}

uint32_t HashTable::get_depth(){
    return depth;
}

uint32_t HashTable::hash( uint32_t key )
{

    uint32_t size = length;
    //std::cout << "Length: " << length << "." << std::endl;
    
    //std::cout << "Hashed " << key << " to:";
    
    key = ((key >> 16) ^ key) * 0x45d9f3b;
    key = ((key >> 16) ^ key) * 0x45d9f3b;
    key = (key >> 16) ^ key;

    return key % size;
}
//
//void HashTable::doubleHashTable(){
//    if( ( array = realloc(array, sizeof(uint32_t)*this->tableLength*2) ) != NULL) {
//}

// Adds an item to the Hash Table.
void HashTable::insertItem( uint32_t newItem, uint32_t offset )
{
    uint32_t index = hash( newItem );
    array[ index ] =  offset ;
}


void HashTable::doubleHashTable(uint32_t overflowNode, uint32_t newNode, uint32_t bucketDepth)
{

    uint32_t index = hash( overflowNode );
    uint32_t newIndex = index + pow(2, bucketDepth); // FIXME: This could be wrong.



    if( ( array = (uint32_t *) realloc(array, sizeof(uint32_t)*length*2) ) != NULL) {
        for (uint32_t i=0; i<length; i++){
            array[length+i] = array[i];
        }
        length = length * 2;
        depth++;
        //std::cout << "Doubled HashTable size." << std::endl;
    }
    else {
//        std::cout << "Failed to double HashTable size." << std::endl;
    }

    array[newIndex] = newNode;
}

void HashTable::splitPointers(uint32_t overflowNode, uint32_t newNode, uint32_t bucketDepth){



    uint32_t index = hash( overflowNode );
//    uint32_t newIndex = index + pow(2, bucketDepth); // FIXME: This could be wrong.

//    std::cout << "Spliting pointers " << index << " points to: " << newNode << std::endl;

    array[index] = newNode;
}

// Returns an item from the Hash Table by key.
// If the item isn't found, a null pointer is returned.
uint32_t HashTable::getItemByKey( uint32_t itemKey )
{
    uint32_t index = hash( itemKey );
    return array[ index ];
}

// Returns the number of locations in the Hash Table.
uint32_t HashTable::getLength()
{
    return length;
}

// Returns the number of Items in the Hash Table.
uint32_t HashTable::getNumberOfItems()
{
//    int itemCount = 0;
//    for ( int i = 0; i < length; i++ )
//    {
//        itemCount += array[i].getLength();
//    }
//    return itemCount;
    return 0;
}

// De-allocates all memory used for the Hash Table.
HashTable::~HashTable()
{
    delete [] array;
}

