/*
 * @file    raw_data_show.c
 * @author  Pointspread Team
 * @date    2025-08-29
 * @brief   print raw data in hex format
 * @output_style:
 *      ===== data_name =====
 *      0x0000: 00 01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0f |................|
 *      0x0010: 10 11 12 13 14 15 16 17 18 19 1a 1b 1c 1d 1e 1f |................|
 *      0x0020: 20 21 22 23 24 25 26 27 28 29 2a 2b 2c 2d 2e 2f | !"#$%&'()*+,-./|
 *      0x0030: 30 31 32 33 34 35 36 37 38 39 3a 3b 3c 3d 3e 3f |0123456789:;<=>?|
 *      0x0040: 40 41 42 43 44 45 46 47 48 49 4a 4b 4c 4d 4e 4f |@ABCDEFGHIJKLMNO|
 *      0x0050: 50 51 52 53 54 55 56 57 58 59 5a 5b 5c 5d 5e 5f |PQRSTUVWXYZ[\]^_|
 *      0x0060: 60 61 62 63 64 65 66 67 68 69 6a 6b 6c 6d 6e 6f |`abcdefghijklmno|
 *      0x0070: 70 71 72 73 74 75 76 77 78 79 7a 7b 7c 7d 7e 7f |pqrstuvwxyz{|}~|
 *      0x0080: 80 81 82 83 84 85 86 87 88 89 8a 8b 8c 8d 8e 8f |................|
 *      0x0090: 90 91 92 93 94 95 96 97 98 99 9a 9b 9c 9d 9e 9f |................|
 * Copyright (c) 2025 pointspread. All rights reserved.
 */
#include <stdio.h>
#include <stdint.h>

/**
 * @brief Print raw data in hexadecimal format with ASCII representation
 * @param data Pointer to the raw data buffer
 * @param length Length of the data buffer in bytes
 * @param data_name Name/description of the data being displayed
 */
static void raw_data_show(const char *data, uint32_t length, const char *data_name)
{
#define MAX_LINE_LENGTH 128
#define SHOW_INTERFACE  printf
#define FILETE_LENGTH   MAX_LINE_LENGTH

    char line_buffer[MAX_LINE_LENGTH];
    SHOW_INTERFACE("[%s] %d bytes\r\n", data_name, length);

    if (length > FILETE_LENGTH) // too long, skip
    {
        return;
    }

    for (int i = 0; i < length; i += 16)
    {
        // step 1: set line_end
        uint32_t line_end = (i + 16 < length) ? (i + 16) : length;
        uint32_t pos = 0;

        // step 2: format address portion
        pos += snprintf(line_buffer + pos, sizeof(line_buffer) - pos, "%04x: ", i);

        // step 3: format hexadecimal portion
        for (uint32_t j = i; j < i + 16; j++)
        {
            if (j < line_end)
            {
                pos += snprintf(line_buffer + pos, sizeof(line_buffer) - pos, "%02x ",
                                (unsigned char)data[j]);
            }
            else
            {
                pos += snprintf(line_buffer + pos, sizeof(line_buffer) - pos, "   ");
            }
            if (j == i + 7)
            {
                pos += snprintf(line_buffer + pos, sizeof(line_buffer) - pos, " ");
            }
        }

        // step 4: format separator
        pos += snprintf(line_buffer + pos, sizeof(line_buffer) - pos, " |");

        // step 5: format ASCII portion
        for (uint32_t j = i; j < line_end; j++)
        {
            char c = data[j];
            pos += snprintf(line_buffer + pos, sizeof(line_buffer) - pos, "%c",
                            (c >= 32 && c <= 126) ? c : '.');
        }

        // step 6: format line ending
        pos += snprintf(line_buffer + pos, sizeof(line_buffer) - pos, "|\n");

        // step 7: output complete line at once
        SHOW_INTERFACE("%s", line_buffer);
    }
}