// 通过 open 函数判断文件是否存在（例如 test_file），并将判断结果显示出来。

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define NEW_FILE "./new_file"

int main()
{
    int fd;
    char buf[1024];
    int ret = 0;
    fd = open(NEW_FILE, O_WRONLY | O_CREAT | O_EXCL, 
                        S_IRWXU | S_IRGRP | S_IROTH);
    if (-1 == fd)
    {
        ret = -1;
        printf("create failed\n");
        goto out;
    }
    printf("created\n");

    memset(buf, 0x00, sizeof(buf));
    ret = write(fd, buf, sizeof(buf) / sizeof(char));
    if (-1 == ret)
    {
        goto out;
    }

    memset(buf, 0xFF, sizeof(buf));
    ret = write(fd, buf, sizeof(buf) / sizeof(char));
    if (-1 == ret)
    {
        goto out;
    }
    
out:
    printf("this is out\n");
    return ret;
}