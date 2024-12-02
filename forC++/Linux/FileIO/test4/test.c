// 打开一个已经存在的文件（例如 test_file），通过 lseek 函数计算该文件的大小，并打印出来。

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define TEST_FILE "./test_file"

int main()
{
    int fd;
    int ret = 0;
    off_t start, end;
    fd = open(TEST_FILE, O_RDONLY);
    if (-1 == fd)
    {
        ret = -1;
        printf("open failed\n");
        goto out;
    }
    printf("open successfully\n");

    start = lseek(fd, 0, SEEK_SET);
    end = lseek(fd, 0, SEEK_END);

    printf("total: %d\n", (int)(end - start));
    
out:
    printf("this is out\n");
    return ret;
}