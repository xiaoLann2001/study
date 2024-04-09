#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define SRC_FILE "./src_file"
#define DEST_FILE "./dest_file"

int main()
{
    char buffer[1024];
    int fd1, fd2;
    int ret;
    off_t off;

    // 打开已存在的文件
    fd1 = open(SRC_FILE, O_RDONLY);
    if (-1 == fd1)
    {
        ret = -1;
        goto out;
    }

    // 打开新建文件, 文件所属者拥有读、写、执行权限, 同组用户与其他用户只有读权限。
    fd2 = open(DEST_FILE, O_WRONLY | O_CREAT, S_IRWXU | S_IRGRP | S_IROTH);
    if (-1 == fd2)
    {
        goto out1;
    }

    // 从 src_file 文件偏移头部 500 个字节位置开始读取 1Kbyte 字节数据
    off = lseek(fd1, 500, SEEK_SET);
    if (-1 == off)
    {
        goto out2;
    }

    ret = read(fd1, buffer, sizeof(buffer));
    if (-1 == ret)
    {
        ret = -1;
        goto out2;
    }

    // 将读取出来的数据写入到dest_file 文件中，从文件开头处开始写入， 1Kbyte 字节大小
    off = lseek(fd2, 0, SEEK_SET);
    if (-1 == off)
    {
        goto out2;
    }

    ret = write(fd2, buffer, sizeof(buffer));
    if (-1 == ret)
    {
        ret = -1;
        goto out2;
    }

    // 操作完成之后使用 close 显式关闭所有文件，然后退出程序
    printf("run successfully\n");
out2: 
    printf("this is out2\n");
    close(fd2);
out1:
    printf("this is out1\n");
    close(fd1);
out:
    printf("this is out\n");
    return ret;
}