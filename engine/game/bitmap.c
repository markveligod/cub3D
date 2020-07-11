#include "../../cub.h"

/*
** Functions for creating a title and label in a bmp file
** https://stackoverflow.com/questions/742236
*/

unsigned char	*create_file_header(int res_y, int res_x)
{
	int						nb_octet;
	static unsigned char	bmp_file_header[] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	};
	int						padding;

	padding = (4 - (res_x * 3) % 4) % 4;
	nb_octet = 14 + 40 + (3 * res_x + padding) * res_y;
	bmp_file_header[0] = (unsigned char)('B');
	bmp_file_header[1] = (unsigned char)('M');
	bmp_file_header[2] = (unsigned char)(nb_octet);
	bmp_file_header[3] = (unsigned char)(nb_octet >> 8);
	bmp_file_header[4] = (unsigned char)(nb_octet >> 16);
	bmp_file_header[5] = (unsigned char)(nb_octet >> 24);
	bmp_file_header[10] = (unsigned char)(54);
	return (bmp_file_header);
}

unsigned char	*create_bitmap_header(int res_y, int res_x)
{
	static unsigned char	bmp_bitmap_header[] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	};

	bmp_bitmap_header[0] = (unsigned char)(40);
	bmp_bitmap_header[4] = (unsigned char)(res_x);
	bmp_bitmap_header[5] = (unsigned char)(res_x >> 8);
	bmp_bitmap_header[6] = (unsigned char)(res_x >> 16);
	bmp_bitmap_header[7] = (unsigned char)(res_x >> 24);
	bmp_bitmap_header[8] = (unsigned char)(res_y);
	bmp_bitmap_header[9] = (unsigned char)(res_y >> 8);
	bmp_bitmap_header[10] = (unsigned char)(res_y >> 16);
	bmp_bitmap_header[11] = (unsigned char)(res_y >> 24);
	bmp_bitmap_header[12] = (unsigned char)(1);
	bmp_bitmap_header[14] = (unsigned char)(3 * 8);
	return (bmp_bitmap_header);
}
