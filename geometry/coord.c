#include <stdio.h>
#include <math.h>

typedef struct 
{
    double x;
    double y;
} coord_t;

typedef struct 
{
    coord_t rotAt;
    double theta;
    double ofs_x;
    double ofs_y;
} config_t;

typedef coord_t (*converter_t)(coord_t);

coord_t trans(double dx, double dy, coord_t coord){
    coord_t result=coord;
    result.x +=dx;
    result.y +=dy;
    return result;
}

coord_t rotate(double theta, coord_t coord){
    coord_t result = {0,0};
    result.x=cos(theta) * coord.x - sin(theta) * coord.y;
    result.y=sin(theta) * coord.x + cos(theta) * coord.y;
    return result;
}

coord_t trans_by_config(config_t config, coord_t coord){
    return trans(config.ofs_x,config.ofs_y, coord);
}

coord_t rotate_by_config(config_t config, coord_t coord){
    coord_t pre_trans = trans(-config.rotAt.x,-config.rotAt.y, coord);
    coord_t rotated = rotate(config.theta, pre_trans);
    coord_t post_trans =  trans(config.rotAt.x,config.rotAt.y,rotated);
    return post_trans;
}

coord_t convert_by_config(config_t config, coord_t coord){
    return trans_by_config(config, rotate_by_config(config, coord));
}

void map_to_coords(converter_t conv, size_t n, coord_t* in_coord, coord_t* out_coord){
    unsigned int i = 0;
    for (i=0;i<n;i++) out_coord[i] = conv(in_coord[i]);
}

int main(){
    config_t config = { {0.5,0.5}, 3.141592653589793/4,-0.5,-0.5};
    coord_t unit_rect[] = {{0,0},{0,1},{1,1},{1,0}};
    coord_t converted_rect[] = {{0,0}, {0,0}, {0,0},{0,0}};
    {
        unsigned int i=0;
        for (i=0;i<sizeof(unit_rect)/sizeof(unit_rect[0]);i++){
            converted_rect[i]=convert_by_config(config,unit_rect[i]);
        }
    }

    {
        unsigned int i=0;
        for (i=0; i<sizeof(unit_rect)/sizeof(unit_rect[0]);i++){
            printf("(%.6f,%.6f\n",converted_rect[i].x,converted_rect[i].y);
        }
    }
    return 0;
}
