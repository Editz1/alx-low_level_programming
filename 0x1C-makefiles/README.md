Introduction
A hash table in C/C++ is a data structure that maps keys to values. A hash table uses a hash function to compute indexes for a key. You can store the value at the appropriate location based on the hash table index.

The benefit of using a hash table is its very fast access time. Typically, the time complexity (amortized time complexity) is a constant O(1) access time.

If two different keys get the same index, you will need to use other data structures (buckets) to account for these collisions. If you choose a very good hash function, the likelihood of a collision can be negligible.

The C++ STL (Standard Template Library) has the std::unordered_map() data structure.

In this article, you will construct a hash table from scratch comprised of:

A hash function to map keys to values.
A hash table data structure that supports insert, search, and delete operations.
A data structure to account for a collision of keys.
Choosing a Hash Function
The first step is to choose a reasonably good hash function that has a low chance of collision. However, for the purposes of this tutorial, a poor hash function will be applied to better illustrate hash collisions. This limited example will also only utilize strings (or character arrays in C).

HashTable.cpp
#define CAPACITY 50000 // Size of the HashTable.

unsigned long hash_function(char* str)
{
    unsigned long i = 0;

    for (int j = 0; str[j]; j++)
        i += str[j];

    return i % CAPACITY;
}
Run this code and test different strings for potential collisions. For example, the strings Hel and Cau will collide since they have the same ASCII value.

This code must return a number within the bounds of the capacity of the hash table. Otherwise, it may access an unbound memory location, leading to an error.

Defining the Hash Table Data Structures
A hash table is an array of items, which are { key: value } pairs.

First, define the item structure:

HashTable.cpp
// Defines the HashTable item.

typedef struct Ht_item
{
    char* key;
    char* value;
} Ht_item;
Now, the hash table has an array of pointers that point to Ht_item, so it is a double-pointer.

HashTable.cpp
// Defines the HashTable.
typedef struct HashTable
{
    // Contains an array of pointers to items.
    Ht_item** items;
    int size;
    int count;
} HashTable;
Your hash table will need to return the number of elements in the hash table using count and size of the hash table using size.

Creating the Hash Table and Hash Table Items
Next, create functions for allocating memory and creating items.

Create items by allocating memory for a key and value, and return a pointer to the item:

HashTable.cpp
Ht_item* create_item(char* key, char* value)
{
    // Creates a pointer to a new HashTable item.
    Ht_item* item = (Ht_item*) malloc(sizeof(Ht_item));
    item->key = (char*) malloc(strlen(key) + 1);
    item->value = (char*) malloc(strlen(value) + 1);
    strcpy(item->key, key);
    strcpy(item->value, value);
    return item;
}
Create the table by allocating memory and setting size, count, and items:

HashTable.cpp
HashTable* create_table(int size)
{
    // Creates a new HashTable.
    HashTable* table = (HashTable*) malloc(sizeof(HashTable));
    table->size = size;
    table->count = 0;
    table->items = (Ht_item**) calloc(table->size, sizeof(Ht_item*));

    for (int i = 0; i < table->size; i++)
        table->items[i] = NULL;

    return table;
}
The preceding example allocates memory for the wrapper structure HashTable and sets all the items to NULL.

Freeing up memory is a C/C++ best practice. Free up memory that you’ve allocated on the heap with malloc() and calloc().

Write functions that free up a table item and the whole table.