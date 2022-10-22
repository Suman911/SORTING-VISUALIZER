#define global_variable static
#define internal static


typedef char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef long long s64;
typedef unsigned long long u64;

#define swap(a, b)\
int temp = a;\
a = b;\
b = temp;\
d(2);

void d(int n)
{
    clock_t t = clock();
    while (clock() < t + n)
        ;
}

//game loop
global_variable bool running = true;

//screen
struct Render_State 
{
	int height, width;
	void* screen;

	BITMAPINFO bitmap_info;
};
global_variable Render_State render_state;

//importent for render SCREEN
HDC hdc;
void get_dc(HWND window)
{
	hdc = GetDC(window);
}

//array needed in sorting
int* s_ort;
int width;
int height;
int ratio;

//array for animation
struct ANIMATION
{
	int* a;
	int w;
	int h;
};
global_variable ANIMATION animation;

int col[200];
int part(int low, int high, int cmplt)
{
	int pivot = animation.a[high];
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++)
	{
		if (animation.a[j] < pivot) {
			i++;
			int temp = animation.a[i];
				animation.a[i] = animation.a[j];
				animation.a[j] = temp;
				temp = col[i];
				col[i] = col[j];
				col[j] = temp;
		}
	}
	int temp = animation.a[i + cmplt];
	animation.a[i + cmplt] = animation.a[high];
	animation.a[high] = temp;
	temp = col[i + cmplt];
	col[i + cmplt] = col[high];
	col[high] = temp;
	return (i + 1);
}
void qsort(int low, int high, int cmplt = 1)
{
	if (low < high) {
		int pi = part(low, high, cmplt);
		qsort(low, pi - 1, cmplt);
		qsort(pi + 1, high, cmplt);
	}
}


//BUTTONS
struct Button_State 
{
	bool is_down;
	bool changed;
};

enum 
{
	BUTTON_UP,
	BUTTON_DOWN,
	BUTTON_ENTER,

	BUTTON_COUNT, // Should be the last item
};

struct Input 
{
	Button_State buttons[BUTTON_COUNT];
};
Input input = {};

#define is_down(b) input.buttons[b].is_down
#define pressed(b) (input.buttons[b].is_down && input.buttons[b].changed)
#define released(b) (!input.buttons[b].is_down && input.buttons[b].changed)

clock_t button_pressed = clock(), laps_c = clock(), laps_s = clock(), hlod_duration = clock();