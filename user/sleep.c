/**
 * Param 1
 * 开始编写程序之前，记得看看提示：https://pdos.csail.mit.edu/6.828/2020/labs/util.html
 * 下面是中文翻译
 * 1. 开始编码前，请先看第一章: https://pdos.csail.mit.edu/6.828/2020/xv6/book-riscv-rev1.pdf
 * 2. 看 (user/) 文件夹中的其他例子(例如: echo.c, grep.c, rm.c)，去学习如何把命令行参数传递到程序内；
 * 2. 如果用户忘记传递参数，sleep 需要打印一个错误信息
 * 3. 命令行参数传递进来时是 string 类型，你可以使用 atoi 函数将它转为 int 类型 (参考 user/ulib.c)
 * 4. 使用系统调用 sleep
 * 5. 从(kernel/sysproc.c)看 xv6 的内核如何实现 sleep 这个系统调用(搜索sys_sleep)，而可从用户程序调用 sleep 的
 *    C 语言定义在(user/user.h)，(user/usys.S)则表示从用户代码跳转到内核进行 sleep 的汇编代码。
 * 6. 确保 main 函数调用了 exit() 方法，以便退出你的程序。
 * 7. 将你的 sleep 程序添加到 Makefile 文件的 UPROGS
 *    一旦你这么做，make qemu 命令会编译你的程序，并且你可以在 xv6 的命令行中执行它。
 * 8. 看 Kernighan 和 Ritchie 的书 《C程序设计语言（第2版·新版）》来学习 C.
 */
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[]) {
  // 如果没有传递参数
  if (argc <= 1) {
    fprintf(2, "usage: sleep time...\n");
    exit(1);
  }
  if (sleep(atoi(argv[1])) < 0) {
    fprintf(2, "sleep: %s failed.\n", argv[1]);
    exit(1);
  }
  exit(0);
}
