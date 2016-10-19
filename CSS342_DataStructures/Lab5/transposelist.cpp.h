//
//  transposelist.cpp.h
//  Lab5_Part2
//
//  Created by Gregory Asher on 2/17/16.
//  Copyright © 2016 Gregory Asher. All rights reserved.
//

template<class Object>
int TransposeList<Object>::find( const Object &obj ) {
    DListNode<Object> *found = DList<Object>::header->next;
    
    int i = 0;
    for ( ; found != NULL && found->item != obj;  found = found->next, ++i )
        ++DList<Object>::cost;
    
    if ( found == NULL )
        return -1; // not found
    
    if ( found == DList<Object>::header->next )
        return 0;  // no need to swap
    
    DList<Object>::remove(obj);
    DList<Object>::insert(obj, i-1);
    // remove found from the current position
    // insert found before previous
    
    return i;
}