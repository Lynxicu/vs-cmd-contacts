#include "common.h"
#include "file.h"
#include "input.h"
#include "message.h"

#define CONTROL_FIRST 10
#define CONTROL_NOT_FIRST 20
#define CONTROL_ADD 30
#define CONTROL_UPDATE 40

status control_input_info(int n_state, data *const p_data_temp, node *const p_node_list);
status control_input_class(int n_state, data *const p_data_temp, node *const p_node_list);
status control_delete(data *const p_data_temp, node *const p_node_list);
status control_update(data *const p_data_temp, node *const p_node_list);
status control_search_id(data *const p_data_temp, const node *const p_NODE_LIST);
status control_search_name(data *const p_data_temp, const node *const p_NODE_LIST);
status control_search_contacts(data *const p_data_temp, const node *const p_NODE_LIST);
void control_search_all(const node *const p_NODE_LIST);

int main(void)
{
	int n_key_stroke = KEY_DEFAULT;
	data *p_data_temp = (data *)malloc(sizeof(data));
	node *p_node_list = (node *)malloc(sizeof(node));

	if (NULL == p_data_temp || NULL == p_node_list) {
		msg_memory_error();
		exit(1);
	}

	if (OPERATE_SUCCESS != file_load(p_data_temp, p_node_list)) {
		msg_file_error();
		exit(1);
	}

	msg_welcome();

	if ('\0' != p_node_list->data_info.s_id[0]) {
		msg_class_info(p_node_list);
	}
	else {
		control_input_class(CONTROL_FIRST, p_data_temp, p_node_list);
	}

	while (KEY_EXIT != n_key_stroke) {
		msg_menu();

		switch (n_key_stroke = input_menu()) {
		case 1:
			msg_add();
			n_key_stroke = control_input_info(CONTROL_ADD, p_data_temp, p_node_list);
			break;
		case 2:
			msg_delete();
			n_key_stroke = control_delete(p_data_temp, p_node_list);
			break;
		case 3:
			msg_update();
			n_key_stroke = control_update(p_data_temp, p_node_list);
			break;
		case 4:
			msg_search();
			n_key_stroke = control_search_id(p_data_temp, p_node_list);
			break;
		case 5:
			msg_search();
			n_key_stroke = control_search_name(p_data_temp, p_node_list);
			break;
		case 6:
			msg_search();
			n_key_stroke = control_search_contacts(p_data_temp, p_node_list);
			break;
		case 7:
			msg_search_all();
			control_search_all(p_node_list);
			break;
		case 8:
			msg_update_class();
			n_key_stroke = control_input_class(CONTROL_NOT_FIRST, p_data_temp, p_node_list);
			break;
		case 9:
			msg_help();
			break;
		case KEY_EXIT:
			msg_exit_confirm();

			if (KEY_EXIT == (n_key_stroke = input_yes_no())) {
				free(p_data_temp);

				if (OPERATE_SUCCESS != file_save(p_node_list)) {
					msg_file_error();
					exit(1);
				}
				
				msg_exit_success();
			}
			else {
				msg_cancel();
			}

			break;
		default:
			msg_menu_error();
		}
	}

	return 0;
}

