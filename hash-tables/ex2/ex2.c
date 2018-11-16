#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "ex2.h"

char **reconstruct_trip(Ticket **tickets, int length)
{
  HashTable *hash = create_hash_table(16);
  char **route = malloc(length * sizeof(char *));

  // YOUR CODE HERE
  char *original;

  for (int i = 0; i < length; i++)
  {
    if (strcmp(tickets[i]->source, "NONE") == 0)
    {
      original = strdup(tickets[i]->destination);
      route[0] = original;
    }
    else
    {
      hash_table_insert(hash, tickets[i]->source, tickets[i]->destination);
    }
  }

  int i = 1;

  char *target_destination = hash_table_retrieve(hash, original);

  while (strcmp(target_destination, "NONE") != 0)
  {
    route[i] = target_destination;
    target_destination = hash_table_retrieve(hash, target_destination);
    i++;
  }
  route[i] = target_destination;
  destroy_hash_table(hash);
  return route;
}

void print_route(char **route, int length)
{
  for (int i = 0; i < length; i++)
  {
    printf("%s\n", route[i]);
  }
}