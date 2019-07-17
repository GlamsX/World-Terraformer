/**
 * @Author: la-montagne
 * @Date:   2019-07-17T14:24:39+02:00
 * @Last modified by:   la-montagne
 * @Last modified time: 2019-07-17T14:26:54+02:00
 */

#include <math.h>
#include <time.h>
#include <sys/types.h>
#include <SFML/Window/Mouse.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <features.h>
#include <unistd.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/System/Vector2.h>
#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/Sound.h>
#include <fcntl.h>
#define WIDTH 1920
#define HEIGHT 1029
#define BIT_PIXEL 32
#define eve sfRenderWindow_pollEvent
#define PI 3.1415926535897932384626433832795028841972

typedef struct text_s
{
    sfFont *font;
    sfText *help;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f vector;
} text_t;

typedef struct global_s
{
    sfRenderWindow *window;
    sfEvent event;
    int event_val;
    text_t text;
    sfVector2u vec;
} global_t;

typedef struct object_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f vector;
    sfIntRect but_coord;
    int type;
} object_t;

typedef struct mod_s
{
    int doted;
    int pincase;
    int options;
    int brush;
    sfCircleShape *cir;
    int help;
} mod_t;

typedef struct rotate_s
{
    int rot_x;
    int rot_y;
    int rot_z;
} rotate_t;

typedef struct map_s
{
    int **mapz;
    sfVector2f **map;
    int rx;
    int ry;
    int rz;
    float shade;
    sfVector3f vthf;
    int zoom;
    int zoomer;
    int unzoomer;
    int updown;
    int rightleft;
    int posx;
    int posy;
    int mapX;
    int mapY;
    sfVector2i mouse;
    int adj;
    int opp;
    mod_t mod;
    rotate_t rot;
} map_t;

int text_to_int_arr(char *filemap, map_t *maps);
int error_file(FILE *fp, char *file);

global_t init_gbl(sfVideoMode mode);
map_t init_maps(int ac, char **av);
object_t *init_button(char *path, sfVector2f vector, sfIntRect rec, int type);
void init_button_tab(object_t **button);

void init_mapz(map_t *maps);
void randomize_map_borders(map_t *maps);
void randomize_map_insides(map_t *maps);
void detect_nearest(map_t *maps, int tril, int ret);
void detect_real_nearest(map_t *maps, int tril, int ret, int x);
void detect_case(map_t *maps, sfVector2f **map, int tril, int ret);
sfColor choose_color(int h, float sh);
void modify_map(map_t *maps);

float ct_rad(int deg);
float norm_vector(float x, float y, float z);
float get_shader(int x, int y, map_t *maps);
int rand_scale(void);
char *my_revstr(char *str);
int my_getnbr(char const *str);
char **my_str_to_word_array(char const *str, char sep);
int my_strcmp(char *str1, char *str2);

void draw_help_window(global_t *gbl, map_t *maps);
sfVector3f get_xyz_p(int x, int y, int z, map_t *maps);
sfVector2f project_iso_point(int x, int y, int z, map_t *maps);
void create_twod_map(map_t *maps);
void get_threed_coords(float ax, float ay, float az, map_t *maps);
void draw_button(global_t *gbl, object_t *button[], \
int nb_sprite, map_t *maps);
void draw_twod_map(global_t *gbl, map_t *maps);
void draw_ninety_deg(sfRenderWindow *window, map_t *maps);
void draw_h_eighty_deg(sfRenderWindow *window, map_t *maps);
void draw_twoh_seventy_deg(sfRenderWindow *window, map_t *maps);
void draw_zero_deg(sfRenderWindow *window, map_t *maps);
void draw_twod_sides(sfRenderWindow *window, map_t *maps);
void draw_all(sfRenderWindow *window, map_t *maps, int x, int y);

int **int_tab_realloc(int **tab, int size_of_tab, int size_to_add);
int *int_realloc(int *tab, int size_of_tab, int size_to_add);
int **int_tab_unrealloc(int **tab, int size_of_tab, int to_sub);
int *int_unrealloc(int *tab, int size_of_tab, int to_sub);
int *full_with_zero(int size_of_tab, int size_to_add);

sfVertexArray *create_square(sfVector2f *v, int highness, float shade);
sfVertexArray *create_base(map_t *maps);
sfVertexArray *create_line(sfVector2f a, sfVector2f b, \
sfVector2f c, sfVector2f d);
sfVertexArray *create_sidex(map_t *maps, int x, int y);
sfVertexArray *create_sidey(map_t *maps, int x, int y);

int event_close(global_t *gbl, map_t *maps);
int event_zoom(global_t *gbl, map_t *maps);
int event_moves(global_t *gbl, map_t *maps);
int event_mouse(global_t *gbl, map_t *maps);
int event_reset(global_t *gbl, map_t *maps);
void reset_altitude(map_t *maps);
void event_button(global_t *gbl, map_t *maps, object_t **button);
void select_button_a(int idx, map_t *maps, object_t *button);
void select_button_b(int idx, map_t *maps, object_t *button);
void event_rot(global_t *gbl, map_t *maps);
void seeable_button(object_t *button[]);
void unseeable_button(object_t *button[]);
void rand_map_real_insides(map_t *maps, int x, int y);
void draw_annex(sfRenderWindow *window, map_t *maps, int x, int y);

void free_struct(object_t **button, map_t *maps);
int close_before(FILE *fp, char *str);
