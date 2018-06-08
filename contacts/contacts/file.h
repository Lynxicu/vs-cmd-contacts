#pragma once

#include "common.h"
#include "list.h"

status file_new(void);
status file_load(data *const p_data_temp, node *const p_node_list);
status file_save(node *p_node_list);