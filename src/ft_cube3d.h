#ifndef FT_CUBE3D_H
# define FT_CUBE3D_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

/* ./handle_minilibx/00_handle_window.c ===================================== */
int		open_window(t_data *data);
int		close_window(t_data *data);

/* ./handle_minilibx/01_handle_events.c ===================================== */
int		handle_keypress(int keysym, t_data *data);
int		handle_mouse(int keysym, int x, int y, t_data *data);
int		handle_nothing(void);

/* ./handle_minilibx/02_handle_img.c ======================================== */
int		clear_window(t_data *data __attribute__((unused)));
int		render(t_data *data);
int		img_pixel_put(t_img *img, int x2d, int y2d, t_data *data);
t_img	*new_img(t_data *data);

/* ./main/00_main.c ========================================================= */
t_data	*getdata(void);
t_data	*initdata(void);

/* ./matrix/00_matrix_utils.c =============================================== */
t_matrix	*m_sum(t_matrix *a, t_matrix *b, int flag);
t_matrix	*m_prod(t_matrix *a, t_matrix *b, int flag);
t_matrix	*new_matrix(int row, int col);
t_matrix	*free_matrix(t_matrix *m);
void	free_tab(int **tab);

/* ./parsing/00_parser.c ==================================================== */
char	*get_texture(char *path);
t_color	getcolor(char *color_txt);
int		parser(t_data *data, char *path2map);

/* ./parsing/01_parser.c ==================================================== */
char	*rm_nl(char *gnl);
void	getmapdata(t_data *data, char *gnl);
int		convertmap(t_data *data, t_list	*maptmp);

/* ./parsing/02_parser.c ==================================================== */
t_bool	checkparsing(t_data *data);

/* ./raycasting/ray.c ======================================================= */
void	img_pix_put(t_img *img, int x, int y, int color);
void	draw_filled_square(t_img *img, int x, int y, int size, int color);
void	render_background(t_img *img, int color);
void	print_map(t_data *data);

/* ./utils/00_garbage_memory.c ============================================== */
void	*free_label(t_garbage *garbage, t_label label);
void	*free_adr(t_garbage *garbage, void *adr);
void	*purge_garbage(t_garbage *garbage);
void	*add_garbage(t_data *data, size_t size, void *adr, t_label label);
void	*memg(t_memt type, size_t size, void *adr, t_label label);

/* ./utils/01_list.c ======================================================== */
t_list	*list_addback(t_list **first, char *newdata);
size_t	listlen(t_list *first);
#endif
