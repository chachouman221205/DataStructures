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

    addLinkedListElement(a, 0, NULL);
    addLinkedListElement(a, 1, NULL);
    addLinkedListElement(a, 1, NULL);
    addLinkedListElement(a, 3, NULL);
    addLinkedListElement(a, 0, NULL);
    removeLinkedListElement(a, 3);

    freeLinkedList(a);

    return 0;
}