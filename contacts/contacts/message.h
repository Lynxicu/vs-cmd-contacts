#pragma once

#include "common.h"
#include "list.h"

void msg_memory_error(void);
void msg_file_error(void);
void msg_cancel(void);
void msg_welcome(void);
void msg_class_info(const node *const p_NODE);
void msg_menu(void);
void msg_menu_error(void);
void msg_exit_confirm(void);
void msg_exit_success(void);
void msg_add(void);
void msg_add_error(void);
void msg_add_success(const int n_count, const data *const p_DATA);
void msg_delete(void);
void msg_delete_confirm(const data *const p_DATA);
void msg_delete_success(void);
void msg_update(void);
void msg_update_original(const data *const p_DATA);
void msg_update_confirm(const data *const p_DATA);
void msg_update_error(void);
void msg_update_success(void);
void msg_search(void);
void msg_search_all(void);
void msg_search_show_header(void);
void msg_search_show(const data *const p_DATA);
void msg_search_count(const int *const p_n_COUNT);
void msg_search_back(void);
void msg_search_error(void);
void msg_input_id(void);
void msg_repeat(void);
void msg_input_id_error(void);
void msg_input_name(void);
void msg_input_name_error(void);
void msg_input_contacts(void);
void msg_input_contacts_error(void);
void msg_output_header(void);
void msg_output(const data *const p_DATA);
void msg_output_count(const node *const p_NODE_LIST);
void msg_update_class(void);
void msg_input_class_first(void);
void msg_input_class(void);
void msg_input_class_confirm(const data *const p_DATA);
void msg_class_empty(void);
void msg_input_class_error(void);
void msg_input_class_success(void);
void msg_help(void);
static void set_color_default(void);
static void set_color_light(void);
static void set_color_blue_tips(void);
static void set_color_green_tips(void);
static void set_color_yellow_alert(void);
static void set_color_red_alert(void);