#include "input.h"

status input_menu(void)
{
	status n_key = KEY_DEFAULT;
	char s_temp[STRING_TEMP_SIZE];

	scanf_s("%s", s_temp, STRING_TEMP_SIZE);

	if (0 != isdigit(s_temp[0]) && '\0' == s_temp[1]) {
		n_key = s_temp[0] - 48;
	}
	else {
		n_key = INPUT_ERROR;
	}

	input_eatline();
	return n_key;
}


status input_yes_no(void)
{
	status n_key = KEY_DEFAULT;
	char s_temp[STRING_TEMP_SIZE];

	scanf_s("%s", s_temp, STRING_TEMP_SIZE);

	if ('y' == s_temp[0] || 'Y' == s_temp[0] || s_temp == strstr(s_temp, "yes") || s_temp == strstr(s_temp, "Yes") || '1' == s_temp[0] || s_temp == strstr(s_temp, "ÊÇ")) {
		n_key = KEY_EXIT;
	}

	input_eatline();
	return n_key;
}

status input_id(data *const p_data_temp)
{
	status n_key = KEY_DEFAULT;
	char s_temp[STRING_TEMP_SIZE];

	scanf_s("%s", s_temp, STRING_TEMP_SIZE);

	if (NULL != strstr(s_temp, "--c")) {
		n_key = INPUT_CANCEL;
	}
	else {
		for (int i = 0; i < ID_SIZE - 1; ++i) {
			if (strlen(s_temp) > ID_SIZE - 1 || 0 == isdigit((unsigned char)s_temp[i])) {
				n_key = INPUT_ERROR;
				break;
			}
		}

		if (KEY_DEFAULT == n_key) {
			strncpy_s(p_data_temp->s_id, ID_SIZE * sizeof(char), s_temp, ID_SIZE - 1);
			n_key = OPERATE_SUCCESS;
		}
	}

	input_eatline();
	return n_key;
}

status input_name(data *const p_data_temp)
{
	status n_key = KEY_DEFAULT;
	char s_temp[STRING_TEMP_SIZE];

	scanf_s("%s", s_temp, STRING_TEMP_SIZE);

	if (NULL != strstr(s_temp, "--c")) {
		n_key = INPUT_CANCEL;
	}
	else {
		if (strlen(s_temp) > NAME_SIZE - 1) {
			n_key = INPUT_ERROR;
		}
		if (KEY_DEFAULT == n_key) {
			strncpy_s(p_data_temp->s_name, NAME_SIZE * sizeof(char), s_temp, NAME_SIZE - 1);
			n_key = OPERATE_SUCCESS;
		}
	}

	input_eatline();
	return n_key;
}

status input_contacts(data *const p_data_temp)
{
	status n_key = KEY_DEFAULT;
	char s_temp[STRING_TEMP_SIZE];

	scanf_s("%s", s_temp, STRING_TEMP_SIZE);

	if (NULL != strstr(s_temp, "--c")) {
		n_key = INPUT_CANCEL;
	}
	else {
		if (strlen(s_temp) > CONTACTS_SIZE - 1) {
			n_key = INPUT_ERROR;
		}
		if (KEY_DEFAULT == n_key) {
			strncpy_s(p_data_temp->s_contacts, CONTACTS_SIZE * sizeof(char), s_temp, CONTACTS_SIZE - 1);
			n_key = OPERATE_SUCCESS;
		}
	}

	input_eatline();
	return n_key;
}

status input_class_name(data *const p_data_temp)
{
	status n_key = KEY_DEFAULT;
	char s_temp[STRING_TEMP_SIZE];

	scanf_s("%s", s_temp, STRING_TEMP_SIZE);

	if (NULL != strstr(s_temp, "--c")) {
		n_key = INPUT_CANCEL;
	}
	else {
		if (strlen(s_temp) > CONTACTS_SIZE - 1) {
			n_key = INPUT_ERROR;
		}

		if (KEY_DEFAULT == n_key) {
			strncpy_s(p_data_temp->s_contacts, CONTACTS_SIZE * sizeof(char), s_temp, CONTACTS_SIZE - 1);
			n_key = OPERATE_SUCCESS;
		}
	}

	input_eatline();
	return n_key;
}

status input_add(const data *const p_DATA, node *const p_node_list)
{
	status n_key = list_node_add(p_DATA, p_node_list);
	return n_key;
}

void input_delete(node *p_node, node *const p_node_list)
{
	list_node_delete(p_node, p_node_list);
}

int input_count(const node *const p_NODE_LIST)
{
	return list_length(p_NODE_LIST);
}

static void input_eatline(void)
{
	while ('\n' != getchar()) {
		continue;
	}
}