//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2016 __Pearson Education__. All rights reserved.

/** ADT bag: Array-based implementation.
 @file Bag.h */


#ifndef ARRAY_BAG_
#define ARRAY_BAG_

#include <vector>
#include "BagInterface.h"

template<class ItemType>
class ArrayBag : public BagInterface<ItemType>
{
private:
   static const unsigned DEFAULT_BAG_SIZE = 30;
   ItemType items[DEFAULT_BAG_SIZE]; // array of bag items
   unsigned itemCount;               // current count of bag items
   unsigned maxItems;                // max capacity of the bag

   // Returns either the index of the element in the array items that
   // contains the given target or -1, if the array does not contain
   // the target.
   int getIndexOf(const ItemType& target) const;

public:
   ArrayBag();
   int getCurrentSize() const;
   bool isEmpty() const;
   bool add(const ItemType& newEntry);
   bool remove(const ItemType& anEntry);
   void clear();
   bool contains(const ItemType& anEntry) const;
   int getFrequencyOf(const ItemType& anEntry) const;
   std::vector<ItemType> toVector() const;
};  // end ArrayBag

#include "ArrayBag.cpp"

#endif
