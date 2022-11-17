#include "EOSApp.h"

//
// main 函数参数的意义：
// argc - argv 数组的长度，大小至少为 1，argc - 1 为命令行参数的数量。
// argv - 字符串指针数组，数组长度为命令行参数个数 + 1。其中 argv[0] 固定指向当前
//        进程所执行的可执行文件的路径字符串，argv[1] 及其后面的指针指向各个命令行
//        参数。
//        例如通过命令行内容 "a:\hello.exe -a -b" 启动进程后，hello.exe 的 main 函
//        数的参数 argc 的值为 3，argv[0] 指向字符串 "a:\hello.exe"，argv[1] 指向
//        参数字符串 "-a"，argv[2] 指向参数字符串 "-b"。
//
int main(int argc, char* argv[])
{
	//
	// 如果需要在调试应用程序时能够调试进入内核并显示对应的源码，
	// 必须使用 EOS 内核项目编译生成完全版本的 SDK 文件夹，然
	// 后使用刚刚生成的 SDK 文件夹覆盖此应用程序项目中的 SDK 文件
	// 夹，并且 EOS 内核项目在磁盘上的位置不能改变。
	//

	/* TODO: 在此处添加自己的代码 */
	//printf("Hello world!\n");
	INT *d;
	//
	// 调用API函数VirtualAlloc，
	// 分配一个整型变量所需的空间，
	// 并用一个整型变量的指针指向这个空间
	//
	if (d = VirtualAlloc(0, sizeof(int), MEM_RESERVE|MEM_COMMIT)) {
		printf("Allocated %d bytes virtual memory of 0x%x \n\n", *d);
		//
		// 修改整型变量的值为0xFFFFFFFF
		// 在修改前输出整型变量的值，并在修改后输出整型变量的值
		//
		printf("virtual memory original value: 0x%x\n\n", *d);
		*d = 0xFFFFFFFF;
		printf("a new virtual memory value: 0x%x\n\n", *d);
		//
		// 调用API函数等待10秒
		//
		Sleep(10000);
		//
		// 调用API函数VirtualFree,
		// 释放之前分配的整型变量的空间
		//
		if (VirtualFree(d, 0, MEM_RELEASE)) {
			printf("release virtualmemory success!\n");
		} else {
			printf("release error\n");
		}
		//
		// 进入死循环
		//
		printf("endless loop start");
		for(;;);
	} else {
		printf("error\n");
		return -1;
	}
	printf("program complete\n");
	return 0;
}
