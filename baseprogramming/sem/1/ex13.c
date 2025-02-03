#include <stdio.h>

int main() {
    double w, h;
    double desk_width = 1.20;
    double desk_length = 0.70;
    double corridor_width = 1.0;
    int desks_left, desks_right;
    int corridor_desks;
    int total_desks;
    int lost_desks = 3;

    printf("enter width of lab: ");
    scanf("%lf", &w);
    printf("enter length of lab: ");
    scanf("%lf", &h);

    desks_left = (int)((h - corridor_width) / desk_width);
    desks_right = (int)((h - corridor_width) / desk_width);

    corridor_desks = (int)(w / desk_length);

    total_desks = (desks_left + desks_right) + corridor_desks;

    printf("number of workspaces available in lab: %d\n", total_desks - lost_desks);

    return 0;
}
