/*
 * Copyright (C) 2026 chachouman
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include <stdbool.h>

typedef struct LinkedListNode {
    void* value;
    struct LinkedListNode* previous;
    struct LinkedListNode* next;
} LinkedListNode;

typedef struct LinkedList {
    int length;
    LinkedListNode* first;
    LinkedListNode* last;
} LinkedList;

LinkedList* initLinkedList();
void freeLinkedList(LinkedList* list);
void addLinkedListElement(LinkedList* list, int index, void* value);
void appendLinkedListElement(LinkedList* list, void* value);
LinkedListNode* getLinkedListElement(LinkedList* list, int index);
void* removeLinkedListElement(LinkedList* list, int index);
void reverseLinkedList(LinkedList* list);
void printLinkedList(LinkedList* list);
LinkedList* initLinkedListFromArray(void** array, int length);
bool isElementInLinkedList(void* value, LinkedList* list);
