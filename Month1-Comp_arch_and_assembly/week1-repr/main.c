#define _GNU_SOURCE
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Add function prototypes
char *int32_to_bin (int32_t x, char out[35]);
char *int32_to_bin2 (int32_t x, char out[35]);

// interestingly, bin 2 is 5% faster than bin 1

// random ints for benchmarking
int32_t random_ints[10000000];

char *
int32_to_bin (int32_t x, char out[35])
{
  for (int i = 34; i >= 0; i--)
    {
      if (i == 26 || i == 18 || i == 10)
        {
          out[i] = ' ';
        }
      else
        {
          out[i] = (x & 1) ? '1' : '0';
          x >>= 1;
        }
    }
  return out;
}

char *
int32_to_bin2 (int32_t x, char out[35])
{
  for (int i = 34; i >= 0; i--)
    {
      if (i == 26 || i == 18 || i == 10)
        {
          out[i] = ' ';
        }
      else
        {
          out[i] = (x & 1) + '0';
          x >>= 1;
        }
    }
  return out;
}

int
main (void)
{
  struct timespec start, end;
  long time_taken_ms;
  char out[35];

  // seed RNG and populate random_ints
  srand ((unsigned)time (NULL));
  for (int i = 0; i < 10000000; i++)
    {
      random_ints[i] = rand ();
    }

  // benchmark int32_to_bin2
  clock_gettime (CLOCK_MONOTONIC, &start);
  for (int i = 0; i < 10000000; i++)
    {
      int32_to_bin2 (random_ints[i], out);
    }
  clock_gettime (CLOCK_MONOTONIC, &end);
  time_taken_ms = (end.tv_sec - start.tv_sec) * 1000
                  + (end.tv_nsec - start.tv_nsec) / 1000000;
  printf ("Time taken by int32_to_bin: %ld ms\n", time_taken_ms);

  // benchmark int32_to_bin
  clock_gettime (CLOCK_MONOTONIC, &start);
  for (int i = 0; i < 10000000; i++)
    {
      int32_to_bin (random_ints[i], out);
    }
  clock_gettime (CLOCK_MONOTONIC, &end);
  time_taken_ms = (end.tv_sec - start.tv_sec) * 1000
                  + (end.tv_nsec - start.tv_nsec) / 1000000;
  printf ("Time taken by int32_to_bin2: %ld ms\n", time_taken_ms);

  return 0;
}
