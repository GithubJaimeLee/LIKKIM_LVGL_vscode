﻿/*********************
 * settings_reset_Erase_This_Device.c
 *      INCLUDES
 *********************/

#include "settings_reset_Erase_This_Device.h"
#include "gui_comm.h"

extern void settings_security_start(void);


static settings_reset_Erase_t* p_settings_reset = NULL;

static void confirm_cb(lv_event_t* e)
{
    lv_event_code_t event = lv_event_get_code(e);

    if (LV_EVENT_SHORT_CLICKED == event)
    {
    	printf("%s\n", __func__);
    }
}

static void cancle_cb(lv_event_t* e)
{
    lv_event_code_t event = lv_event_get_code(e);

    if (LV_EVENT_SHORT_CLICKED == event)
    {
        settings_reset_stop();
        settings_security_start();
    }
}

static void settings_reset_bg_cont(lv_obj_t* parent)
{
    gui_comm_draw_title(parent, "Reset Device", NULL);

    lv_obj_t* describe_label = lv_label_create(parent);
    lv_obj_set_style_text_color(describe_label, lv_color_hex(0xffffff), 0);
    lv_obj_set_style_text_font(describe_label, &lv_font_montserrat_12, 0);
    lv_label_set_long_mode(describe_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_width(describe_label, 200);
    lv_obj_set_pos(describe_label, 20, 60);
    lv_label_set_text(describe_label, "This action will erase all data and cannot be undone. Are you sure you want to proceed?");
    lv_obj_add_flag(describe_label, LV_OBJ_FLAG_SCROLL_CHAIN | LV_OBJ_FLAG_EVENT_BUBBLE);

    lv_obj_t* img_btn_confirm = lv_imagebutton_create(parent);
    lv_imagebutton_set_src(img_btn_confirm, LV_IMAGEBUTTON_STATE_RELEASED, &img_left_released_6c6cf4_14x26, &img_mid_released_6c6cf4_4x26, &img_right_released_6c6cf4_14x26);
    lv_imagebutton_set_src(img_btn_confirm, LV_IMAGEBUTTON_STATE_PRESSED, &img_left_released_6c6cf4_14x26, &img_mid_released_6c6cf4_4x26, &img_right_released_6c6cf4_14x26);
    lv_obj_set_width(img_btn_confirm, 200);
    lv_obj_set_pos(img_btn_confirm, 20, 246);
    lv_obj_add_event_cb(img_btn_confirm, confirm_cb, LV_EVENT_SHORT_CLICKED, NULL);
    lv_obj_add_flag(img_btn_confirm, LV_OBJ_FLAG_CLICKABLE);

    lv_obj_t* label_confirm = lv_label_create(img_btn_confirm);
    lv_obj_set_style_text_color(label_confirm, lv_color_hex(0xffffff), 0);
    lv_obj_set_style_text_font(label_confirm, &lv_font_montserrat_12, 0);
    lv_obj_set_style_text_align(label_confirm, LV_TEXT_ALIGN_CENTER, 0);
    lv_label_set_long_mode(label_confirm, LV_LABEL_LONG_DOT);
    lv_obj_set_width(label_confirm, 200);
    lv_label_set_text(label_confirm, "Confirm");
    lv_obj_center(label_confirm);
    lv_obj_add_flag(label_confirm, LV_OBJ_FLAG_SCROLL_CHAIN | LV_OBJ_FLAG_EVENT_BUBBLE);

    lv_obj_t* img_btn_cancle = lv_imagebutton_create(parent);
    lv_imagebutton_set_src(img_btn_cancle, LV_IMAGEBUTTON_STATE_RELEASED, &img_left_released_888888_14x26, &img_mid_released_888888_4x26, &img_right_released_888888_14x26);
    lv_imagebutton_set_src(img_btn_cancle, LV_IMAGEBUTTON_STATE_PRESSED, &img_left_pressed_bbbbbb_14x26, &img_mid_pressed_bbbbbb_4x26, &img_right_pressed_bbbbbb_14x26);
    lv_obj_set_width(img_btn_cancle, 200);
    lv_obj_set_pos(img_btn_cancle, 20, 278);
    lv_obj_add_event_cb(img_btn_cancle, cancle_cb, LV_EVENT_SHORT_CLICKED, NULL);
    lv_obj_add_flag(img_btn_cancle, LV_OBJ_FLAG_CLICKABLE);

    lv_obj_t* label_cancle = lv_label_create(img_btn_cancle);
    lv_obj_set_style_text_color(label_cancle, lv_color_hex(0xffffff), 0);
    lv_obj_set_style_text_font(label_cancle, &lv_font_montserrat_12, 0);
    lv_obj_set_style_text_align(label_cancle, LV_TEXT_ALIGN_CENTER, 0);
    lv_label_set_long_mode(label_cancle, LV_LABEL_LONG_DOT);
    lv_obj_set_width(label_cancle, 200);
    lv_label_set_text(label_cancle, "Cancle");
    lv_obj_center(label_cancle);
    lv_obj_add_flag(label_cancle, LV_OBJ_FLAG_SCROLL_CHAIN | LV_OBJ_FLAG_EVENT_BUBBLE);
}


void settings_reset_start(void)
{
    p_settings_reset = (settings_reset_Erase_t*)lv_malloc(sizeof(settings_reset_Erase_t));
    LV_ASSERT(p_settings_reset);
    lv_memset(p_settings_reset, 0, sizeof(settings_reset_Erase_t));

    p_settings_reset->bg_cont = gui_comm_draw_bg();
    settings_reset_bg_cont(p_settings_reset->bg_cont);
}

 void settings_reset_stop(void)
{
    lv_obj_del(p_settings_reset->bg_cont);
    lv_free(p_settings_reset);
    p_settings_reset = NULL;
}
