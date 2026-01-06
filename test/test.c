/*
 * Copyright (C) 2026 chachouman
 *
 * Licensed under the GNU General Public License v2.
 * See the LICENSE file for details.
 */

#include "../src/linked_list.h"

#include <stdio.h>

int main () {
    LinkedList* a = initLinkedList();

    
    addLinkedListElement(a, 0, (void*) 1);
    addLinkedListElement(a, 0, (void*) 2);
    
    printLinkedList(a);

    addLinkedListElement(a, 0, (void*) 3);
    addLinkedListElement(a, 0, (void*) 4);
    addLinkedListElement(a, 0, (void*) 5);
    
    printLinkedList(a);

    reverseLinkedList(a);

    printLinkedList(a);

    freeLinkedList(a);

    return 0;
}