status control_input_info(int n_state, data *const p_data_temp, node *const p_node_list)
{
	status n_key = KEY_DEFAULT;

	do {
		msg_input_id();

		if (INPUT_ERROR == (n_key = input_id(p_data_temp))) {
			msg_input_id_error();
			n_key = KEY_DEFAULT;
		}
		else if (INPUT_CANCEL != n_key && p_node_list != list_search_id(p_data_temp->s_id, p_node_list, p_node_list)) {
			msg_repeat();
			n_key = KEY_DEFAULT;
		}
	} while (KEY_DEFAULT == n_key);

	if (INPUT_CANCEL != n_key) {
		do {
			msg_input_name();

			if (INPUT_ERROR == (n_key = input_name(p_data_temp))) {
				msg_input_name_error();
				n_key = KEY_DEFAULT;
			}
		} while (KEY_DEFAULT == n_key);
	}

	if (INPUT_CANCEL != n_key) {
		do {
			msg_input_contacts();

			if (INPUT_ERROR == (n_key = input_contacts(p_data_temp))) {
				msg_input_contacts_error();
				n_key = KEY_DEFAULT;
			}
		} while (KEY_DEFAULT == n_key);
	}

	if (INPUT_CANCEL == n_key) {
		msg_cancel();
	}
	else {
		if (CONTROL_ADD == n_state) {
			if (OPERATE_SUCCESS == input_add(p_data_temp, p_node_list)) {
				msg_add_success(input_count(p_node_list), p_data_temp);
			}
			else {
				msg_add_error();
				msg_memory_error();
			}
		}

		if (CONTROL_UPDATE == n_state) {
			msg_update_confirm(p_data_temp);

			if (KEY_EXIT == (n_key = input_yes_no())) {
				if (OPERATE_SUCCESS == input_add(p_data_temp, p_node_list)) {
					msg_update_success();
				}
				else {
					msg_update_error();
					msg_memory_error();
				}
			}
			else {
				msg_cancel();
			}
		}
	}

	n_key = KEY_DEFAULT;
	return n_key;
}

status control_input_class(int n_state, data *const p_data_temp, node *const p_node_list)
{
	status n_key = KEY_DEFAULT;

	do {
		msg_input_class();

		if (INPUT_ERROR == (n_key = input_class_name(p_data_temp))) {
			msg_input_class_error();
			n_key = KEY_DEFAULT;
		}
		else if (CONTROL_FIRST == n_state && INPUT_CANCEL == n_key) {
			msg_class_empty();
			n_key = KEY_DEFAULT;
		}

		if (INPUT_CANCEL == n_key) {
			msg_cancel();
		}
		else {
			msg_input_class_confirm(p_data_temp);

			if (KEY_EXIT == (n_key = input_yes_no())) {
				list_node_update(p_data_temp, p_node_list);
				msg_input_class_success();
			}
			else if (CONTROL_FIRST == n_state && KEY_EXIT != n_key) {
				n_key = KEY_DEFAULT;
			}
			else {
				msg_cancel();
			}
		}
	} while (KEY_DEFAULT == n_key);

	n_key = KEY_DEFAULT;
	return n_key;
}

status control_delete(data *const p_data_temp, node *const p_node_list)
{
	status n_key = KEY_DEFAULT;

	do {
		msg_input_id();

		if (INPUT_ERROR == (n_key = input_id(p_data_temp))) {
			msg_input_id_error();
			n_key = KEY_DEFAULT;
		}
	} while (KEY_DEFAULT == n_key);

	if (INPUT_CANCEL == n_key) {
		msg_cancel();
	}
	else {
		node *p_node_temp = list_search_id(p_data_temp->s_id, p_node_list, p_node_list);

		if (p_node_list != p_node_temp) {
			msg_delete_confirm(&p_node_temp->data_info);

			if (KEY_EXIT == (n_key = input_yes_no())) {
				input_delete(p_node_temp, p_node_list);
				msg_delete_success();
			}
			else {
				msg_cancel();
			}
		}
		else {
			msg_search_error();
		}
	}

	n_key = KEY_DEFAULT;
	return n_key;
}

status control_update(data *const p_data_temp, node *const p_node_list)
{
	status n_key = KEY_DEFAULT;

	do {
		msg_input_id();

		if (INPUT_ERROR == (n_key = input_id(p_data_temp))) {
			msg_input_id_error();
			n_key = KEY_DEFAULT;
		}
	} while (KEY_DEFAULT == n_key);

	if (INPUT_CANCEL == n_key) {
		msg_cancel();
	}
	else {
		node *p_node_temp = list_search_id(p_data_temp->s_id, p_node_list, p_node_list);

		if (p_node_list != p_node_temp) {
			msg_update_original(&p_node_temp->data_info);
			input_delete(p_node_temp, p_node_list);
			control_input_info(CONTROL_UPDATE, p_data_temp, p_node_list);
		}
		else {
			msg_search_error();
		}
	}

	n_key = KEY_DEFAULT;
	return n_key;
}

