#include"xlang.h"

//强制使用UTF-8编码的程序
int main(int argc, char const *argv[])
{
#ifdef _WIN32//确保所有系统下都是以UTF-8编码（Windows下是GBK）
    system("chcp 65001>nul");
#endif
    printf("Hello你好World世界\n");
    for (int i = 0; i < argc; i++)
    {
        printf("参数%d:%s\n", i, argv[i]);
    }
    //如果没有参数，等待用户按键盘（调试启动时没指定参数）
    if(argc==1)
        getchar();
    return 0;
}
