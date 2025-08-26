#include <stdio.h>

/**
 * @brief 打印原始数据
 * @param data 数据
 * @param length 数据长度
 */
void raw_data_show(const char *data, int length)
{
    for (int i = 0; i < length; i += 16)
    {
        int line_end = (i + 16 < length) ? (i + 16) : length;
        printf("%04x: ", i);
        for (int j = i; j < i + 16; j++)
        {
            if (j < line_end)
            {
                printf("%02x ", data[j]);
            }
            else
            {
                printf("   ");
            }
            if (j == i + 7)
            {
                printf(" ");
            }
        }
        printf(" |");
        for (int j = i; j < line_end; j++)
        {
            char c = data[j];
            printf("%c", (c >= 32 && c <= 126) ? c : '.');
        }
        printf("|\n");
    }
}
