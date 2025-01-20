#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current = *head;
    unsigned int count = 0;

    if (head == NULL || *head == NULL)
        return (-1);

    while (current != NULL && count < index)
    {
        current = current->next;
        count++;
    }

    if (current == NULL)
        return (-1);

    // Suppression du premier élément
    if (current == *head)
    {
        *head = current->next;
        if (*head != NULL)
            (*head)->prev = NULL;
    }
    else
    {
        // Suppression d'un élément intermédiaire ou du dernier élément
        if (current->prev != NULL)
            current->prev->next = current->next;
        if (current->next != NULL)
            current->next->prev = current->prev;
    }

    free(current);

    // Vérification si la liste est vide après suppression
    if (*head == NULL)
        *head = NULL;

    return (1);
}
