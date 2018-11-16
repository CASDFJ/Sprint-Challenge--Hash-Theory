#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  HashTable *ht = create_hash_table(16);

  // YOUR CODE HERE
  for (int i = 0; i < length; i++)
  {
    hash_table_insert(ht, weights[i], i);
  }

  for (int i = 0; i < length; i++)
  {
    int weight = weights[i];
    int match = limit - weight;
    int matchIndex = hash_table_retrieve(ht, match);

    if (matchIndex != -1)
    {
      Answer *answer = malloc(sizeof(Answer));

      int weightIndex = hash_table_retrieve(ht, weight);

      if (weight == match)
      {
        for (int i = 0; i < length; i++)
        {
          if (weights[i] == weight && i != matchIndex)
          {
            weightIndex = i;
          }
        }
      }

      if (weightIndex > matchIndex)
      {
        answer->index_1 = weightIndex;
        answer->index_2 = matchIndex;
      }
      else
      {
        answer->index_1 = matchIndex;
        answer->index_2 = weightIndex;
      }
      destroy_hash_table(ht);
      return answer;
    }
  }
  destroy_hash_table(ht);
  return NULL;
}

void print_answer(Answer *answer)
{
  if (answer != NULL)
  {
    printf("%d %d\n", answer->index_1, answer->index_2);
  }
  else
  {
    printf("NULL\n");
  }
}