#include "message.h"

void msg_memory_error(void)
{
	set_color_red_alert();
	puts("");
	puts("内存错误：");
	puts("无法为程序分配内存！");
	puts("程序即将退出！");
	Sleep(600);
}

void msg_file_error(void)
{
	set_color_red_alert();
	puts("");
	puts("文件错误：");
	puts("无法读写数据文件！");
	puts("程序即将退出！");
	Sleep(600);
}

void msg_cancel(void)
{
	set_color_light();
	puts("");
	puts("操作已取消！");
	Sleep(100);
}

void msg_welcome(void)
{
	set_color_blue_tips();
	puts("欢迎使用班级通讯录管理程序！");
}

void msg_class_info(const node *const p_NODE)
{
	set_color_light();
	printf("班级名称：");
	set_color_blue_tips();
	printf("%s\n", p_NODE->data_info.s_contacts);
	set_color_light();
	printf("班级人数：");
	set_color_blue_tips();
	printf("%s\n", p_NODE->data_info.s_id);
}

void msg_menu(void)
{
	set_color_default();
	puts("");
	puts("**********************");
	puts("操作菜单：");
	puts("-> 1.信息录入");
	puts("-> 2.信息删除");
	puts("-> 3.信息修改");
	puts("-> 4.按学号查询");
	puts("-> 5.按姓名查询");
	puts("-> 6.按联系方式查询");
	puts("-> 7.全体信息查询");
	puts("-> 8.修改班级名称");
	puts("-> 9.使用帮助");
	puts("-> 0.退出");
	puts("**********************");
	puts("");
	printf("请输入要执行的操作：");
}

void msg_menu_error(void)
{
	set_color_yellow_alert();
	puts("");
	puts("操作错误：");
	puts("未找到目标操作项！");
	Sleep(100);
}

void msg_exit_confirm(void)
{
	set_color_blue_tips();
	puts("");
	printf("确认要退出吗？");
	set_color_default();
	printf("请输入是（y）否（n）：");
}

void msg_exit_success(void)
{
	set_color_green_tips();
	puts("");
	puts("文件已保存，程序已退出。");
	Sleep(600);
}

void msg_add(void)
{
	set_color_blue_tips();
	puts("");
	printf("正在录入信息：");
	set_color_default();
	printf("（要取消操作，请输入--c）\n");
}

void msg_add_error(void)
{
	set_color_red_alert();
	puts("");
	puts("录入失败！");
}

void msg_add_success(const int n_count, const data *const p_DATA)
{
	set_color_blue_tips();
	msg_output_header();
	set_color_light();
	msg_output(p_DATA);
	set_color_green_tips();
	puts("");
	puts("信息录入成功！");
	set_color_default();
	puts("");
	printf("数据库共");
	set_color_green_tips();
	printf("%d", n_count);
	set_color_default();
	printf("条信息。\n");
	Sleep(100);
}

void msg_delete(void)
{
	set_color_red_alert();
	puts("");
	printf("正在删除信息：");
	set_color_default();
	printf("（要取消操作，请输入--c）\n");
}

void msg_delete_confirm(const data *const p_DATA)
{
	set_color_blue_tips();
	msg_output_header();
	set_color_light();
	msg_output(p_DATA);
	set_color_red_alert();
	puts("");
	printf("确认要删除吗？");
	set_color_default();
	printf("请输入是（y）否（n）：");
}

void msg_delete_success(void)
{
	set_color_green_tips();
	puts("");
	puts("信息删除成功！");
	Sleep(100);
}

void msg_update(void)
{
	set_color_blue_tips();
	puts("");
	printf("正在修改信息：");
	set_color_default();
	printf("（要取消，请输入--c）\n");
}

void msg_update_original(const data *const p_DATA)
{
	set_color_light();
	puts("");
	puts("原始信息：");
	set_color_blue_tips();
	msg_output_header();
	set_color_default();
	msg_output(p_DATA);
	set_color_light();
	puts("");
	puts("修改信息：");
}

void msg_update_confirm(const data *const p_DATA)
{
	set_color_light();
	puts("");
	puts("修改信息为：");
	set_color_blue_tips();
	msg_output_header();
	set_color_light();
	msg_output(p_DATA);
	set_color_yellow_alert();
	puts("");
	printf("确认要修改吗？");
	set_color_default();
	printf("请输入是（y）否（n）：");
}

void msg_update_error(void)
{
	set_color_red_alert();
	puts("");
	puts("修改失败！");
}

