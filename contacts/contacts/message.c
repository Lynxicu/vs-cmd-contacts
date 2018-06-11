#include "message.h"

void msg_memory_error(void)
{
	set_color_red_alert();
	puts("");
	puts("�ڴ����");
	puts("�޷�Ϊ��������ڴ棡");
	puts("���򼴽��˳���");
	Sleep(600);
}

void msg_file_error(void)
{
	set_color_red_alert();
	puts("");
	puts("�ļ�����");
	puts("�޷���д�����ļ���");
	puts("���򼴽��˳���");
	Sleep(600);
}

void msg_cancel(void)
{
	set_color_light();
	puts("");
	puts("������ȡ����");
	Sleep(100);
}

void msg_welcome(void)
{
	set_color_blue_tips();
	puts("��ӭʹ�ð༶ͨѶ¼�������");
}

void msg_class_info(const node *const p_NODE)
{
	set_color_light();
	printf("�༶���ƣ�");
	set_color_blue_tips();
	printf("%s\n", p_NODE->data_info.s_contacts);
	set_color_light();
	printf("�༶������");
	set_color_blue_tips();
	printf("%s\n", p_NODE->data_info.s_id);
}

void msg_menu(void)
{
	set_color_default();
	puts("");
	puts("**********************");
	puts("�����˵���");
	puts("-> 1.��Ϣ¼��");
	puts("-> 2.��Ϣɾ��");
	puts("-> 3.��Ϣ�޸�");
	puts("-> 4.��ѧ�Ų�ѯ");
	puts("-> 5.��������ѯ");
	puts("-> 6.����ϵ��ʽ��ѯ");
	puts("-> 7.ȫ����Ϣ��ѯ");
	puts("-> 8.�޸İ༶����");
	puts("-> 9.ʹ�ð���");
	puts("-> 0.�˳�");
	puts("**********************");
	puts("");
	printf("������Ҫִ�еĲ�����");
}

void msg_menu_error(void)
{
	set_color_yellow_alert();
	puts("");
	puts("��������");
	puts("δ�ҵ�Ŀ������");
	Sleep(100);
}

void msg_exit_confirm(void)
{
	set_color_blue_tips();
	puts("");
	printf("ȷ��Ҫ�˳���");
	set_color_default();
	printf("�������ǣ�y����n����");
}

void msg_exit_success(void)
{
	set_color_green_tips();
	puts("");
	puts("�ļ��ѱ��棬�������˳���");
	Sleep(600);
}

void msg_add(void)
{
	set_color_blue_tips();
	puts("");
	printf("����¼����Ϣ��");
	set_color_default();
	printf("��Ҫȡ��������������--c��\n");
}

void msg_add_error(void)
{
	set_color_red_alert();
	puts("");
	puts("¼��ʧ�ܣ�");
}

void msg_add_success(const int n_count, const data *const p_DATA)
{
	set_color_blue_tips();
	msg_output_header();
	set_color_light();
	msg_output(p_DATA);
	set_color_green_tips();
	puts("");
	puts("��Ϣ¼��ɹ���");
	set_color_default();
	puts("");
	printf("���ݿ⹲");
	set_color_green_tips();
	printf("%d", n_count);
	set_color_default();
	printf("����Ϣ��\n");
	Sleep(100);
}

void msg_delete(void)
{
	set_color_red_alert();
	puts("");
	printf("����ɾ����Ϣ��");
	set_color_default();
	printf("��Ҫȡ��������������--c��\n");
}

void msg_delete_confirm(const data *const p_DATA)
{
	set_color_blue_tips();
	msg_output_header();
	set_color_light();
	msg_output(p_DATA);
	set_color_red_alert();
	puts("");
	printf("ȷ��Ҫɾ����");
	set_color_default();
	printf("�������ǣ�y����n����");
}

void msg_delete_success(void)
{
	set_color_green_tips();
	puts("");
	puts("��Ϣɾ���ɹ���");
	Sleep(100);
}

void msg_update(void)
{
	set_color_blue_tips();
	puts("");
	printf("�����޸���Ϣ��");
	set_color_default();
	printf("��Ҫȡ����������--c��\n");
}

void msg_update_original(const data *const p_DATA)
{
	set_color_light();
	puts("");
	puts("ԭʼ��Ϣ��");
	set_color_blue_tips();
	msg_output_header();
	set_color_default();
	msg_output(p_DATA);
	set_color_light();
	puts("");
	puts("�޸���Ϣ��");
}

