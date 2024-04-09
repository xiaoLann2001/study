// 通过 open 函数判断文件是否存在（例如 test_file），并将判断结果显示出来。

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define TEST_FILE "./test_file"

int main()
{
    int fd;
    int ret = 0;
    fd = open(TEST_FILE, O_RDONLY);
    if (-1 == fd)
    {
        ret = -1;
        printf("file is not found\n");
        goto out;
    }
    else
    {
        printf("have found\n");
    }
    
out:
    printf("this is out\n");
    return ret;
}