void msg_update_success(void)
{
	set_color_green_tips();
	puts("");
	puts("信息修改成功！");
	Sleep(100);
}

void msg_search(void)
{
	set_color_blue_tips();
	puts("");
	printf("正在查询目标信息：");
	set_color_default();
	printf("（要取消操作，请输入--c）\n");
}

void msg_search_all(void)
{
	set_color_blue_tips();
	puts("");
	puts("正在查询全体信息：");
}

void msg_search_show_header(void)
{
	set_color_blue_tips();
	msg_output_header();
}

void msg_search_show(const data *const p_DATA)
{
	set_color_light();
	msg_output(p_DATA);
}

void msg_search_count(const int *const p_n_COUNT)
{
	set_color_default();
	puts("");
	printf("共找到");
	set_color_blue_tips();
	printf("%d", *p_n_COUNT);
	set_color_default();
	printf("条信息。\n");
	Sleep(100);
}

void msg_search_back(void)
{
	set_color_default();
	puts("");
	puts("按任意键返回。");
	Sleep(100);
}

void msg_search_error(void)
{
	set_color_yellow_alert ();
	puts("");
	puts("查询错误：");
	puts("未找到目标信息！");
	Sleep(100);
}

void msg_input_id(void)
{
	set_color_default();
	puts("");
	printf("请输入学生学号（12位）：");
	set_color_light();
}

void msg_repeat(void)
{
	set_color_yellow_alert();
	puts("");
	puts("输入错误：");
	puts("已存在该学号！");
	Sleep(100);
}

void msg_input_id_error(void)
{
	set_color_yellow_alert();
	puts("");
	puts("输入错误：");
	puts("正确的学号格式为12位数字！");
	Sleep(100);
}

void msg_input_name(void)
{
	set_color_default();
	puts("");
	printf("请输入学生姓名：");
	set_color_light();
}

void msg_input_name_error(void)
{
	set_color_yellow_alert();
	puts("");
	puts("输入错误：");
	puts("输入的学生姓名过长！");
	Sleep(100);
}

void msg_input_contacts(void)
{
	set_color_default();
	puts("");
	printf("请输入联系方式：");
	set_color_light();
}

void msg_input_contacts_error(void)
{
	set_color_yellow_alert();
	puts("");
	puts("输入错误：");
	puts("输入的联系方式过长！");
	Sleep(100);
}

void msg_output_header(void)
{
	puts("");
	printf("%-12s\t", "学号");
	printf("%-12s\t", "姓名");
	printf("%-63s\n", "联系方式");
}

void msg_output(const data *const p_DATA)
{
	printf("%-12s\t", p_DATA->s_id);
	printf("%-12s\t", p_DATA->s_name);
	printf("%-63s\n", p_DATA->s_contacts);
}

void msg_output_count(const node *const p_NODE_LIST)
{
	set_color_default();
	puts("");
	printf("数据库共");
	set_color_blue_tips();
	printf("%d", list_length(p_NODE_LIST));
	set_color_default();
	printf("条信息。\n");
	Sleep(100);
}

void msg_update_class(void)
{
	set_color_blue_tips();
	puts("");
	printf("正在修改班级名称：");
	set_color_default();
	printf("（要取消操作，请输入--c）\n");
}

void msg_input_class_first(void)
{
	set_color_blue_tips();
	puts("");
	puts("正在设置班级名称：");
}

void msg_input_class(void)
{
	set_color_default();
	puts("");
	printf("请输入班级名称：");
	set_color_light();
}

void msg_input_class_confirm(const data *const p_DATA)
{
	set_color_yellow_alert();
	puts("");
	printf("确认要将班级名称设置为\"%s\"吗？", p_DATA->s_contacts);
	set_color_default();
	printf("请输入是（y）否（n）：");
}

void msg_class_empty(void)
{
	set_color_yellow_alert();
	puts("");
	puts("输入错误：");
	puts("班级名称为空无法取消输入！");
	Sleep(100);
}

void msg_input_class_error(void)
{
	set_color_yellow_alert();
	puts("");
	puts("输入错误：");
	puts("输入的班级名称过长！");
	Sleep(100);
}

void msg_input_class_success(void)
{
	set_color_green_tips();
	puts("");
	puts("班级名称设置成功！");
}

void msg_help(void)
{

}

static void set_color_default(void)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

static void set_color_light(void)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

static void set_color_blue_tips(void)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

static void set_color_green_tips(void)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
}

static void set_color_yellow_alert(void)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
}

static void set_color_red_alert(void)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
}