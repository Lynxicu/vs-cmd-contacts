#include "list.h"

void list_initialize(node *const p_node_list)
{
	*p_node_list->data_info.s_id = '\0';
	p_node_list->p_node_last = p_node_list;
	p_node_list->p_node_next = p_node_list;
}

void list_destroy(node *p_node_list)
{
	node *p_node_temp = p_node_list->p_node_next;

	while (p_node_list != p_node_temp) {
		p_node_temp = p_node_temp->p_node_next;
		free(p_node_temp->p_node_last);
	}

	free(p_node_list);
}

int list_length(const node *const p_NODE_LIST)
{
	return atoi(p_NODE_LIST->data_info.s_id);
}

status list_node_add(const data *const p_DATA, node *const p_node_list)
{
	status n_key = OPERATE_SUCCESS;
	node *p_node_temp = p_node_list->p_node_next;
	node *p_node_new = (node *)malloc(sizeof(node));

	if (NULL == p_node_new) {
		n_key = OPERATE_FAIL;
	}
	else {
		list_node_copy(p_DATA, p_node_new);

		while (p_node_list != p_node_temp) {
			if (0 < strcmp(p_node_temp->data_info.s_id, p_node_new->data_info.s_id)) {
				break;
			}

			p_node_temp = p_node_temp->p_node_next;
		}

		p_node_temp->p_node_last->p_node_next = p_node_new;
		p_node_new->p_node_last = p_node_temp->p_node_last;
		p_node_new->p_node_next = p_node_temp;
		p_node_temp->p_node_last = p_node_new;
		_itoa_s(atoi(p_node_list->data_info.s_id) + 1, p_node_list->data_info.s_id, ID_SIZE, 10);
	}

	return n_key;
}

void list_node_delete(node *p_node, node *const p_node_list)
{
	p_node->p_node_last->p_node_next = p_node->p_node_next;
	p_node->p_node_next->p_node_last = p_node->p_node_last;
	free(p_node);
	_itoa_s(atoi(p_node_list->data_info.s_id) - 1, p_node_list->data_info.s_id, ID_SIZE, 10);
}

void list_node_update(const data *const p_DATA, node *const p_node)
{
	list_node_copy(p_DATA, p_node);
}

node *list_search_id(const char *const p_s_ID, const node *const p_NODE, const node *const p_NODE_LIST)
{
	node *p_node_temp = p_NODE->p_node_next;
	node *p_node_find = NULL;

	while (p_NODE_LIST != p_node_temp) {
		if (0 == strcmp(p_node_temp->data_info.s_id, p_s_ID)) {
			break;
		}

		p_node_temp = p_node_temp->p_node_next;
	}

	p_node_find = p_node_temp;

	return p_node_find;
}

node *list_search_name(const char *const p_s_NAME, const node *const p_NODE, const node *const p_NODE_LIST)
{
	node *p_node_temp = p_NODE->p_node_next;
	node *p_node_find = NULL;

	while (p_NODE_LIST != p_node_temp) {
		if (NULL != strstr(p_node_temp->data_info.s_name, p_s_NAME)) {
			break;
		}

		p_node_temp = p_node_temp->p_node_next;
	}

	p_node_find = p_node_temp;

	return p_node_find;
}

node *list_search_contacts(const char *const p_s_CONTACTS, const node *const p_NODE, const node *const p_NODE_LIST)
{
	node *p_node_temp = p_NODE->p_node_next;
	node *p_node_find = NULL;

	while (p_NODE_LIST != p_node_temp) {
		if (NULL != strstr(p_node_temp->data_info.s_contacts, p_s_CONTACTS)) {
			break;
		}

		p_node_temp = p_node_temp->p_node_next;
	}

	p_node_find = p_node_temp;

	return p_node_find;
}

static void list_node_copy(const data *const p_DATA, node *const p_node)
{
	p_node->data_info = *p_DATA;
}