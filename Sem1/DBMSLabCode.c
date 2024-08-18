#include <stdio.h>
#include <stdlib.h>
#define lower 1
#define upper 10

void input(int *a, int nor, int noc)
{
  int i, j;
  for (i = 0; i < nor; i++)
  {
    for (j = 0; j < noc; j++)
      *(a + i * noc + j) = (rand() % (upper - lower + 1)) + lower;
  }
}

void disp(int *a, int nor, int noc)
{
  int i, j;
  for (i = 0; i < nor; i++)
  {
    for (j = 0; j < noc; j++)
    {
      printf("%d\t", *(a + i * noc + j));
    }

    printf("\n");
  }
}

int uniq(int *a, int nor, int noc, int cn)
{
  int i, j, flag = 0;
  for (i = 0; i < nor; i++)
  {
    for (j = i + 1; j < nor; j++)
    {
      if (*(a + i * noc + cn) == *(a + j * noc + cn))
      {
        flag = 1;
        break;
      }
    }
  }
  return flag;
}

int same(int *a, int nor, int noc, int cn)
{
  int i, flag = 0;
  for (i = 1; i < nor; i++)
  {
    if (*(a + i * noc + cn) != *(a + (i - 1) * noc + cn))
    {
      flag = 1;
      break;
    }
  }
  return flag;
}

int fd(int *a, int nor, int noc, int cn, int cn1)
{
  int i, j, flag = 0;
  for (i = 0; i < nor; i++)
  {
    for (j = i + 1; j < nor; j++)
    {
      if (*(a + i * noc + cn) == *(a + j * noc + cn))
      {
        if (*(a + i * noc + cn1) != *(a + j * noc + cn1))
        {
          flag = 1;
          break;
        }
      }
    }
  }
  return flag;
}

int main()
{
  int nor, noc;
  printf("Enter nor and noc: ");
  scanf("%d%d", &nor, &noc);
  int a[nor][noc];
  char fn[noc];
  for (int i = 0; i < noc; i++)
  {
    fn[i] = 'A' + i;
  }
  input(*a, nor, noc);
  disp(*a, nor, noc);
  int cno, cno1;
  for (cno = 0; cno < noc; cno++)
  {
    for (cno1 = cno + 1; cno1 < noc; cno1++)
    {
      if (!uniq(*a, nor, noc, cno) || !same(*a, nor, noc, cno) || !fd(*a, nor, noc, cno, cno1))
      {
        printf("%c-->%c\n", fn[cno], fn[cno1]);
      }
    }
  }

  return 0;
}