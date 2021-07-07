#include <mlx.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.141592
#define WIDTH 1200
#define HEIGHT 1200
#define N_NUM 50
#define MAX_X 3.0
#define MAX_Y 3.0
#define DX 0.005
#define DY 0.005

#define COLOR_PURPLE 0x008B00FF
#define COLOR_BLACK 0x00000000

#define ESC 53
#define CLK_LEFT 1
#define CLK_RIGHT 2
#define ZOOM_IN 5
#define ZOOM_OUT 4

/* number data */
typedef struct s_complex
{
	double real;
	double imaginary;
} t_complex;

/* img data */
typedef struct s_img
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_img;

/* hooking data */
typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_img	img;
} t_vars;

/* init complex */
void init_complex(t_complex *i, double real, double imaginary)
{
	i->real = real;
	i->imaginary = imaginary;
}

/* complex pow */
t_complex pow_complex(t_complex i)
{
	t_complex rtn;

	rtn.real = pow(i.real, 2.0) - pow(i.imaginary, 2.0);
	rtn.imaginary = 2 * i.real * i.imaginary;
	return (rtn);
}

/* complex sum */
t_complex sum_complex(t_complex a, t_complex b)
{
	t_complex rtn;

	rtn.real = a.real + b.real;
	rtn.imaginary = a.imaginary + b.imaginary;
	return (rtn);
}

/* 복소수가 발산하는가? */
int isdvg_complex(t_complex i)
{
	if (pow(i.real, 2.0) + pow(i.imaginary, 2.0) > 4.0)
		return (1);
	else
		return (0);
}

/* detect key */
int key_hook(int keycode, t_vars *vars)
{
	/* esc : 53 */
	printf("Hello from key_hook! : %d\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(1);
	}
	return (0);
}

/* detect mouse click*/
int mouse_hook(int button, int x, int y, t_vars *vars)
{
	printf("Hello from mouse_hook! : %d %d %d\n", button, x, y);
	return (0);
}

/* easy pixel put function */
void my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/* put img */
/*
int main()
{
	void *mlx;
	void *mlx_win;
	t_data img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 640, 480, "Hello");
	img.img = mlx_new_image(mlx, 640, 480);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	for (int i = 0; i < 100; i++)
	{
		my_mlx_pixel_put(&img, i, i, 0x00FF0000);
		my_mlx_pixel_put(&img, 5, i, 0x0000FF00);
		my_mlx_pixel_put(&img, i, 5, 0x000000FF);
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
*/

/* hook : key detecting */
/*
int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	mlx_hook(vars.win, 4, 1L<<3, mouse_hook, &vars);
	//mlx_key_hook(vars.win, key_hook, &vars);
	//mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_loop(vars.mlx);
}
*/


/* 만델브롯 x,y,zoom 변수 */
void mandelbrot(t_img *img, double x, double y, double zoom)
{
	int cycle;
	double put_x;
	double put_y;
	t_complex zn;
	t_complex input;

	init_complex(&zn, 0, 0);
	init_complex(&input, x, y);
	cycle = N_NUM;
	while (cycle-- && !isdvg_complex(zn))
		zn = sum_complex(pow_complex(zn), input);
	put_x = (x + MAX_X) * (WIDTH / (MAX_X * 2));
	put_y = (y + MAX_Y) * (HEIGHT / (MAX_Y * 2));
	put_x = (WIDTH / 2) + (put_x - (WIDTH / 2)) * zoom;
	put_y = (HEIGHT / 2) + (put_y - (HEIGHT / 2)) * zoom;
	if (isdvg_complex(zn) && (put_x > 0) && (put_x < WIDTH) && (put_y > 0) && (put_y < HEIGHT))
		my_mlx_pixel_put(img, (int)put_x, (int)put_y, COLOR_PURPLE * (cycle * 7));
	else
		my_mlx_pixel_put(img, (int)put_x, (int)put_y, COLOR_BLACK);
}

/* 줄리아 x,y,zoom 변수, c는 특정 고정 타입 (마우스 클릭에 맞추어서 변수를 넣어줘야 할듯) */
void julia(t_img *img, double x, double y, double zoom)
{
	int cycle;
	double put_x;
	double put_y;
	t_complex zn;
	t_complex input;

	init_complex(&zn, x, y);
	init_complex(&input, -0.8, 0.156);
	cycle = N_NUM;
	while (cycle-- && !isdvg_complex(zn))
		zn = sum_complex(pow_complex(zn), input);
	put_x = (x + MAX_X) * (WIDTH / (MAX_X * 2));
	put_y = (y + MAX_Y) * (HEIGHT / (MAX_Y * 2));
	put_x = (WIDTH / 2) + (put_x - (WIDTH / 2)) * zoom;
	put_y = (HEIGHT / 2) + (put_y - (HEIGHT / 2)) * zoom;
	if (isdvg_complex(zn) && (put_x > 0) && (put_x < WIDTH) && (put_y > 0) && (put_y < HEIGHT))
		my_mlx_pixel_put(img, (int)put_x, (int)put_y, COLOR_PURPLE * (cycle * 7));
	else
		my_mlx_pixel_put(img, (int)put_x, (int)put_y, COLOR_BLACK);
}

/* 모든 정보를 한 개의 구조체에 담아서 인자로 보내버리자. 그럼 외부 입력에 대해서도 그림 변경 가능 */
int main(void)
{
	t_vars vars;
	t_img img;
	double zoom;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "Hello");
	img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	zoom = 1.5;
	for (double y = (MAX_Y / zoom); y > -(MAX_Y / zoom); y -= (DY / zoom))
	{
		for (double x = (MAX_X / zoom); x > -(MAX_X / zoom); x -= (DX / zoom))
		{
			julia(&img, x, y, zoom);
			//mandelbrot(&img, x, y, zoom);
		}
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
}
