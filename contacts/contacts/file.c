#include "file.h"

status file_new(void)
{
	status n_key = OPERATE_SUCCESS;
	FILE *p_file = NULL;

	if (0 != fopen_s(&p_file, "info", "wb")) {
		n_key = OPERATE_FAIL;
	}

	fclose(p_file);
	return n_key;
}

status file_load(data *const p_data_temp, node *const p_node_list)
{
	status n_key = OPERATE_SUCCESS;
	node *p_node_temp = p_node_list->p_node_next;
	FILE *p_file = NULL;

	list_initialize(p_node_list);

	if (0 != fopen_s(&p_file, "info", "rb")) {
		if (OPERATE_SUCCESS != file_new()) {
			n_key = OPERATE_FAIL;
		}
	}
	else {
		if (1 == fread_s(p_data_temp, sizeof(data), sizeof(data), 1, p_file)) {
			list_node_update(p_data_temp, p_node_list);

			while (p_node_list != p_node_temp) {
				if (1 == fread_s(p_data_temp, sizeof(data), sizeof(data), 1, p_file)) {
					if (OPERATE_FAIL == list_node_add(p_data_temp, p_node_list)) {
						n_key = OPERATE_FAIL;
						break;
					}
				}
				else {
					break;
				}
			}
		}

		fclose(p_file);
	}

	return n_key;
}

status file_save(node *p_node_list)
{
	status n_key = OPERATE_SUCCESS;
	node *p_node_temp = p_node_list;
	FILE *p_file = NULL;

	_itoa_s(0, p_node_list->data_info.s_id, ID_SIZE, 10);

	if (0 != fopen_s(&p_file, "info", "wb")) {
		n_key = OPERATE_FAIL;
	}
	else {
		do {
			if (1 == fwrite(&p_node_temp->data_info, sizeof(data), 1, p_file)) {
				p_node_temp = p_node_temp->p_node_next;
			}
			else {
				n_key = OPERATE_FAIL;
				break;
			}
		} while (p_node_list != p_node_temp);

		list_destroy(p_node_list);
		fclose(p_file);
	}

	return n_key;
}