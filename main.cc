#include <iostream>
#include <cstdio>
#include <cstdlib>

#include <getopt.h>

#include <ft2build.h>
#include FT_FREETYPE_H

int main(int argc, char **argv) {

    int c;

    char *text_file_name;
    char *font_file_name;

    while (1) {
        static struct option long_options[] = { { "font", required_argument,
                NULL, 'f' }, { "text", required_argument, NULL, 't' }, { 0, 0,
                0, 0 } };

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

    return 0;
}