status control_search_id(data *const p_data_temp, const node *const p_NODE_LIST)
{
	status n_key = KEY_DEFAULT;

	do {
		msg_input_id();

		if (INPUT_ERROR == (n_key = input_id(p_data_temp))) {
			msg_input_id_error();
			n_key = KEY_DEFAULT;
		}
	} while (KEY_DEFAULT == n_key);

	if (INPUT_CANCEL == n_key) {
		msg_cancel();
	}
	else {
		node *p_node_temp = list_search_id(p_data_temp->s_id, p_NODE_LIST, p_NODE_LIST);

		if (NULL != p_node_temp && p_NODE_LIST != p_node_temp) {
			msg_search_show_header();
			msg_search_show(&p_node_temp->data_info);
			msg_search_back();
			_getch();
		}
		else {
			msg_search_error();
		}
	}

	n_key = KEY_DEFAULT;
	return n_key;
}

status control_search_name(data *const p_data_temp, const node *const p_NODE_LIST)
{
	status n_key = KEY_DEFAULT;
	int n_count = 0;

	do {
		msg_input_name();

		if (INPUT_ERROR == (n_key = input_name(p_data_temp))) {
			msg_input_name_error();
			n_key = KEY_DEFAULT;
		}
	} while (KEY_DEFAULT == n_key);

	if (INPUT_CANCEL == n_key) {
		msg_cancel();
	}
	else {
		node *p_node_temp = list_search_name(p_data_temp->s_name, p_NODE_LIST, p_NODE_LIST);

		if (NULL != p_node_temp && p_NODE_LIST != p_node_temp) {
			msg_search_show_header();

			while (p_NODE_LIST != p_node_temp) {
				++n_count;
				msg_search_show(&p_node_temp->data_info);
				p_node_temp = list_search_name(p_data_temp->s_name, p_node_temp, p_NODE_LIST);
			}

			msg_search_count(&n_count);
			msg_search_back();
			_getch();
		}
		else {
			msg_search_error();
		}
	}

	n_key = KEY_DEFAULT;
	return n_key;
}

status control_search_contacts(data *const p_data_temp, const node *const p_NODE_LIST)
{
	status n_key = KEY_DEFAULT;
	int n_count = 0;

	do {
		msg_input_contacts();

		if (INPUT_ERROR == (n_key = input_contacts(p_data_temp))) {
			msg_input_contacts_error();
			n_key = KEY_DEFAULT;
		}
	} while (KEY_DEFAULT == n_key);

	if (INPUT_CANCEL == n_key) {
		msg_cancel();
	}
	else {
		node *p_node_temp = list_search_contacts(p_data_temp->s_contacts, p_NODE_LIST, p_NODE_LIST);

		if (NULL != p_node_temp && p_NODE_LIST != p_node_temp) {
			msg_search_show_header();

			while (p_NODE_LIST != p_node_temp) {
				++n_count;
				msg_search_show(&p_node_temp->data_info);
				p_node_temp = list_search_contacts(p_data_temp->s_contacts, p_node_temp, p_NODE_LIST);
			}

			msg_search_count(&n_count);
			msg_search_back();
			_getch();
		}
		else {
			msg_search_error();
		}
	}

	n_key = KEY_DEFAULT;
	return n_key;
}

void control_search_all(const node *const p_NODE_LIST)
{
	node *p_node_temp = p_NODE_LIST->p_node_next;

	if (p_NODE_LIST != p_node_temp) {
		msg_search_show_header();
	}

	while (p_NODE_LIST != p_node_temp) {
		msg_search_show(&p_node_temp->data_info);
		p_node_temp = p_node_temp->p_node_next;
	}

	msg_output_count(p_NODE_LIST);
	msg_search_back();
	_getch();
}