void msg_update_confirm(const data *const p_DATA)
{
	set_color_light();
	puts("");
	puts("�޸���ϢΪ��");
	set_color_blue_tips();
	msg_output_header();
	set_color_light();
	msg_output(p_DATA);
	set_color_yellow_alert();
	puts("");
	printf("ȷ��Ҫ�޸���");
	set_color_default();
	printf("�������ǣ�y����n����");
}

void msg_update_error(void)
{
	set_color_red_alert();
	puts("");
	puts("�޸�ʧ�ܣ�");
}

void msg_update_success(void)
{
	set_color_green_tips();
	puts("");
	puts("��Ϣ�޸ĳɹ���");
	Sleep(100);
}

void msg_search(void)
{
	set_color_blue_tips();
	puts("");
	printf("���ڲ�ѯĿ����Ϣ��");
	set_color_default();
	printf("��Ҫȡ��������������--c��\n");
}

void msg_search_all(void)
{
	set_color_blue_tips();
	puts("");
	puts("���ڲ�ѯȫ����Ϣ��");
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
	printf("���ҵ�");
	set_color_blue_tips();
	printf("%d", *p_n_COUNT);
	set_color_default();
	printf("����Ϣ��\n");
	Sleep(100);
}

void msg_search_back(void)
{
	set_color_default();
	puts("");
	puts("����������ء�");
	Sleep(100);
}

void msg_search_error(void)
{
	set_color_yellow_alert ();
	puts("");
	puts("��ѯ����");
	puts("δ�ҵ�Ŀ����Ϣ��");
	Sleep(100);
}

void msg_input_id(void)
{
	set_color_default();
	puts("");
	printf("������ѧ��ѧ�ţ�12λ����");
	set_color_light();
}

void msg_repeat(void)
{
	set_color_yellow_alert();
	puts("");
	puts("�������");
	puts("�Ѵ��ڸ�ѧ�ţ�");
	Sleep(100);
}

void msg_input_id_error(void)
{
	set_color_yellow_alert();
	puts("");
	puts("�������");
	puts("��ȷ��ѧ�Ÿ�ʽΪ12λ���֣�");
	Sleep(100);
}

void msg_input_name(void)
{
	set_color_default();
	puts("");
	printf("������ѧ��������");
	set_color_light();
}

void msg_input_name_error(void)
{
	set_color_yellow_alert();
	puts("");
	puts("�������");
	puts("�����ѧ������������");
	Sleep(100);
}

void msg_input_contacts(void)
{
	set_color_default();
	puts("");
	printf("��������ϵ��ʽ��");
	set_color_light();
}

void msg_input_contacts_error(void)
{
	set_color_yellow_alert();
	puts("");
	puts("�������");
	puts("�������ϵ��ʽ������");
	Sleep(100);
}

void msg_output_header(void)
{
	puts("");
	printf("%-12s\t", "ѧ��");
	printf("%-12s\t", "����");
	printf("%-63s\n", "��ϵ��ʽ");
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
	printf("���ݿ⹲");
	set_color_blue_tips();
	printf("%d", list_length(p_NODE_LIST));
	set_color_default();
	printf("����Ϣ��\n");
	Sleep(100);
}

void msg_update_class(void)
{
	set_color_blue_tips();
	puts("");
	printf("�����޸İ༶���ƣ�");
	set_color_default();
	printf("��Ҫȡ��������������--c��\n");
}

void msg_input_class_first(void)
{
	set_color_blue_tips();
	puts("");
	puts("�������ð༶���ƣ�");
}

void msg_input_class(void)
{
	set_color_default();
	puts("");
	printf("������༶���ƣ�");
	set_color_light();
}

void msg_input_class_confirm(const data *const p_DATA)
{
	set_color_yellow_alert();
	puts("");
	printf("ȷ��Ҫ���༶��������Ϊ\"%s\"��", p_DATA->s_contacts);
	set_color_default();
	printf("�������ǣ�y����n����");
}

void msg_class_empty(void)
{
	set_color_yellow_alert();
	puts("");
	puts("�������");
	puts("�༶����Ϊ���޷�ȡ�����룡");
	Sleep(100);
}

void msg_input_class_error(void)
{
	set_color_yellow_alert();
	puts("");
	puts("�������");
	puts("����İ༶���ƹ�����");
	Sleep(100);
}

void msg_input_class_success(void)
{
	set_color_green_tips();
	puts("");
	puts("�༶�������óɹ���");
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