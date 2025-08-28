#include <stdio.h>

/**
 * @brief 打印原始数据
 * @param data 数据
 * @param length 数据长度
 */
static void raw_data_show(const char *data, int length)
{
    char line_buffer[128]; // 缓存一行输出

    for (int i = 0; i < length; i += 16)
    {
        int line_end = (i + 16 < length) ? (i + 16) : length;
        int pos = 0;

        // 格式化地址部分
        pos += snprintf(line_buffer + pos, sizeof(line_buffer) - pos, "%04x: ", i);

        // 格式化十六进制部分
        for (int j = i; j < i + 16; j++)
        {
            if (j < line_end)
            {
                pos += snprintf(line_buffer + pos, sizeof(line_buffer) - pos, "%02x ", (unsigned char)data[j]);
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

        // 格式化分隔符
        pos += snprintf(line_buffer + pos, sizeof(line_buffer) - pos, " |");

        // 格式化ASCII部分
        for (int j = i; j < line_end; j++)
        {
            char c = data[j];
            pos += snprintf(line_buffer + pos, sizeof(line_buffer) - pos, "%c", (c >= 32 && c <= 126) ? c : '.');
        }

        // 格式化结束符
        pos += snprintf(line_buffer + pos, sizeof(line_buffer) - pos, "|\n");

        // 一次性输出整行
        printf("%s", line_buffer);
    }
}
