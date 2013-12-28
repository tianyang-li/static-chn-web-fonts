#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <fstream>

#include <getopt.h>

#include <ft2build.h>
#include FT_FREETYPE_H

#include "unicode/unistr.h"
#include "unicode/ustream.h"

int main(int argc, char **argv) {

    char *text_file_name = NULL;
    char *font_file_name = NULL;

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

    if (font_file_name == NULL) {
        std::cerr << "No font file!" << std::endl;
        return 1;
    }

    if (text_file_name == NULL) {
        std::cerr << "No text file!" << std::endl;
        return 1;
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
    } else {
        if (error) {
            std::cerr << "error reading font file" << std::endl;
        }
    }

    std::ifstream text_file(text_file_name, std::ios::binary);

    std::vector<char> text_file_data_vector;

    while (text_file.good()) {
        char c = text_file.get();
        if (text_file.good()) {
            text_file_data_vector.push_back(c);
        }
    }
    text_file.close();

    char *text_file_data_char = new char[text_file_data_vector.size() + 1];
    text_file_data_char[text_file_data_vector.size()] = '\0';

    for (int i = 0; i != int(text_file_data_vector.size()); ++i) {
        text_file_data_char[i] = text_file_data_vector[i];
    }

    icu::UnicodeString text_file_data = icu::UnicodeString::fromUTF8(
            text_file_data_char);

    delete[] text_file_data_char;

    std::cout << text_file_data;

    return 0;
}

