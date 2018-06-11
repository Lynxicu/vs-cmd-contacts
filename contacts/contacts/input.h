#pragma once

#include "common.h"
#include "list.h"

#define STRING_TEMP_SIZE 128

status input_menu(void);
status input_yes_no(void);
status input_id(data *const p_data_temp);
status input_name(data *const p_data_temp);
status input_contacts(data *const p_data_temp);
status input_class_name(data *const p_data_temp);
status input_add(const data *const p_DATA, node *const p_node_list);
void input_delete(node *p_node, node *const p_node_list);
int input_count(const node *const p_NODE_LIST);
static void input_eatline(void);