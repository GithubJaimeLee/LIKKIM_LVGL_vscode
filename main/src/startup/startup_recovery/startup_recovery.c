﻿/*********************
 *      INCLUDES
 *********************/

#include "startup_recovery.h"
#include "gui_comm.h"


static gui_comm_imgbtn_desc_t startup_imgbtn_num_table[] =
{
    {"1.word", 20, 96},
    {"2.word", 130, 96},
    {"3.word", 20, 126},
    {"4.word", 130, 126},
    {"5.word", 20, 156},
    {"6.word", 130, 156},
    {"7.word", 20, 186},
    {"8.word", 130, 186},
    {"9.word", 20, 216},
    {"10.word", 130, 216},
    {"11.word", 20, 246},
    {"12.word", 130, 246},
};

extern void startup_done_start(void);
extern void startup_ready_check_start(void);

static startup_recovery_t* p_startup_recovery = NULL;

static void title_cb(lv_event_t* e)
{
    lv_event_code_t event = lv_event_get_code(e);

    if (LV_EVENT_SHORT_CLICKED == event)
    {
        startup_recovery_stop();
        startup_ready_check_start();
    }
}

static void startup_recovery_word_btn_handler(lv_event_t* e)
{
    lv_event_code_t event = lv_event_get_code(e);

    if (LV_EVENT_SHORT_CLICKED == event)
    {
        printf("%s\n", (char *)e->user_data);
    }
}
static void startup_recovery_continue_btn_handler(lv_event_t* e)
{
    lv_event_code_t event = lv_event_get_code(e);

    if (LV_EVENT_SHORT_CLICKED == event)
    {
        //gui_app_run_subpage("startup", "done", NULL);
        startup_recovery_stop();
        startup_done_start();
    }
}
static void startup_recovery_bg_cont(lv_obj_t* parent)
{
    gui_comm_draw_title(parent, "Recovery Phrase", title_cb);

    lv_obj_t* label_describe = lv_label_create(parent);
    lv_obj_set_style_text_color(label_describe, lv_color_hex(0xffffff), 0);
    lv_obj_set_style_text_font(label_describe, &lv_font_montserrat_12, 0);
    lv_label_set_text(label_describe, "Write down the following 12 Words in orders.");
    lv_label_set_long_mode(label_describe, LV_LABEL_LONG_WRAP);
    lv_obj_set_width(label_describe, 200);
    lv_obj_set_pos(label_describe, 20, 60);

    for (uint8_t i = 0; i < sizeof(startup_imgbtn_num_table) / sizeof(gui_comm_imgbtn_desc_t); i++)
    {
        lv_obj_t* img_btn = lv_imagebutton_create(parent);
        lv_imagebutton_set_src(img_btn, LV_IMAGEBUTTON_STATE_RELEASED, &img_left_released_888888_14x26, &img_mid_released_888888_4x26, &img_right_released_888888_14x26);
        lv_imagebutton_set_src(img_btn, LV_IMAGEBUTTON_STATE_PRESSED, &img_left_pressed_bbbbbb_14x26, &img_mid_pressed_bbbbbb_4x26, &img_right_pressed_bbbbbb_14x26);
        lv_obj_set_width(img_btn, 90);
        lv_obj_set_pos(img_btn, startup_imgbtn_num_table[i].x, startup_imgbtn_num_table[i].y);
        lv_obj_add_event_cb(img_btn, startup_recovery_word_btn_handler, LV_EVENT_SHORT_CLICKED, (void *)startup_imgbtn_num_table[i].str);
        lv_obj_add_flag(img_btn, LV_OBJ_FLAG_CLICKABLE);

        lv_obj_t* label = lv_label_create(img_btn);
		lv_obj_set_style_text_color(label, lv_color_hex(0xffffff), 0);
		lv_obj_set_style_text_font(label, &lv_font_montserrat_12, 0);
        lv_label_set_text(label, startup_imgbtn_num_table[i].str);
        lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
    }

    lv_obj_t* img_btn_continue = lv_imagebutton_create(parent);
    lv_imagebutton_set_src(img_btn_continue, LV_IMAGEBUTTON_STATE_RELEASED, &img_left_released_6c6cf4_14x26, &img_mid_released_6c6cf4_4x26, &img_right_released_6c6cf4_14x26);
    lv_imagebutton_set_src(img_btn_continue, LV_IMAGEBUTTON_STATE_PRESSED, &img_left_pressed_9797ff_14x26, &img_mid_pressed_9797ff_4x26, &img_right_pressed_9797ff_14x26);
    lv_obj_set_width(img_btn_continue, 200);
    lv_obj_set_pos(img_btn_continue, 20, 278);
    lv_obj_add_event_cb(img_btn_continue, startup_recovery_continue_btn_handler, LV_EVENT_SHORT_CLICKED, NULL);
    lv_obj_add_flag(img_btn_continue, LV_OBJ_FLAG_CLICKABLE);

    lv_obj_t* label_continue = lv_label_create(img_btn_continue);
    lv_obj_set_style_text_color(label_continue, lv_color_hex(0xffffff), 0);
    lv_obj_set_style_text_font(label_continue, &lv_font_montserrat_12, 0);
    lv_label_set_text(label_continue, "Contiune");
    lv_obj_align(label_continue, LV_ALIGN_CENTER, 0, 0);
    lv_obj_add_flag(label_continue, LV_OBJ_FLAG_EVENT_BUBBLE);
}


void startup_recovery_start(void)
{
    p_startup_recovery = (startup_recovery_t*)lv_malloc(sizeof(startup_recovery_t));
    LV_ASSERT(p_startup_recovery);
    lv_memset(p_startup_recovery, 0, sizeof(startup_recovery_t));

    p_startup_recovery->bg_cont = gui_comm_draw_bg();
    startup_recovery_bg_cont(p_startup_recovery->bg_cont);
}

void startup_recovery_stop(void)
{
    lv_obj_del(p_startup_recovery->bg_cont);
    lv_free(p_startup_recovery);
    p_startup_recovery = NULL;
}


