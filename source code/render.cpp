void clear_screen()
{
	unsigned int* pixel = (u32*)render_state.screen;
	for (int y = 0; y < render_state.height; y++) {
		for (int x = 0; x < render_state.width; x++) {
			*pixel++ = 0x1e21f2;
		}
	}
}

void draw_arry()
{
	for (int i = 0; i < width; i++)
	{
		for (int y = 10; y < render_state.height; y++) {
			unsigned int* pixel = (u32*)render_state.screen + i * ratio + y * render_state.width;
			for (int x = 0; x < ratio ; x++) {
				if(y < (10 + s_ort[i]))
				*pixel++ = 0xff5500;
				else
				*pixel++ = 0x1e21f2;
			}
		}
	}
	StretchDIBits(hdc, 0, 0, render_state.width, render_state.height, 0, 0, render_state.width, render_state.height, render_state.screen, &render_state.bitmap_info, DIB_RGB_COLORS, SRCCOPY);
}

void draw_element(int i, u32 color = 0x80ff00, bool render = true)
{
	for (int y = 10; y < render_state.height; y++) {
		unsigned int* pixel = (u32*)render_state.screen + i * ratio + y * render_state.width;
		for (int x = 0; x < ratio; x++) {
			if (y < (10 + s_ort[i]))
				*pixel++ = color;
			else
				*pixel++ = 0x1e21f2;
		}
	}
	if(render)
	StretchDIBits(hdc, 0, 0, render_state.width, render_state.height, 0, 0, render_state.width, render_state.height, render_state.screen, &render_state.bitmap_info, DIB_RGB_COLORS, SRCCOPY);
}

void draw_rect(const int X, const int Y, const int height, const int width, u32 color)
{
	for (int y = Y; y < Y + height; y++) {
		unsigned int* pixel = (u32*)render_state.screen + X + y * render_state.width;
		for (int x = 0; x < width; x++) {
				*pixel++ = color;
		}
	}
}

const char* letters[][7] = {
	" 000",
	"0  0",
	"0  0",
	"0000",
	"0  0",
	"0  0",
	"0  0",

	"000 ",
	"0  0",
	"0  0",
	"000",
	"0  0",
	"0  0",
	"000",

	" 000",
	"0",
	"0",
	"0",
	"0",
	"0",
	" 000",

	"000",
	"0  0",
	"0  0",
	"0  0",
	"0  0",
	"0  0",
	"000",

	"0000",
	"0",
	"0",
	"000",
	"0",
	"0",
	"0000",

	"0000",
	"0",
	"0",
	"000",
	"0",
	"0",
	"0",

	" 000",
	"0",
	"0",
	"0 00",
	"0  0",
	"0  0",
	" 000",

	"0  0",
	"0  0",
	"0  0",
	"0000",
	"0  0",
	"0  0",
	"0  0",

	"000",
	" 0",
	" 0",
	" 0",
	" 0",
	" 0",
	"000",

	" 000",
	"   0",
	"   0",
	"   0",
	"0  0",
	"0  0",
	" 000",

	"0  0",
	"0  0",
	"0 0",
	"00",
	"0 0",
	"0  0",
	"0  0",

	"0",
	"0",
	"0",
	"0",
	"0",
	"0",
	"0000",

	"00 00",
	"0 0 0",
	"0 0 0",
	"0   0",
	"0   0",
	"0   0",
	"0   0",

	"00  0",
	"0 0 0",
	"0 0 0",
	"0 0 0",
	"0 0 0",
	"0 0 0",
	"0  00",

	"0000",
	"0  0",
	"0  0",
	"0  0",
	"0  0",
	"0  0",
	"0000",

	" 000",
	"0  0",
	"0  0",
	"000",
	"0",
	"0",
	"0",

	" 000 ",
	"0   0",
	"0   0",
	"0   0",
	"0 0 0",
	"0  0 ",
	" 00 0",

	"000",
	"0  0",
	"0  0",
	"000",
	"0  0",
	"0  0",
	"0  0",

	" 000",
	"0",
	"0 ",
	" 00",
	"   0",
	"   0",
	"000 ",

	"000",
	" 0",
	" 0",
	" 0",
	" 0",
	" 0",
	" 0",

	"0  0",
	"0  0",
	"0  0",
	"0  0",
	"0  0",
	"0  0",
	" 00",

	"0   0",
	"0   0",
	"0   0",
	"0   0",
	"0   0",
	" 0 0",
	"  0",

	"0   0",
	"0   0",
	"0   0",
	"0 0 0",
	"0 0 0",
	"0 0 0",
	" 0 0 ",

	"0   0",
	"0   0",
	" 0 0",
	"  0",
	" 0 0",
	"0   0",
	"0   0",

	"0   0",
	"0   0",
	" 0 0",
	"  0",
	"  0",
	"  0",
	"  0",

	"0000",
	"   0",
	"  0",
	" 0",
	"0",
	"0",
	"0000",
};

void draw_text(const char* text, int X, int Y, u32 size, u32 color)
{
	int original_y = Y;
	int original_x = X;
	int space;

	while (*text) 
	{
		if (*text != ' ')
		{
			const char** letter;

			letter = letters[*text - 'A'];
			space = 0;

			for (int i = 6; i >= 0; i--)
			{
				const char* row = letter[i];
				space = strlen(row) > space ? strlen(row) : space;
				while (*row) {
					if (*row == '0') {
						draw_rect(X, Y, size, size, color);
					}
					X += size;
					row++;
				}
				Y += size;
				X = original_x;
			}
		}
		else
		{
			space = 4;
		}
		X += size * (space + 1);
		original_x = X;
		Y = original_y;
		text++;
	}
}


bool hold = true, done = false, first = true;
void ANIMATION()
{
	int X = render_state.width - 500, Y = render_state.height - 600;
	if (hlod_duration > (laps_c + 1500) || first)
	{
		laps_c = clock();
		animation.w = 200;
		animation.h = 400;
		animation.a = new int[animation.w];
		animation.a[0] = rand();
		for (int i = 0; i < animation.w; i++)
		{
			animation.a[i] = (rand()) % animation.h + 5;
			col[i] = 0x5eff00 + animation.a[i]*.5;
		}
		hold = false;
		first = false;
	}
	if (hlod_duration > (laps_c + 500) && !hold)
	{
		laps_s = clock();
		qsort(0, animation.w - 1, 0);
		hold = true;
		done = true;
	}
	if (hlod_duration > (laps_c + 1000) && done)
	{
		laps_s = clock();
		qsort(0, animation.w - 1);
		done = false;
	}

	for (int i = 0; i < animation.w; i++)
	{
		for (int y = Y; y < animation.h + Y; y++) {
			unsigned int* pixel = (u32*)render_state.screen + i * 2 + X + y * render_state.width;
			for (int x = 0; x < 2; x++)
			{
				if (y < (Y + animation.a[i]))
					*pixel++ = col[i];
				else
					*pixel++ = 0x160086;
			}
		}
	}
}