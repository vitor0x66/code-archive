#include <stdio.h>
#include <string.h>

int main(){
    int cols, rows, i, j, k = 0;
    scanf("P3 %d %d 255", &rows, &cols);
    int color_matrix[rows][cols];
    int r;
    int g;
    int b;

    char color_names[5][11];
    strcpy(color_names[0], "0 0 0");
    strcpy(color_names[1], "255 0 0");
    strcpy(color_names[2], "0 255 0");
    strcpy(color_names[3], "0 0 255");
    strcpy(color_names[4], "255 255 0");

    for (i = 0; i < rows; i++){
        for (j = 0; j < cols; j++){
            scanf("%d %d %d ", &r, &g, &b);
            if (r == 0 && g == 0 && b == 0)
                color_matrix[i][j] = 0;
            if (r == 255 && g == 0 && b == 0)
                color_matrix[i][j] = 1;
            if (r == 0 && g == 255 && b == 0)
                color_matrix[i][j] = 2;
            if (r == 0 && g == 0 && b == 255)
                color_matrix[i][j] = 3;
            if (r == 255 && g == 255 && b == 0)
                color_matrix[i][j] = 4;
        }
    }

    int count_matrix[rows][5];
    for (i = 0; i < rows; i++){
        for (j = 0; j < 5; j++)
            count_matrix[i][j] = 0;
    }

    for (i = 0; i < rows; i++){
        for (j = 0; j < cols; j++){
            k = 0;
            while (1){
                if (color_matrix[i][j] == k){
                    count_matrix[i][k]++;
                    break;
                }
                else
                    k++;
            }
        }
    }

    for (i = 0; i < rows; i++){
        for (j = 0; j < 5; j++)
            printf("%d ", count_matrix[i][j]);
        printf("\n");
    }

    int sum_colors[5] = {0};

    for (j = 0; j < 5; j++){
        for (i = 0; i < rows; i++)
            sum_colors[j] += count_matrix[i][j];
    }

    int major_color, tie[5] = {0};

    for (i = 0, k = 0; i < 5; i++){
        if (k < sum_colors[i]){
            major_color = i;
            k = sum_colors[i];
        }
    }

    for (i = 0; i < 5; i++){
        if (k == sum_colors[i])
            tie[i] = 1;
    }
    k = 0;
    for (i = 0; i < 5; i++)
        k += tie[i];

    if (k == 1){
        for (i = 0; i < rows; i++){
            for (j = 0; j < cols; j++){
                if (color_matrix[i][j] == major_color)
                    printf("0 0 0 ");
                else
                    printf("255 255 255 ");
            }
            printf("\n");
        }
    }
    if (k > 1){
        for (i = 0; i < rows; i++){
            for (j = 0; j < cols; j++){
                if (tie[color_matrix[i][j]] == 1)
                    printf("%s ", color_names[color_matrix[i][j]]);
                else
                    printf("255 255 255 ");
            }
            printf("\n");
        }
    }

    return 0;
}
