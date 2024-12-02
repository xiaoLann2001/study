#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define FILE_PATH "./file.txt"

int main(void)
{
    char buffer0[10] = "cqupt";
    char buffer1[10];
    int fd;
    int ret;

    fd = open(FILE_PATH, O_RDWR | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
    if (-1 == fd)
    {
        ret = fd;
        goto out;
    }
    
    printf("buffer0:");
    for (int i = 0; i < 10; i++)
    {
        printf("%c", buffer0[i]);
    }
    puts("");
    
    ret = write(fd, buffer0, sizeof(buffer0));
    if (-1 == ret)
    {
        goto out;
    }  

    // read() and write() 使用同一個讀寫偏移量
    off_t off = lseek(fd, 0, SEEK_SET);
    if (-1 == off)
    {
        ret = off;
        goto out;
    }

    ret = read(fd, buffer1, sizeof(buffer1));
    if (-1 == ret)
    {
        goto out;
    }

    printf("buffer1:");
    for (int i = 0; i < 10; i++)
    {
        printf("%c", buffer1[i]);
    }
    puts("");

out:
    close(fd);
    return ret;
}