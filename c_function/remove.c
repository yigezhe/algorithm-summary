#include <stdio.h>
int main(void) {
    char file[80];
    /* prompt for filename to delete */
    printf("File to delete: ");
    gets(file);
    /* delete file */
    //可以删除文件也可以删除目录！
    if(remove(file) == 0)
        printf("Removed %s.\n",file);
    else
        perror("remove");
    return 0;
}
