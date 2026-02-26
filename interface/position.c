#include "position.h"
#include "ui.h"

int *get_positions(int width, int lenght)
{
    int *coordinates = (int *)calloc(2, sizeof(int));

    coordinates[0] = ((max_y - 1) / 2) - (lenght / 2);
    coordinates[1] = ((max_x - 1) / 2) - (width / 2);

    return coordinates;
}

int get_position_y(int lenght)
{
    return ((max_y - 1) / 2) - (lenght / 2);
}

int get_position_x(int width)
{
    return ((max_x - 1) / 2) - (width / 2);
}