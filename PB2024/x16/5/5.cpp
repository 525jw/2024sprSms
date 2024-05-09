#include <stdio.h>

typedef struct _coord coord_t;

struct _coord {
    int x;
    int y;
};

int farpoints(int n, coord_t *p, coord_t **r, coord_t **s){
    int d=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int newd=(p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y);
            if(newd>d){
                d=newd;
                *r=&p[i];
                *s=&p[j];
            }
        }
    }
    return d;
}

int main()
{
    int n;
    scanf("%d", &n);
    coord_t point[100];
    for (int i = 0; i < n; i++)
        scanf("%d %d", &point[i].x, &point[i].y);
    coord_t *u, *v;
    int sqrdist = farpoints(n, point, &u, &v);
    printf("sqrt(%d)\n", sqrdist);
    printf("%d %d\n", u->x, u->y);
    printf("%d %d\n", v->x, v->y);
}