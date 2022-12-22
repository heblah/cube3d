#ifndef FT_CUBE3D_H
# define FT_CUBE3D_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

/* ./00_main.c ============================================================== */

/* ./01_window_management.c ================================================= */
int		open_window(t_data *data);
int		close_window(t_data *data);
t_data	*getdata(void);
int		init_data(t_data *data);

/* ./02_handle_events.c ===================================================== */
int		handle_keypress(int keysym, t_data *data);
int		handle_mouse(int keysym, int x, int y, t_data *data);
int		handle_nothing(void);

/* ./03_handle_img.c ======================================================== */
int		clear_window(t_data *data);
int		render(t_data *data);
int		img_pixel_put(t_img *img, int x2d, int y2d, t_data *data);
t_img	*new_img(t_data *data);
#endif
