#include <iostream>
#include <cstdio>
#include <cstdlib>

#include <getopt.h>

#include <ft2build.h>
#include FT_FREETYPE_H

int main(int argc, char **argv) {

    char *text_file_name;
    char *font_file_name;

    int c;

    while (1) {
        static struct option long_options[] = { { "font", required_argument,
                NULL, 'f' }, { "text", required_argument, NULL, 't' }, { NULL,
                0, NULL, 0 } };

        int option_index = 0;

        c = getopt_long(argc, argv, "f:t:", long_options, &option_index);

        if (c == -1) {
            break;
        }

        switch (c) {
        case 0:
            break;

        case 't':
            text_file_name = optarg;
            break;

        case 'f':
            font_file_name = optarg;
            break;

        case '?':
            /* getopt_long already printed an error message. */
            break;

        default:
            return 1;
        }
    }

    FT_Library library;
    FT_Face face;

    int error;

    error = FT_Init_FreeType(&library);
    if (error) {
        std::cerr << "font library init failed at " << __FILE__ << " "
                << __LINE__ << std::endl;
        return 1;
    }

    error = FT_New_Face(library, font_file_name, 0, &face);
    if (error == FT_Err_Unknown_File_Format) {
        std::cerr << "unknown font file format" << std::endl;
    } else if (error) {
        std::cerr << "error reading font file" << std::endl;
    }

    return 0;
}

