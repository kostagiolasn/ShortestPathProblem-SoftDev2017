/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   hashTable.hpp
 * Author: Panos
 *
 * Created on November 15, 2016, 5:58 PM
 */

#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

class HashTable
{
private:
    
    // Array is a reference to an array of Linked Lists.
    uint32_t * array;
    
    // Length is the size of the Hash Table array.
    uint32_t length;
    
    // The global depth of the hash table.
    uint32_t depth;
    
    
    
public:
    
    
    // Returns an array location for a given item key.
    // FIXME: Move back to `private:` .
    uint32_t hash( uint32_t itemKey );
    
    
    // Constructs the empty Hash Table object.
    // Array length is set to 13 by default.
    HashTable( uint32_t tableLength = 13 );
    
    // Doubling the size of the HashTable
    void doubleHashTable(uint32_t overflowNode, uint32_t newNode, uint32_t bucketDepth);

    // Splitting two pointers of the HashTable.
    void splitPointers(uint32_t overflowNode, uint32_t newNode, uint32_t bucketDepth);
    
    // Adds an item to the Hash Table.
    void insertItem( uint32_t newItem , uint32_t offset);
    
//    // Deletes an Item by key from the Hash Table.
//    // Returns true if the operation is successful.
//    bool removeItem( uint32_t itemKey );
//    
    // Returns an item from the Hash Table by key.
    // If the item isn't found, a null pointer is returned.
    uint32_t getItemByKey( uint32_t itemKey );
    
//    // Display the contents of the Hash Table to console window.
//    void printTable();
//    
//    // Prints a histogram illustrating the Item distribution.
//    void printHistogram();
//    
    // Returns the number of locations in the Hash Table.
    uint32_t getLength();
    
    // Returns the number of Items in the Hash Table.
    uint32_t getNumberOfItems();

    uint32_t get_depth();

    void increment_depth();
    
    // De-allocates all memory used for the Hash Table.
    ~HashTable();
};
#endif /* HASHTABLE_HPP */

