#include <stdio.h>

int main() {
    int square_size, bench_width, bench_length;
    int tile_width, tile_length;
    double tile_area, bench_area, total_area, tile_count, time_needed;

    printf("enter the size of the square in meters: ");
    scanf("%d", &square_size);

    printf("enter the width of the bench in meters: ");
    scanf("%d", &bench_width);

    printf("enter the length of the bench in meters: ");
    scanf("%d", &bench_length);

    printf("enter the width of the tile in meters: ");
    scanf("%d", &tile_width);

    printf("enter the length of the tile in meters: ");
    scanf("%d", &tile_length);

    tile_area = W * L;
    bench_area = M * O;
    total_area = N * N - bench_area;
    tile_count = total_area / tile_area;
    time_needed = tile_count * 0.2;

    printf("total number of tiles needed: %.2lf\n", tile_count);
    printf("time needed for laying all the tiles: %.2lf minutes\n", time_needed);

    return 0;
}
