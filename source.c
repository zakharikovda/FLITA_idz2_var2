#include <stdio.h>
#include <stdlib.h>

int main()
{
    int matrix[5][19];
    int i, j;
    FILE *file = fopen("input.txt", "r");
    if (!file)
        exit(EXIT_FAILURE);
    for (i = 0; i < 5 && !feof(file); i++)
    {
        for (j = 0; j < 19 && !feof(file); j++)
        {
            fscanf(file, "%d", &matrix[i][j]);
            printf("%d ", matrix[i][j]);
        }
        putchar('\n');
    }
    fclose(file);
    FILE *out;
    out = fopen("output.dot", "w");
    fprintf(out, "graph{\n");
    for (int i = 0; i < 5; i++)
    {
        for (int j = i; j < 19; j++)
        {
            if (matrix[i][j] == 1)
            fprintf(out, "\t%d -- %d\n", i, j);
        }
    }
    fprintf(out, "}\n");
    fclose(out);
    system("dot output.dot -Tpng -o image.png");
    return (EXIT_SUCCESS);
}