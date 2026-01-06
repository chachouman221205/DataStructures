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

#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>

LinkedList* initLinkedList() {
    LinkedList* list = malloc(1 * sizeof(LinkedList));
    list->length = 0;
    list->first = NULL;
    list->last = NULL;
    return list;
};

void freeLinkedList(LinkedList* list) {
    while (list->length > 0) { removeLinkedListElement(list, 0); }

    free(list);
}

void addLinkedListElement(LinkedList* list, int index, void* value) {
    LinkedListNode* node = malloc(1 * sizeof(LinkedListNode));
    node->value = value;

    if (index == list->length) {
        list->last = node;
        node->next = NULL;
    } else {
        // Attach to next node
        node->next = getLinkedListElement(list, index);
        node->next->previous = node;
    }

    if (index == 0) {
        list->first = node;
        node->previous = NULL;
    } else {
        // Attach to previous node
        node->previous = getLinkedListElement(list, index - 1);
        node->previous->next = node;
    }

    list->length++;
}

void appendLinkedListElement(LinkedList* list, void* value) {
    addLinkedListElement(list, list->length, value);
}

LinkedListNode* getLinkedListElement(LinkedList* list, int index) {
    LinkedListNode* node = list->first;

    if (index >= list->length || index < 0) {
        fprintf(stderr, "Error: Index out of range: Invalid index %d for list of size %d\n", index, list->length);
        exit(1);
    }

    for (int i = 0; i < index; i++) {
        if (node->next == NULL) {
            fprintf(stderr, "Error: LinkedList length mismatch\n");
            exit(1);
        }
        node = node->next;
    }

    return node;
}

void* removeLinkedListElement(LinkedList* list, int index) {
    LinkedListNode* nodeToRemove = getLinkedListElement(list, index);

    // If node to remove is the first node, update list header
    if (index == 0) { list->first = nodeToRemove->next; }

    // If node to remove is the last node, update list header
    if (index == list->length - 1) { list->last = nodeToRemove->previous; }

    // Remove link with previous node
    if (nodeToRemove->previous != NULL) { nodeToRemove->previous->next = nodeToRemove->next; }

    // Remove link with next node
    if (nodeToRemove->next != NULL) { nodeToRemove->next->previous = nodeToRemove->previous; }

    list->length--;

    // Remember value to return
    void* value = nodeToRemove->value;

    free(nodeToRemove);
    return value;
}

void reverseLinkedList(LinkedList* list) {
    LinkedListNode* node = list->first;
    LinkedListNode* temp;
    for (int i = 0; i < list->length; i++) {
        if (node == NULL) {
            fprintf(stderr, "Error: LinkedList length mismatch\n");
            exit(1);
        }
        temp = node->next;
        node->next = node->previous;
        node->previous = temp;

        node = node->previous;  // order is reversed, so previous = next
    }

    temp = list->first;
    list->first = list->last;
    list->last = temp;
}

void printLinkedList(LinkedList* list) {
    LinkedListNode* node = list->first;
    while (node != NULL) {
        printf("%p\n", node->value);
        node = node->next;
    }
    printf("\n");
}

LinkedList* initLinkedListFromArray(void** array, int length) {
    LinkedList* list = initLinkedList();
    for (int i = 0; i < length; i++) { appendLinkedListElement(list, array[i]); }

    return list;
}
