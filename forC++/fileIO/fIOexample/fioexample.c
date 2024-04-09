#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main(void)
{
    char buff[1024];
    int fd1, fd2;
    int ret;
    /* 打开源文件 src_file */
    fd1 = open("./src_file.txt", O_RDWR, 
                            S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
    if (-1 == fd1)
        return fd1;
    /* 打开目标文件 dest_file */
    fd2 = open("./dest_file.txt", O_RDWR, 
                            S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
    if (-1 == fd2)
    {
        ret = fd2;
        goto out1;
    }
    /* 读取源文件 1KB 数据到 buff 中 */
    ret = read(fd1, buff, sizeof(buff));
    if (-1 == ret)
        goto out2;
    /* 将 buff 中的数据写入目标文件 */
    ret = write(fd2, buff, sizeof(buff));
    if (-1 == ret)
        goto out2;
    ret = 0;
out2:
    /* 关闭目标文件 */
    close(fd2);
out1:
    /* 关闭源文件 */
    close(fd1);
    return ret;
}