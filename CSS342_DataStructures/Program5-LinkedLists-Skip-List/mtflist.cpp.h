//
//  mtflist.cpp
//  Program5
//
//  Created by Gregory Asher on 2/28/16.
//  Copyright © 2016 Gregory Asher. All rights reserved.
//

#include "mtflist.h"
#include "dlist.h"

template<class Object>
int MtfList<Object>::find( const Object &obj ) {
    DListNode<Object> *top = DList<Object>::header->next;
    DListNode<Object> *found = top;
    
    for ( ; found != NULL && found->item != obj;  found = found->next )
        ++DList<Object>::cost;
    
    if ( found == NULL )
        return -1; // not found
    
    if ( found == top )
        return 0;  // no need to move to front
    int index = DList<Object>::getCost();
    Object temp = DList<Object>::retrieve(index);
    DList<Object>::remove(temp);
    DList<Object>::insert(temp, 0);
    // remove found from the current position
    // insert found between header and top
    
    return 0;
    
}