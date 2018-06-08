#pragma once

#include "common.h"

#define ID_SIZE  13
#define NAME_SIZE  13
#define CONTACTS_SIZE  64

typedef int status;

typedef struct data {
	char s_id[ID_SIZE];
	char s_name[NAME_SIZE];
	char s_contacts[CONTACTS_SIZE];
}data;

typedef struct node {
	data data_info;
	struct node *p_node_last;
	struct node *p_node_next;
}node;

void list_initialize(node *const p_node_list);
void list_destroy(node *p_node_list);
int list_length(const node *const p_NODE_LIST);
status list_node_add(const data *const p_DATA, node *const p_node_list);
void list_node_delete(node *p_node, node *const p_node_list);
void list_node_update(const data *const p_DATA, node *const p_node);
node *list_search_id(const char *const p_s_ID, const node *const p_NODE, const node *const p_NODE_LIST);
node *list_search_name(const char *const p_s_NAME, const node *const p_NODE, const node *const p_NODE_LIST);
node *list_search_contacts(const char *const p_s_CONTACTS, const node *const p_NODE, const node *const p_NODE_LIST);
static void list_node_copy(const data *const p_DATA, node *const p_node);

