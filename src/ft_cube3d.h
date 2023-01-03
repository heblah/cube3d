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

/* ./utils/00_garbage_memory.c ============================================== */
void	*free_label(t_garbage *garbage, t_label label);
void	*free_adr(t_garbage *garbage, void *adr);
void	*purge_garbage(t_garbage *garbage);
void	*add_garbage(t_data *data, size_t size, void *adr, t_label label);
void	*memg(t_memt type, size_t size, void *adr, t_label label);
#endif
